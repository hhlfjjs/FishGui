/*--------------------------------------------------------------------------

	FG_Win32DrawInterface.cpp - Win32的绘图接口类的实现文件

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
 *  \brief Win32的绘图接口类的实现文件
 */

/*! @} */

#include "stdio.h"
#include "windows.h"
#include "FG_Win32DrawInterface.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
//##ModelId=3F71AB2E0279
FG_Win32DrawInterface::~FG_Win32DrawInterface()
{
    // 删除绘图资源
    DeleteDC(m_hMemDC);
    DeleteObject(m_hBitmap);
    DeleteObject(m_hFont);
}
    
//##ModelId=3F4EDED00326
void FG_Win32DrawInterface::BeginDraw(const FG_Rect & rect)
{
    if (! m_iDrawCount)
    {
        if (! m_hMemDC)
        {
            // 创建绘图缓冲区
            m_hMemDC = CreateCompatibleDC(m_hDC);
            m_hBitmap = CreateCompatibleBitmap(m_hDC, SCREEN_WIDTH, SCREEN_HEIGHT);
            SelectObject(m_hMemDC, m_hBitmap);
    
            m_hFont = CreateFont(15, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 
                                 OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, 
                                 DEFAULT_QUALITY, DEFAULT_PITCH, "宋体");
            SelectObject(m_hMemDC, m_hFont);
        }

        // 初始无效区
        m_Invalid = rect;
    }
    else
    {
        // 组合无效区
        m_Invalid |= rect;
    }
    m_iDrawCount ++;
}

//##ModelId=3F4EDED003A8
void FG_Win32DrawInterface::EndDraw()
{
    m_iDrawCount --;
    if (! m_iDrawCount)
    {
        // 把缓冲区内容刷新到屏幕上
        BitBlt(m_hDC, m_Invalid.wLeft, m_Invalid.wTop, m_Invalid.Width(), m_Invalid.Height(), m_hMemDC, 
            m_Invalid.wLeft, m_Invalid.wTop, SRCCOPY);
    }
}

//##ModelId=3F4EDED003E4
void FG_Win32DrawInterface::FillRect(const FG_Rect & rect, const COLORVAL ForeColor, const COLORVAL background)
{
    if (m_hMemDC)
    {
        // 创建绘图所用资源
        HPEN hPen = CreatePen(PS_SOLID, 1, ForeColor);
        HBRUSH hBrush = CreateSolidBrush(background);

        HPEN hPenOld = (HPEN)SelectObject(m_hMemDC, hPen);
        HBRUSH hBrushOld = (HBRUSH)SelectObject(m_hMemDC, hBrush);

        Rectangle(m_hMemDC, rect.wLeft, rect.wTop, rect.wRight + 1, rect.wBottom + 1);

        // 删除绘图资源
        SelectObject(m_hMemDC, hPenOld);
        DeleteObject(hPen);
        SelectObject(m_hMemDC, hBrushOld);
        DeleteObject(hBrush);
    }
}

//##ModelId=3F4EDED10133
void FG_Win32DrawInterface::Line(const short x1, const short y1, const short x2, const short y2, const COLORVAL color)
{
    if (m_hMemDC)
    {
        // 创建绘图所用资源
        HPEN hPen = CreatePen(PS_SOLID, 1, color);

        HPEN hPenOld = (HPEN)SelectObject(m_hMemDC, hPen);

        MoveToEx(m_hMemDC, x1, y1, NULL);
        LineTo(m_hMemDC, x2, y2);
        // Win32的画线函数不画最后一点，和FishGUI的定义不同
		// 这里需要加画最后一点
        SetPixel(m_hMemDC, x2, y2, color);

        // 删除绘图资源
        SelectObject(m_hMemDC, hPenOld);
        DeleteObject(hPen);
    }
}

//##ModelId=3F4EDED1031E
void FG_Win32DrawInterface::DrawText(const char * Text, const short x, const short y, const COLORVAL color)
{
    if (m_hMemDC)
    {
        SetTextColor(m_hMemDC, color);
        SetBkMode(m_hMemDC, TRANSPARENT);
        TextOut(m_hMemDC, x, y, Text, strlen(Text));
    }
}

//##ModelId=3F4EDED200DA
WORD FG_Win32DrawInterface::GetTextWidth(const char * Text)
{
    if (m_hMemDC)
    {
        SIZE size;
        GetTextExtentPoint(m_hMemDC, Text, strlen(Text), & size);
        return (WORD)size.cx;
    }
    else
        return 0;
}

//##ModelId=3F4EDED20184
WORD FG_Win32DrawInterface::GetTextHeight(const char * Text)
{
    if (m_hMemDC)
    {
        SIZE size;
        GetTextExtentPoint(m_hMemDC, Text, strlen(Text), & size);
        return (WORD)size.cy;
    }
    else
        return 0;
}

//##ModelId=3F4EDED20239
void FG_Win32DrawInterface::DrawBitmap(const char * pBmpName, const short x1, const short y1)
{
    if (m_hMemDC)
    {
        HBITMAP hBitmap1 = (HBITMAP)LoadImage(NULL, pBmpName, IMAGE_BITMAP, 0, 0,
                                    LR_DEFAULTSIZE | LR_LOADFROMFILE);
        if (hBitmap1)
        {
            BITMAP info;
            GetObject(hBitmap1, sizeof(BITMAP), & info);

            HDC hMemDC1 = CreateCompatibleDC(m_hDC);
            SelectObject(hMemDC1, hBitmap1);
            BitBlt(m_hMemDC, x1, y1, x1 + info.bmWidth - 1, y1 + info.bmHeight - 1, hMemDC1, 0, 0, SRCCOPY);
            DeleteDC(hMemDC1);
            DeleteObject(hBitmap1);
        }
    }
}

//##ModelId=3F6193B201F2
void FG_Win32DrawInterface::DrawPolyLine(const short n, const FG_Point * vert, const COLORVAL color)
{
    if (m_hMemDC)
    {
        // 创建绘图所用资源
        HPEN hPen = CreatePen(PS_SOLID, 1, color);

        HPEN hPenOld = (HPEN)SelectObject(m_hMemDC, hPen);

        POINT * lppt = new POINT[n];
        for (short i = 0; i < n; i ++)
        {
            lppt[i].x = vert[i].x;
            lppt[i].y = vert[i].y;
        }

        Polyline(m_hMemDC, lppt, n);
        SetPixel(m_hMemDC, lppt[n - 1].x, lppt[n - 1].y, color);

        delete [] lppt;

        // 删除绘图资源
        SelectObject(m_hMemDC, hPenOld);
        DeleteObject(hPen);
    }
}

//##ModelId=3F6EAC820075
void FG_Win32DrawInterface::DrawDotRect(const FG_Rect & rect, const COLORVAL color)
{
    if (m_hMemDC)
    {
        // 创建绘图所用资源
        HPEN hPen = CreatePen(PS_DOT, 1, color);

        HPEN hPenOld = (HPEN)SelectObject(m_hMemDC, hPen);
        HBRUSH hBrushOld = (HBRUSH)SelectObject(m_hMemDC, GetStockObject(NULL_BRUSH));

        Rectangle(m_hMemDC, rect.wLeft, rect.wTop, rect.wRight + 1, rect.wBottom + 1);

        // 删除绘图资源
        SelectObject(m_hMemDC, hPenOld);
        DeleteObject(hPen);
        SelectObject(m_hMemDC, hBrushOld);
    }
}

