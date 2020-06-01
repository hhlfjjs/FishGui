/*--------------------------------------------------------------------------

	FG_X11DrawInterface.h - X11的绘图接口类的头文件

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
 *  \brief X11的绘图接口类的头文件
 */

#ifndef FG_X11DRAWINTERFACE_H_HEADER_INCLUDED_C0B152A0
#define FG_X11DRAWINTERFACE_H_HEADER_INCLUDED_C0B152A0

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../Utility/FG_Utility.h"
#include "FG_OSDrawInterface.h"

//##ModelId=3F6EAFFE00BE
/*! \brief X11的绘图接口类
 *  
 *  该类封装X11的绘图过程
 */
class FG_X11DrawInterface : public FG_OSDrawInterface
{
public:
    //##ModelId=3F6EB0010086
    /*! \brief X11的绘图接口类的构造函数 */
    FG_X11DrawInterface(Window win, Display * display, int screen);

    //##ModelId=40925CB00334
    /*! \brief X11的绘图接口类的析构函数 */
    ~FG_X11DrawInterface();

    //##ModelId=3F6EB0010090
    void BeginDraw(const FG_Rect & rect);

    //##ModelId=3F6EB0010092
    void EndDraw();
    
    //##ModelId=3F6EB001009A
    void FillRect(const FG_Rect & rect, const COLORVAL ForeColor, const COLORVAL background);

    //##ModelId=3F6EB00100A4
    void Line(const short x1, const short y1, const short x2, const short y2, const COLORVAL color);
    
    //##ModelId=3F6EB00100B1
    void DrawText(const char * Text, const short x, const short y, const COLORVAL color);
    
    //##ModelId=3F6EB00100C3
    WORD GetTextWidth(const char * Text);
    
    //##ModelId=3F6EB00100CC
    WORD GetTextHeight(const char * Text);
    
    //##ModelId=3F6EB00100CE
    void DrawBitmap(const char * pBmpName, const short x1, const short y1);
    
    //##ModelId=3F6EB00100D8
    void DrawPolyLine(const short n, const FG_Point * vert, const COLORVAL color);
    
    //##ModelId=3F6EB00100E3
    void DrawDotRect(const FG_Rect & rect, const COLORVAL color);

protected:
    //##ModelId=3F6EB0010040
    Window      m_Win;                  /*!< \brief X11窗口结构 */

    //##ModelId=3F6EB0010041
    Display *   m_Display;              /*!< \brief X11显示设备 */
    
    //##ModelId=3F6EB001004A
    //Visual *    m_Visual;
    
    //##ModelId=3F6EB0010054
    int         m_Depth;                /*!< \brief 颜色深度 */
    
    //##ModelId=3F6EB001005E
    GC          m_GC;                   /*!< \brief 绘图设备 */
    
    //##ModelId=3F6EB0010068
    GC          m_CopyGC;               /*!< \brief 缓冲区绘图设备 */
    
    //##ModelId=3F6EB0010072
    Pixmap      m_Buffer;               /*!< \brief 缓冲区的位图 */
    
    //##ModelId=3F6EB001007C
    Colormap    m_CMap;                 /*!< \brief 颜色表 */
    
    //##ModelId=40925CB002DA
    XFontSet    m_FontSet;              /*!< \brief 字体组 */
};

#endif /* FG_X11DRAWINTERFACE_H_HEADER_INCLUDED_C0B152A0 */

/*! @} */

