/*--------------------------------------------------------------------------

	FG_OSAdaptor.h - 操作系统适配器抽象类的头文件

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
 *  \brief 操作系统适配器抽象类的头文件
*/

#ifndef FG_OSADAPTOR_H_HEADER_INCLUDED_C0B1A949
#define FG_OSADAPTOR_H_HEADER_INCLUDED_C0B1A949

#include "../Utility/FG_Utility.h"
#include "FG_OSDrawInterface.h"

//##ModelId=3F49CBEF015B
/*! \brief 操作系统适配器抽象类
 *  
 *  该类为抽象类，不能实例化，该类的派生类为具体的操作系统的适配器，为单件类。
 *  抽象类为这些单件类提供统一的访问点，它还为操作系统适配层提供统一的接口  
*/
class FG_OSAdaptor
{
public:
    //##ModelId=3F4E1615027D
    /*! \brief 具体的操作系统适配器对象的全局访问点函数
     *  
     *  - 如果\ref FG_OSAdaptor::m_pAdaptor为\ref NULL
     *      - 如果是Win32系统
     *          - 创建\ref FG_Win32Adaptor的唯一实例对象
     *      - 如果是X11系统
     *          - 创建\ref FG_X11Adaptor的唯一实例对象
     *      - 让\ref FG_OSAdaptor::m_pAdaptor指向创建的对象
     *  - 返回\ref FG_OSAdaptor::m_pAdaptor
     */
    static FG_OSAdaptor * GetAdaptor();

    //##ModelId=40925CAF0329
    /*! \brief 系统运行
     *  
     *  依次调用\ref FG_OSAdaptor::InitInstance、\ref FG_OSAdaptor::Execute和\ref FG_OSAdaptor::ExitInstance
     */
    void Run(void);

    //##ModelId=3F4A19760260
    /*! \brief 注册系统消息的观察者
     *  
     *  每个系统消息只能有一个观察者（即消息接受者，\ref FG_OSMsgObserver的子类）
     *  \param type 系统消息类型
     *  \param pObserver 注册的系统消息的观察者指针
     *  \return 该消息以前设置的观察者指针
     */
    FG_OSMsgObserver * SetMsgObserver(const WORD type, FG_OSMsgObserver * const pObserver);

    //##ModelId=3F521F6D00A8
    /*! \brief 发送系统消息给注册的观察者
     *  
     *  \param pMsg 指向要发送的系统消息，由于是同步消息，发送者必须负责分配和释放该消息
     */
    void SendMsg(FG_Message * pMsg);

    //##ModelId=3FD88515012E
    /*! \brief 开始重画
     *  
     *  代理调用\ref FG_OSDrawInterface::BeginDraw\n
     *  该函数执行之后，所有的绘图操作都在一个缓冲区上进行，直到对应的\ref FG_OSAdaptor::EndDraw调用才把缓冲区内容刷新到屏幕上
     *  \param rect 需要重画的无效区域
     */
    virtual void BeginDraw(const FG_Rect & rect);

    //##ModelId=3FD885150188
    /*! \brief 结束重画
     *  
     *  代理调用\ref FG_OSDrawInterface::EndDraw，该函数把缓冲区内容刷新到屏幕上
     */
    virtual void EndDraw();

    //##ModelId=3FD8851501A6
    /*! \brief 填充矩形
     *  
     *  代理调用\ref FG_OSDrawInterface::FillRect
     *  \param rect 要填充的矩形
     *  \param ForeColor 前景色
     *  \param background 背景色
     */
    virtual void FillRect(const FG_Rect & rect, const COLORVAL ForeColor, const COLORVAL background);

    //##ModelId=3FD885150278
    /*! \brief 画线
     *  
     *  代理调用\ref FG_OSDrawInterface::Line
     *  \param x1 第一点的横坐标
     *  \param y1 第一点的横坐标
     *  \param x2 第二点的横坐标
     *  \param y2 第二点的横坐标
     *  \param color 线的颜色
     */
    virtual void Line(const short x1, const short y1, const short x2, const short y2, const COLORVAL color);

    //##ModelId=3FD8851503CD
    /*! \brief 绘制文本
     *
     *  代理调用\ref FG_OSDrawInterface::DrawText
     *  \param Text 要绘制的字符串，以\ref NULL结束
     *  \param x 文本左上角的横坐标
     *  \param y 文本左上角的纵坐标
     *  \param color 文本的颜色
     */
    virtual void DrawText(const char * Text, const short x, const short y, const COLORVAL color);

    //##ModelId=3FD885160111
    /*! \brief 得到文本的宽度
     *
     *  代理调用\ref FG_OSDrawInterface::GetTextWidth
     *  \param Text 要计算宽度的字符串，以\ref NULL结束
     *  \return 文本的宽度的像素数
     */
    virtual WORD GetTextWidth(const char * Text);

    //##ModelId=3FD88516017F
    /*! \brief 得到文本的高度
     *
     *  代理调用\ref FG_OSDrawInterface::GetTextHeight
     *  \param Text 要计算高度的字符串，以\ref NULL结束
     *  \return 文本的高度的像素数
     */
    virtual WORD GetTextHeight(const char * Text);

    //##ModelId=3FD8851601ED
    /*! \brief 绘制位图
     *
     *  代理调用\ref FG_OSDrawInterface::DrawBitmap
     *  \param pBmpName 要绘制的位图名
     *  \param x1 位图左上角的横坐标
     *  \param y1 位图左上角的纵坐标
     */
    virtual void DrawBitmap(const char * pBmpName, const short x1, const short y1);

    //##ModelId=3FD8851602F2
    /*! \brief 绘制折线
     *
     *  代理调用\ref FG_OSDrawInterface::DrawPolyLine
     *  \param n 该折线包含的点数
     *  \param vert 所有点的数组
     *  \param color 折线的颜色
     */
    virtual void DrawPolyLine(const short n, const FG_Point * vert, const COLORVAL color);

    //##ModelId=3FD885170018
    /*! \brief 绘制点划线矩形
     *
     *  代理调用\ref FG_OSDrawInterface::DrawDotRect
     *  \param rect 要绘制的矩形
     *  \param color 矩形的颜色
     */
    virtual void DrawDotRect(const FG_Rect & rect, const COLORVAL color);

protected:
    //##ModelId=3F4E0F5B028B
    /*! \brief 构造函数，用户不能直接调用
     */
    FG_OSAdaptor();

    //##ModelId=3F4E03420206
    /*! \brief 程序初始化
     *
     *  该函数为模板方法，由派生类实现
     *  \return 初始化是否成功\n
     *          true    成功\n
     *          false   失败
     */
    virtual bool InitInstance() = 0;

    //##ModelId=3F4E03DC0013
    /*! \brief 程序退出
     *
     *  该函数为模板方法，由派生类实现
     *  \return 退出是否成功\n
     *          true    成功\n
     *          false   失败
     */
    virtual bool ExitInstance() = 0;

    //##ModelId=3F4E03ED0194
    /*! \brief 程序运行过程，执行消息循环
     *
     *  该函数为模板方法，由派生类实现
     *  \return 退出是否成功\n
     *          true    成功\n
     *          false   失败
     */
    virtual bool Execute() = 0;

    //##ModelId=409260AC00B1
    FG_OSMsgObserver * m_ppObserver[FG_MAX_SYS_MSG];    /*!< \brief 记录所有的系统消息的观察者的数组 */

    //##ModelId=3F4EFF4B0278
    static FG_OSDrawInterface * m_pDraw;                /*!< \brief 指向唯一的绘图接口类的指针 */
    //##ModelId=3F4EFD94015F
    static FG_OSAdaptor * m_pAdaptor;                   /*!< \brief 指向唯一的操作系统适配器的指针，用于实现单件类 */
};

/*! \brief 封装操作系统适配器的全局访问点\ref FG_OSAdaptor::GetAdaptor的全局函数
 *
 *  \return 指向唯一的操作系统适配器的指针
 */
FG_OSAdaptor * FG_GetAdaptor();

#endif /* FG_OSADAPTOR_H_HEADER_INCLUDED_C0B1A949 */

/*! @} */

