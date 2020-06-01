/*--------------------------------------------------------------------------

	FG_RadioButton.h - 收音机按钮类的头文件

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
 *  \brief 收音机按钮类的头文件
 */

#ifndef FG_RADIOBUTTON_H_HEADER_INCLUDED_C0A7BA3D
#define FG_RADIOBUTTON_H_HEADER_INCLUDED_C0A7BA3D

#include "FG_TextWidget.h"

//##ModelId=3F37D6D30247
/*! \brief 收音机按钮类
 *
 *  用圆点选择的收音机按钮，一组收音机按钮只有一个能被选中
 */
class FG_RadioButton : public FG_TextWidget
{
public:
    //##ModelId=3F65E8E302DE
    /*! \brief 收音机按钮类的构造函数
     *
     *  \param Text 收音机按钮上显示的文本
     *  \param Rect 收音机按钮占据的矩形区域
     *  \param pSameGroup 同组的收音机按钮，通过链表把一组收音机按钮连接起来
     *  \param wID 收音机按钮控件的唯一标识
     */
    FG_RadioButton(const char * Text, const FG_Rect & Rect, FG_RadioButton * const pSameGroup = NULL, const WORD wID = 0);

    //##ModelId=3F65E8E302FC
	/*! \brief 收音机按钮是否被选中
	 *
	 *  \return true    选中\n
     *          false   未选中
     */
	bool IsChecked() const { return m_bChecked; }

    //##ModelId=3F65E8E30306
	/*! \brief 改变收音机按钮的选择状态
	 *
     *  改变选中状态后，需要重画本控件
	 *  \param bChecked 选中或取消选中
	 *                  true    选中\n
     *                  false   未选中
	 */
	void SetChecked(bool bChecked) { m_bChecked = bChecked; RequestDraw();}

protected:
    //##ModelId=3F65E8E3031A
    /*! \brief 重画消息\ref FG_MSG_DRAW的处理函数

     *  \param pAdaptor 指向操作系统适配器的指针
     */
	void OnDraw(FG_OSAdaptor * pAdaptor);

    //##ModelId=3F65E8E3032E
    /*! \brief 键盘按下消息（\ref FG_MSG_KEY，\ref FKS_DOWN）的处理函数

     *  \param pMsg 指向键盘消息结构的指针
     */
	bool OnKeyDown(FG_Message * pMsg);

    //##ModelId=3F65E8E30342
    /*! \brief 鼠标左键按下消息（\ref FG_MSG_MOUSE，\ref FMS_LBUTTONDOWN）的处理函数

     *  \param pMsg 指向鼠标消息结构的指针
     */
	bool OnLButtonDown(FG_Message * pMsg);

    //##ModelId=3F65E8E302CA
    bool m_bChecked;                /*!< \brief 收音机按钮是否被选中，true代表被选中，false代表未被选中 */

    //##ModelId=3F65EDEC0133
    FG_RadioButton * m_pNext;       /*!< \brief 本组中的下一个收音机按钮 */

private:
    //##ModelId=3F65EDEC0183
    /*! \brief 把本组的其他收音机按钮取消选中
     *
     *  取消选中时需要重画和发送通知消息\ref FRN_UNCHECKED
     */
    void UncheckGroup(void);

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_RADIOBUTTON_H_HEADER_INCLUDED_C0A7BA3D */

/*! @} */

