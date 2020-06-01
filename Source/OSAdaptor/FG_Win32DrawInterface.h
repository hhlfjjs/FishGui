/*--------------------------------------------------------------------------

	FG_Win32DrawInterface.h - Win32的绘图接口类的头文件

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
 *  \brief Win32的绘图接口类的头文件
 */

#ifndef FG_WIN32DRAWINTERFACE_H_HEADER_INCLUDED_C0B152A0
#define FG_WIN32DRAWINTERFACE_H_HEADER_INCLUDED_C0B152A0

#include "FG_OSDrawInterface.h"

//##ModelId=3F49D01202C6
/*! \brief Win32的绘图接口类
 *  
 *  该类封装Win32的绘图过程
 */
class FG_Win32DrawInterface : public FG_OSDrawInterface
{
public:
    //##ModelId=3F4EDED00308
    /*! \brief Win32的绘图接口类的构造函数 */
    FG_Win32DrawInterface() : m_hMemDC(0) {}

    //##ModelId=3F71AB2E0279
    /*! \brief Win32的绘图接口类的析构函数 */
    ~FG_Win32DrawInterface();

    //##ModelId=3F6EAFFF0390
    /*! \brief 设置Win32的绘图设备句柄
     *
     *  \param hdc 要设置的绘图设备句柄
     */
    void SetHDC(const HDC hdc) { m_hDC = hdc; }

    //##ModelId=3F4EDED00326
    void BeginDraw(const FG_Rect & rect);

    //##ModelId=3F4EDED003A8
    void EndDraw();
    
    //##ModelId=3F4EDED003E4
    void FillRect(const FG_Rect & rect, const COLORVAL ForeColor, const COLORVAL background);

    //##ModelId=3F4EDED10133
    void Line(const short x1, const short y1, const short x2, const short y2, const COLORVAL color);

    //##ModelId=3F4EDED1031E
    void DrawText(const char * Text, const short x, const short y, const COLORVAL color);

    //##ModelId=3F4EDED200DA
    WORD GetTextWidth(const char * Text);

    //##ModelId=3F4EDED20184
    WORD GetTextHeight(const char * Text);

    //##ModelId=3F4EDED20239
    void DrawBitmap(const char * pBmpName, const short x1, const short y1);

    //##ModelId=3F6193B201F2
    void DrawPolyLine(const short n, const FG_Point * vert, const COLORVAL color);

    //##ModelId=3F6EAC820075
    void DrawDotRect(const FG_Rect & rect, const COLORVAL color);

protected:
    //##ModelId=3F6EAFFF012D
    HDC         m_hDC;          /*!< \brief Win32绘图设备句柄 */

    //##ModelId=3F6EAFFF017D
    HDC         m_hMemDC;       /*!< \brief 兼容的内存绘图设备句柄，用作绘图缓冲区 */

    //##ModelId=3F6EAFFF01CD
    HBITMAP     m_hBitmap;      /*!< \brief 内存缓冲区所用的位图句柄 */

    //##ModelId=3F6EAFFF021E
    HFONT       m_hFont;        /*!< \brief 字体句柄 */
};

#endif /* FG_WIN32DRAWINTERFACE_H_HEADER_INCLUDED_C0B152A0 */

/*! @} */

