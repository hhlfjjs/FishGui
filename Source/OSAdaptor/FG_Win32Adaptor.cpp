/*--------------------------------------------------------------------------

	FG_Win32Adaptor.cpp - Win32的适配器类的实现文件

	本程序是FishGUI软件的一部分

	版权所有 (C) 2003,2004 王咏武
	http://www.contextfree.net/wangyw/

----------------------------------------------------------------------------

	作者对 FishGUI 软件及其所有源代码授权如下：

	允许任何个人、组织、机构、企业无偿获得、修改、使用、重新发布 FishGUI 软
	件及其源代码，或按照有偿或者无偿的方式发行基于 FishGUI 源代码的全部或部
	分内容开发的软件产品，——但行使以上权利时，须遵守以下约定：

	1、重新发布 FishGUI 软件及其源代码时，不得隐去软件及其源代码中原有的版
	   权信息和开发者标识。

	2、发行基于 FishGUI 源代码的全部或部分内容开发的软件产品时，必须在产品
	   的显著位置标明以下字样：

	   【本产品的一部分功能是基于王咏武在 FishGUI 软件中的工作完成的】

	3、在正式出版物中引用 FishGUI 的文档、源代码或注释内容的，应注明软件的
	   原作者为王咏武。

--------------------------------------------------------------------------*/
/*! \addtogroup OSAdaptor
 *  @{ 
 */

/*! \file
 *  \brief Win32的适配器类的实现文件
 */

/*! @} */

#include <stdio.h>
#include "windows.h"
#include "../Utility/FG_Utility.h"
#include "FG_Win32Adaptor.h"
#include "FG_WIn32DrawInterface.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
//##ModelId=3F4E099D01F1
bool FG_Win32Adaptor::InitInstance()
{
    if (! m_pDraw)
        m_pDraw = new FG_Win32DrawInterface();

    char szAppName[] = "FishGUI Win32 Simulator";
    WNDCLASS wndClass;

    if (! m_hPrevInst)
    {
        wndClass.style = CS_HREDRAW|CS_VREDRAW;
        wndClass.lpfnWndProc = FG_Win32Adaptor::WndProc;
        wndClass.cbClsExtra = 0;
        wndClass.cbWndExtra = 0;
        wndClass.hInstance = m_hInst;
        wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
        wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
        wndClass.lpszMenuName = NULL;
        wndClass.lpszClassName = szAppName;
        RegisterClass(&wndClass);
    }

    HWND hWnd;
    hWnd = CreateWindow(szAppName, szAppName,
            WS_VISIBLE | WS_MINIMIZEBOX | WS_SYSMENU,
            0, 0, SCREEN_WIDTH + 10, SCREEN_HEIGHT + 30, 
            NULL, NULL, m_hInst, NULL);

    FG_Message Msg(FG_MSG_STARTUP);
    SendMsg(& Msg);

    // create timer tick for stimulating EMGUI
    SetTimer(hWnd, 1, 50, NULL);

    ShowWindow(hWnd, m_nCmdShow);
    UpdateWindow(hWnd);
    
    return true;
}

//##ModelId=3F4E09F802BB
bool FG_Win32Adaptor::ExitInstance()
{
    FG_Message Msg(FG_MSG_HALT);
    SendMsg(& Msg);

    if (m_pDraw)
        delete m_pDraw;
    if (m_pAdaptor)
        delete m_pAdaptor;

    return true;
}

//##ModelId=3F4E09F8031F
bool FG_Win32Adaptor::Execute()
{
    MSG msg;
    while (GetMessage(& msg, 0, 0, 0))
    { 
        TranslateMessage(& msg); 
        DispatchMessage(& msg); 
    }
    return true;
}

//##ModelId=40925CB0009F
void FG_Win32Adaptor::SetBmpPath(char * pPath, int len)
{
    memcpy(m_BmpPath, pPath, len);
    m_BmpPath[len] = 0;
    strcat(m_BmpPath, "\\Win32_Bmp");
}

//##ModelId=40925CB000E5
void FG_Win32Adaptor::DrawBitmap(const char * pBmpName, const short x1, const short y1)
{
    char name[MAX_PATH + 1];
    sprintf(name, "%s/%s.bmp", m_BmpPath, pBmpName);
    m_pDraw->DrawBitmap(name, x1, y1);
}

//##ModelId=3F6EAFFE0335
long FAR WINAPI FG_Win32Adaptor::WndProc(HWND hWnd, UINT uMessage, UINT wParam, LONG lParam)
{

    switch (uMessage)
    {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hDC = BeginPaint(hWnd, &ps);
            
            ((FG_Win32DrawInterface *)m_pDraw)->SetHDC(hDC);
            FG_Message Msg(FG_MSG_DRAW);
            m_pAdaptor->SendMsg(& Msg);

            EndPaint(hWnd, &ps);
        }
        break;
      case WM_KEYDOWN:
        {
            HDC hDC = GetDC(hWnd);
            ((FG_Win32DrawInterface *)m_pDraw)->SetHDC(hDC);

            FG_Message Msg(FG_MSG_KEY, FKS_DOWN);
            if ((wParam >= '0' && wParam <= '9')
                || (wParam >= 'A' && wParam <= 'Z')
                || (wParam >= 'a' && wParam <= 'z'))
                Msg.lData = wParam;
            else if (wParam == VK_RETURN)
                Msg.lData = FVK_ENTER;
            else if (wParam == VK_LEFT)
                Msg.lData = FVK_LEFT;
            else if (wParam == VK_RIGHT)
                Msg.lData = FVK_RIGHT;
            else if (wParam == VK_DELETE)
                Msg.lData = FVK_DELETE;
            else if (wParam == VK_TAB)
                Msg.lData = FVK_TAB;
            m_pAdaptor->SendMsg(& Msg);
            
            ReleaseDC(hWnd, hDC);
        }
        break;
    case WM_KEYUP:
        {
            HDC hDC = GetDC(hWnd);
            ((FG_Win32DrawInterface *)m_pDraw)->SetHDC(hDC);

            FG_Message Msg(FG_MSG_KEY, FKS_UP);
            if ((wParam >= '0' && wParam <= '9')
                || (wParam >= 'A' && wParam <= 'Z')
                || (wParam >= 'a' && wParam <= 'z'))
                Msg.lData = wParam;
            else if (wParam == VK_RETURN)
                Msg.lData = FVK_ENTER;
            else if (wParam == VK_LEFT)
                Msg.lData = FVK_LEFT;
            else if (wParam == VK_RIGHT)
                Msg.lData = FVK_RIGHT;
            else if (wParam == VK_DELETE)
                Msg.lData = FVK_DELETE;
            else if (wParam == VK_TAB)
                Msg.lData = FVK_TAB;
            m_pAdaptor->SendMsg(& Msg);
            
            ReleaseDC(hWnd, hDC);
        }
        break;
    case WM_LBUTTONDOWN:
        {
            HDC hDC = GetDC(hWnd);
            ((FG_Win32DrawInterface *)m_pDraw)->SetHDC(hDC);

            FG_Message Msg(FG_MSG_MOUSE, FMS_LBUTTONDOWN);
            Msg.Point.x = (WORD)lParam;
            Msg.Point.y = (WORD)((lParam & 0xffff0000) >> 16);
            m_pAdaptor->SendMsg(& Msg);
            
            ReleaseDC(hWnd, hDC);
        }
        break;
    case WM_LBUTTONUP:
        {
            HDC hDC = GetDC(hWnd);
            ((FG_Win32DrawInterface *)m_pDraw)->SetHDC(hDC);

            FG_Message Msg(FG_MSG_MOUSE, FMS_LBUTTONUP);
            Msg.Point.x = (WORD)lParam;
            Msg.Point.y = (WORD)((lParam & 0xffff0000) >> 16);
            m_pAdaptor->SendMsg(& Msg);
            
            ReleaseDC(hWnd, hDC);
        }
        break;
    case WM_TIMER:
        {
            HDC hDC = GetDC(hWnd);
            ((FG_Win32DrawInterface *)m_pDraw)->SetHDC(hDC);

            FG_Message Msg(FG_MSG_TIMER);
            m_pAdaptor->SendMsg(& Msg);
            
            ReleaseDC(hWnd, hDC);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, uMessage, wParam, lParam);
    }
    return 0L;
}
