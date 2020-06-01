/*--------------------------------------------------------------------------

	FG_OSDrawInterface.h - 操作系统绘图接口类的头文件

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
 *  \brief 操作系统绘图接口类的头文件
 */

#ifndef FG_OSDRAWINTERFACE_H_HEADER_INCLUDED_C0B113C4
#define FG_OSDRAWINTERFACE_H_HEADER_INCLUDED_C0B113C4

#include "../Utility/FG_Utility.h"

//##ModelId=3F49CF2F0067
/*! \brief 操作系统绘图接口类
 *
 *  该类的派生类封装具体的操作系统的绘图接口，给框架层提供一个统一的接口
 */
class FG_OSDrawInterface
{
public:
    //##ModelId=3F6EAC810381
    /*! \brief 缺省构造函数
     */
    FG_OSDrawInterface() : m_iDrawCount(0) {}

    //##ModelId=3F6EAC81038B
    /*! \brief 析构函数
     */
    virtual ~FG_OSDrawInterface() {}

    //##ModelId=3F4EBF2C01D4
    /*! \brief 开始重画
     *  
     *  该函数执行之后，所有的绘图操作都在一个缓冲区上进行，直到对应的\ref FG_OSDrawInterface::EndDraw调用才把缓冲区内容刷新到屏幕上
     *  \param rect 需要重画的无效区域
     */
    virtual void BeginDraw(const FG_Rect & rect) = 0;

    //##ModelId=3F4EBF2C0293
    /*! \brief 结束重画
     *  
     *  该函数把缓冲区内容刷新到屏幕上
     */
    virtual void EndDraw() = 0;

    //##ModelId=3F4EBF2C02ED
    /*! \brief 填充矩形
     *  
     *  \param rect 要填充的矩形
     *  \param ForeColor 前景色
     *  \param background 背景色
     */
    virtual void FillRect(const FG_Rect & rect, const COLORVAL ForeColor, const COLORVAL background) = 0;

    //##ModelId=3F4EBF2D0081
    /*! \brief 画线
     *  
     *  \param x1 第一点的横坐标
     *  \param y1 第一点的横坐标
     *  \param x2 第二点的横坐标
     *  \param y2 第二点的横坐标
     *  \param color 线的颜色
     */
    virtual void Line(const short x1, const short y1, const short x2, const short y2, const COLORVAL color) = 0;

    //##ModelId=3F4EBF2D02B2
    /*! \brief 绘制文本
     *
     *  \param Text 要绘制的字符串，以\ref NULL结束
     *  \param x 文本左上角的横坐标
     *  \param y 文本左上角的纵坐标
     *  \param color 文本的颜色
     */
    virtual void DrawText(const char * Text, const short x, const short y, const COLORVAL color) = 0;

    //##ModelId=3F4EBF2E00BF
    /*! \brief 得到文本的宽度
     *
     *  \param Text 要计算宽度的字符串，以\ref NULL结束
     *  \return 文本的宽度的像素数
     */
    virtual WORD GetTextWidth(const char * Text) = 0;

    //##ModelId=3F4EBF2E0191
    /*! \brief 得到文本的高度
     *
     *  \param Text 要计算高度的字符串，以\ref NULL结束
     *  \return 文本的高度的像素数
     */
    virtual WORD GetTextHeight(const char * Text) = 0;

    //##ModelId=3F4EBF2E026D
    /*! \brief 绘制位图
     *
     *  \param pBmpName 要绘制的位图名
     *  \param x1 位图左上角的横坐标
     *  \param y1 位图左上角的纵坐标
     */
    virtual void DrawBitmap(const char * pBmpName, const short x1, const short y1) = 0;

    //##ModelId=3F6193B20152
    /*! \brief 绘制折线
     *
     *  \param n 该折线包含的点数
     *  \param vert 所有点的数组
     *  \param color 折线的颜色
     */
    virtual void DrawPolyLine(const short n, const FG_Point * vert, const COLORVAL color) = 0;

    //##ModelId=3F6EAC810395
    /*! \brief 绘制点划线矩形
     *
     *  \param rect 要绘制的矩形
     *  \param color 矩形的颜色
     */
    virtual void DrawDotRect(const FG_Rect & rect, const COLORVAL color) = 0;

protected:
    //##ModelId=3F6EAC810350
    /*! \brief 当前的需要重画的无效区域
     *
     *  调用\ref FG_OSDrawInterface::BeginDraw的参数rect会组合进该无效区域中。\n
     *  调用\ref FG_OSDrawInterface::EndDraw时，该无效区域被清空。
     */
    FG_Rect     m_Invalid;

    //##ModelId=3F6EAC810363
    /*! \brief \ref FG_OSDrawInterface::BeginDraw被调用的次数
     *
     *  \ref FG_OSDrawInterface::BeginDraw被调用时，该值加1。\n
     *  \ref FG_OSDrawInterface::EndDraw被调用时，该值减1。
     */
    int         m_iDrawCount;
};

#endif /* FG_OSDRAWINTERFACE_H_HEADER_INCLUDED_C0B113C4 */

/*! @} */

