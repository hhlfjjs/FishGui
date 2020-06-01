/*--------------------------------------------------------------------------

	FG_Win32Adaptor.cpp - Win32�����������ʵ���ļ�

	��������FishGUI�����һ����

	��Ȩ���� (C) 2003,2004 ��ӽ��
	http://www.contextfree.net/wangyw/

----------------------------------------------------------------------------

	���߶� FishGUI �����������Դ������Ȩ���£�

	�����κθ��ˡ���֯����������ҵ�޳���á��޸ġ�ʹ�á����·��� FishGUI ��
	������Դ���룬�����г������޳��ķ�ʽ���л��� FishGUI Դ�����ȫ����
	�����ݿ����������Ʒ����������ʹ����Ȩ��ʱ������������Լ����

	1�����·��� FishGUI �������Դ����ʱ��������ȥ�������Դ������ԭ�еİ�
	   Ȩ��Ϣ�Ϳ����߱�ʶ��

	2�����л��� FishGUI Դ�����ȫ���򲿷����ݿ����������Ʒʱ�������ڲ�Ʒ
	   ������λ�ñ�������������

	   ������Ʒ��һ���ֹ����ǻ�����ӽ���� FishGUI ����еĹ�����ɵġ�

	3������ʽ������������ FishGUI ���ĵ���Դ�����ע�����ݵģ�Ӧע�������
	   ԭ����Ϊ��ӽ�䡣

--------------------------------------------------------------------------*/
/*! \addtogroup OSAdaptor
 *  @{ 
 */

/*! \file
 *  \brief Win32�����������ʵ���ļ�
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
