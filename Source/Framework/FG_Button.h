/*--------------------------------------------------------------------------

	FG_Button.h - 按钮控件类的头文件

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
 *  \brief 按钮控件类的头文件
*/

#ifndef FG_BUTTON_H_HEADER_INCLUDED_C0A7A9C0
#define FG_BUTTON_H_HEADER_INCLUDED_C0A7A9C0

#include "FG_TextWidget.h"

//##ModelId=3F71AE3101D7
/*! \brief 按钮控件类
 *
 *  该类的对象放在窗口上作为按钮使用
 */
class FG_Button : public FG_TextWidget
{
public:
    //##ModelId=3F71AE3103A5
    /*! \brief 按钮控件的构造函数
     *
     *  \param Text 按钮上的文本，以\ref NULL结束的字符串
     *  \param Rect 按钮控件占据的矩形区域
     *  \param wID 按钮控件的唯一标识
     */
    FG_Button(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
        : FG_TextWidget(Text, Rect, wID, FS_RAISED)
    {}

protected:
    //##ModelId=3F71AE3103C2
    /*! \brief \ref FG_MSG_DRAW消息的处理函数
     *
     *  \param pAdaptor 指向操作系统适配器接口的指针
     */
    void OnDraw(FG_OSAdaptor * pAdaptor);

    //##ModelId=3F71AE3103D6
    /*! \brief 键盘按下消息（\ref FG_MSG_KEY，\ref FKS_DOWN）的处理函数

     *  \param pMsg 指向键盘消息结构的指针
     */
    bool OnKeyDown(FG_Message * pMsg);

    //##ModelId=3F71AE320002
    /*! \brief 键盘弹起消息（\ref FG_MSG_KEY，\ref FKS_UP）的处理函数

     *  \param pMsg 指向键盘消息结构的指针
     */
    bool OnKeyUp(FG_Message * pMsg);

    //##ModelId=3F71AE320016
    /*! \brief 鼠标左键按下消息（\ref FG_MSG_MOUSE，\ref FMS_LBUTTONDOWN）的处理函数

     *  \param pMsg 指向鼠标消息结构的指针
     */
    bool OnLButtonDown(FG_Message * pMsg);

    //##ModelId=3F71AE32002A
    /*! \brief 鼠标左键弹起消息（\ref FG_MSG_MOUSE，\ref FMS_LBUTTONUP）的处理函数

     *  \param pMsg 指向鼠标消息结构的指针
     */
    bool OnLButtonUp(FG_Message * pMsg);

    //##ModelId=3F71AE32003E
    /*! \brief 保证按钮控件总能弹起的定时器消息（\ref TIMERID_UP）的处理函数
     *
     *  - 设置按钮为凸起状态
     *  - 要求重画
     *  - 删除定时器
     *  - 发送通知消息
     */
    void OnTimerUp(void);

private:
    //##ModelId=3F71AE310372
    /*! \brief 保证按钮控件总能弹起的定时器ID

     *  为了防止键盘或鼠标的弹起消息丢失造成按钮无法弹起，用一个定时器来在这种情况下弹起按钮
     */
    enum
    {
        TIMERID_UP = 0xff
    };

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_BUTTON_H_HEADER_INCLUDED_C0A7A9C0 */

/*! @} */

