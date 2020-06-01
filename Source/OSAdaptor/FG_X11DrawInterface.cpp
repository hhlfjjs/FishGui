/*--------------------------------------------------------------------------

	FG_X11DrawInterface.cpp - X11�Ļ�ͼ�ӿ����ʵ���ļ�

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
 *  \brief X11�Ļ�ͼ�ӿ����ʵ���ļ�
 */

/*! @} */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/xpm.h>
#include "FG_X11DrawInterface.h"

//##ModelId=3F6EB0010086
FG_X11DrawInterface::FG_X11DrawInterface(Window win, Display * display, int screen)
: m_Win(win), m_Display(display)
{
    m_Depth     = DefaultDepth(display, screen);
    m_CMap      = DefaultColormap(display, screen);
    // m_Visual    = DefaultVisual(display, screen);
    // ʹ��ȱʡ��ɫ��
    XSetWindowColormap(display, win, m_CMap);
    
    // �õ���Ҫ����ɫ
    XColor e, s;
    COLOR_BLACK     = BlackPixel(display, screen);
    XLookupColor(display, m_CMap, "#c0c0c0", & e, & s);
    XAllocColor(display, m_CMap, &s);
    COLOR_GRAY      = s.pixel;
    COLOR_WHITE     = WhitePixel(display, screen);
    XLookupColor(display, m_CMap, "#808080", & e, & s);
    XAllocColor(display, m_CMap, &s);
    COLOR_DARKGRAY  = s.pixel;
    XLookupColor(display, m_CMap, "#0000bf", & e, & s);
    XAllocColor(display, m_CMap, &s);
    COLOR_BLUE      = s.pixel;
    XLookupColor(display, m_CMap, "#0000ff", & e, & s);
    XAllocColor(display, m_CMap, &s);
    COLOR_BLUE1     = s.pixel;
    XLookupColor(display, m_CMap, "#ff0000", & e, & s);
    XAllocColor(display, m_CMap, &s);
    COLOR_RED       = s.pixel;

	m_GC = XCreateGC(display, win, 0, NULL);
    m_CopyGC = XCreateGC(display, win, 0, NULL);

    // ����������
    char *fontset_name, **missing_charset_list, *def_string; 
    int missing_charset_count; 
    fontset_name = "-*-*-*-*-*-*-*-*-*-*-*-*-iso8859-1, -*-*-*-*-*-*-*-*-*-*-*-*-gb2312.1980-0";
    m_FontSet = XCreateFontSet(display, fontset_name, & missing_charset_list,
                                & missing_charset_count, & def_string); 	

    // ����������λͼ
    m_Buffer = XCreatePixmap(display, win, SCREEN_WIDTH, SCREEN_HEIGHT, m_Depth);
}

//##ModelId=40925CB00334
FG_X11DrawInterface::~FG_X11DrawInterface()
{
    XFreePixmap(m_Display, m_Buffer);
    XFreeFontSet(m_Display, m_FontSet);
	XFreeGC(m_Display, m_GC);
	XFreeGC(m_Display, m_CopyGC);
}

//##ModelId=3F6EB0010090
void FG_X11DrawInterface::BeginDraw(const FG_Rect & rect)
{
    if (! m_iDrawCount)
        m_Invalid = rect;
    else
        m_Invalid |= rect;
    m_iDrawCount ++;
}

//##ModelId=3F6EB0010092
void FG_X11DrawInterface::EndDraw()
{
    m_iDrawCount --;
    if (! m_iDrawCount)
    {
        // �ѻ���������ˢ�µ���Ļ��
    	XSetFillStyle(m_Display, m_CopyGC, FillTiled);
	    XSetTile(m_Display, m_CopyGC, m_Buffer);
    	XFillRectangle(m_Display, m_Win, m_CopyGC, m_Invalid.wLeft, m_Invalid.wTop, m_Invalid.Width(), m_Invalid.Height());
    }
}

//##ModelId=3F6EB001009A
void FG_X11DrawInterface::FillRect(const FG_Rect & rect, const COLORVAL ForeColor, const COLORVAL background)
{
	XSetForeground(m_Display, m_GC, background);
	XFillRectangle(m_Display, m_Buffer, m_GC, rect.wLeft, rect.wTop, rect.Width(), rect.Height());
	if (ForeColor != background)
	{
    	XSetForeground(m_Display, m_GC, ForeColor);
	    XDrawRectangle(m_Display, m_Buffer, m_GC, rect.wLeft, rect.wTop, rect.Width(), rect.Height());
	}
}

//##ModelId=3F6EB00100A4
void FG_X11DrawInterface::Line(const short x1, const short y1, const short x2, const short y2, const COLORVAL color)
{
	XSetForeground(m_Display, m_GC, color);
	XDrawLine(m_Display, m_Buffer, m_GC, x1, y1, x2, y2);
}

//##ModelId=3F6EB00100B1
void FG_X11DrawInterface::DrawText(const char * Text, const short x, const short y, const COLORVAL color)
{
	XSetForeground(m_Display, m_GC, color);
	short my = y + GetTextHeight(Text);
    XmbDrawString(m_Display, m_Buffer, m_FontSet, m_GC, x, my, Text, strlen(Text));
}

//##ModelId=3F6EB00100C3
WORD FG_X11DrawInterface::GetTextWidth(const char * Text)
{
    XRectangle ink, logical;
    XmbTextExtents(m_FontSet, Text, strlen(Text), & ink, & logical);

    return logical.width;
}

//##ModelId=3F6EB00100CC
WORD FG_X11DrawInterface::GetTextHeight(const char * Text)
{
    XRectangle ink, logical;
    XmbTextExtents(m_FontSet, Text, strlen(Text), & ink, & logical);

    return logical.height;
}

//##ModelId=3F6EB00100CE
void FG_X11DrawInterface::DrawBitmap(const char * pBmpName, const short x1, const short y1)
{
	int status;
	XpmAttributes attributes;

	attributes.valuemask = XpmColormap | XpmCloseness;
	attributes.colormap = m_CMap;
	attributes.closeness = 65535;
	
  Pixmap pix, mask;
    // ��ȡxpm�ļ�
    if (XpmReadFileToPixmap(m_Display, m_Buffer, (char *)pBmpName, & pix, & mask, & attributes) == XpmSuccess)
    {
    	int width = attributes.width;
	    int height = attributes.height;
	    GC gc = XCreateGC(m_Display, m_Buffer, 0, NULL);
	    XSetFillStyle(m_Display, gc, FillTiled);
	    XSetTile(m_Display, gc, pix);
	    
	    XGCValues xgcv;
	    xgcv.ts_y_origin = y1;
	    xgcv.ts_x_origin = x1;
	    xgcv.clip_y_origin = y1;
	    xgcv.clip_x_origin = x1;
	    XChangeGC(m_Display, gc, GCClipXOrigin | GCClipYOrigin | GCTileStipXOrigin | GCTileStipYOrigin, & xgcv);
	    XFillRectangle(m_Display, m_Buffer, gc, x1, y1, width, height);
	    
	    XFreePixmap(m_Display, pix);
	    XFreeGC(m_Display, gc);
    }
}

//##ModelId=3F6EB00100D8
void FG_X11DrawInterface::DrawPolyLine(const short n, const FG_Point * vert, const COLORVAL color)
{
	if (n > 1)
	{
    	XSetForeground(m_Display, m_GC, color);
        for (short i = 0; i < n - 1; i ++)
    	    XDrawLine(m_Display, m_Buffer, m_GC, vert[i].x, vert[i].y, vert[i + 1].x, vert[i + 1].y);
    }
}

//##ModelId=3F6EB00100E3
void FG_X11DrawInterface::DrawDotRect(const FG_Rect & rect, const COLORVAL color)
{
    XSetForeground(m_Display, m_GC, color);

    XGCValues xgcv;
    xgcv.line_style = LineOnOffDash;
    XChangeGC(m_Display, m_GC, GCLineStyle, & xgcv);

    XDrawRectangle(m_Display, m_Buffer, m_GC, rect.wLeft, rect.wTop, rect.Width(), rect.Height());

    xgcv.line_style = LineSolid;
    XChangeGC(m_Display, m_GC, GCLineStyle, & xgcv);
}

