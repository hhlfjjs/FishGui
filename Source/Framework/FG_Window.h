/*--------------------------------------------------------------------------

	FG_Window.h - 窗口类的头文件

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
/*! \addtogroup Framework
 *  @{ 
 */

/*! \file
 *  \brief 窗口类的头文件
 *
*/

#ifndef FG_WINDOW_H_HEADER_INCLUDED_C0AD431E
#define FG_WINDOW_H_HEADER_INCLUDED_C0AD431E

#include "../Utility/FG_Utility.h"
#include "FG_Container.h"
#include "FG_Widget.h"
#include "FG_KeyMap.h"

//##ModelId=3F52B6BD00A5
/*! \brief 窗口类
 *
 *  该类的派生类可以放置在屏幕上作为窗口，窗口中可以容纳各种不同的控件
 */
class FG_Window : public FG_Container
{
public:
    //##ModelId=3F5838220352
    /*! \brief 构造函数
     *
     *  当前有焦点的控件指针\ref m_pFocus被设置为\ref NULL
     *
     *  \param title 窗口标题，以0结束的字符串
     *  \param wID 窗口的唯一标识，缺省值为0
     *  \param wStyle \ref Style
     */
    FG_Window(const char * title, const WORD wID = 0, const WORD wStyle = FS_NONE)
        : m_Title(title), m_pFocus(NULL), FG_Container(wID, wStyle)
        {}

    //##ModelId=3F58382201CB
    /*! \brief 构造函数
     *
     *  当前有焦点的控件指针\ref m_pFocus被设置为\ref NULL
     *
     *  \param title 窗口标题，以0结束的字符串
     *  \param Rect 窗口占据的矩形元素
     *  \param wID 窗口的唯一标识，缺省值为0
     *  \param wStyle \ref Style
     */
    FG_Window(const char * title, const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE) 
        : m_Title(title), m_pFocus(NULL), FG_Container(Rect, wID, wStyle)
        {}

    //##ModelId=3F5B470501FA
    /*! \brief 在窗口中添加一个控件
     *
     *  控件之间一般不能重叠，如果有重叠，后添加的控件覆盖以前添加的控件，焦点被切换到刚添加的控件
     *
     *  \param pWidget 要添加的控件指针
     *  \return 添加操作是否成功\n
     *          true　 成功\n
     *          false　失败
     */
    bool AddWidget(FG_Widget * const pWidget);

    //##ModelId=3F5B47050240
    /*! \brief 从窗口中删除一个控件
     *
     *  如果删除的是当前焦点控件，把焦点指针置为\ref NULL，之后，用户需要自己调整焦点
     *  \param pWidget 要删除的控件指针
     *  \return 删除操作是否成功\n
     *          true　 成功\n
     *          false　失败
     */
    bool RemoveWidget(FG_Widget * const pWidget);

    //##ModelId=3F6193A800D6
    /*! \brief 返回该窗口的客户区矩形
     *
     *  覆盖基类的算法，窗口的客户区为除去边框和标题区域的矩形
     *  \param rect 返回的客户区矩形
     */
    void GetClientRect(FG_Rect & rect) const;

    //##ModelId=3F5EDD9E03DF
    /*! \brief 注册快捷键
     *
     *  快捷键的含义为：当本窗口为焦点窗口时，如果用户按键值为wOrgKey的键盘消息，
     *  直接把该键盘消息发送给标识为wID的控件，并把键值转换成wActKey
     *  \param wOrgKey 原始的\ref Virtual_Key
     *  \param wActKey 发送到对应的控件时，应转换成的实际\ref Virtual_Key
     *  \param wID 注册快捷键的控件
     *  \return 删除操作是否成功\n
     *          true　 成功\n
     *          false　失败
     */
	bool RegisterKey(const WORD wOrgKey, const WORD wActKey, const WORD wID);

    //##ModelId=3F6193A800F4
    /*! \brief 改变焦点控件
     *
     *  焦点控件即当前有输入焦点的控件，不是快捷键的键盘消息应该发送给该控件\n
     *  - 改变过程中
     *      - 给失去焦点的控件发送焦点失去消息
     *      - 给得到焦点的控件发送焦点得到消息
     *
     *  \param pWidget 要得到输入焦点的控件
     */
    void ChangeFocus(FG_Widget * const pWidget);

protected:
    //##ModelId=3F584C9403D0
    /*! \brief 重画消息\ref FG_MSG_DRAW的处理函数
     *
     *  按照覆盖顺序把\ref FG_MSG_DRAW消息发送给每个子控件，要求他们重画自己
     *  \param pAdaptor 指向操作系统适配器的指针
     */
    void OnDraw(FG_OSAdaptor * pAdaptor);

    //##ModelId=3F5C4AEB0321
    /*! \brief 键盘消息\ref FG_MSG_KEY的处理函数
     *
     *  - 如果是\ref FVK_TAB键，按顺序切换焦点
     *  - 否则，发送给快捷键管理器处理
     *  - 如果不是快捷键（快捷键管理器未处理），发送给当前焦点窗口
     *
     *  \param pMsg 指向键盘消息结构的指针
     *  \return 该键盘消息是否被处理
     *          true    该键盘消息已被处理
     *          false   该键盘消息未被处理
     */
    bool OnKey(FG_Message * pMsg);

    //##ModelId=3F5C4AEB032B
    /*! \brief 鼠标消息\ref FG_MSG_MOUSE的处理函数
     *
     *  把该消息发送给鼠标指针所在的窗口元素，并且使该窗口元素得到焦点
     *  \param pMsg 指向鼠标消息结构的指针
     *  \return 该鼠标消息是否被处理
     *          true    该鼠标消息已被处理
     *          false   该鼠标消息未被处理
     */
    bool OnMouse(FG_Message * pMsg);

    //##ModelId=3F603B980398
    /*! \brief 控件发送的要求重画消息\ref FG_MSG_DRAW_REQUEST的处理函数
     *
     *  - 如果本窗口为焦点窗口
     *      - 直接发送\ref FG_MSG_DRAW消息给要求重画控件，使其重画自己
     *  - 否则
     *      - 给屏幕对象发送要求重画消息\ref FG_MSG_DRAW_REQUEST
     *
     *  \param pMsg 指向要求重画消息结构的指针
     */
    void OnDrawRequest(FG_Message * pMsg);

    //##ModelId=3F6193A80162
    /*! \brief 焦点切换消息\ref FG_MSG_FOCUS的处理函数
     *
     *  \param pMsg 指向焦点切换消息结构的指针
     */
    void OnFocus(FG_Message * pMsg);

    //##ModelId=409260D5024A
    FG_String   m_Title;                    /*!< \brief 窗口标题 */
    //##ModelId=3F6193A800B9
    FG_Widget * m_pFocus;                   /*!< \brief 当前有焦点的控件指针 */

private:
    //##ModelId=3F5E6ECC03A6
    FG_KeyMap   m_KeyMap;                   /*!< \brief 键盘映射表管理器 */

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_WINDOW_H_HEADER_INCLUDED_C0AD431E */

/* @} */

