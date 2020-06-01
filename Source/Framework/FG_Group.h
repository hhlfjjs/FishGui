/*--------------------------------------------------------------------------

	FG_Group.h - 分组控件类的头文件

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
 *  \brief 分组控件类的头文件
 */

#ifndef FG_GROUP_H_HEADER_INCLUDED_C0A7D115
#define FG_GROUP_H_HEADER_INCLUDED_C0A7D115

#include "FG_TextWidget.h"

//##ModelId=3F584D87031B
/*! \brief 分组控件类
 *
 *  该控件放置在窗口上，显示为静态的矩形区域，用于把控件分组
 */
class FG_Group : public FG_TextWidget
{
public:
    //##ModelId=3F6193A70193
	/*! \brief 分组控件的构造函数
	 *
	 *  \param Text 分组控件左上角显示的标题，以\ref NULL结束的字符串
	 *  \param Rect 分组控件占据的矩形区域
	 *  \param wID 分组控件的唯一标识，缺省为0
	 */
	FG_Group(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
        : FG_TextWidget(Text, Rect, wID, FS_NONE|GS_TRANSPARENT) {}

    //##ModelId=3F6EAC8F0088
    /*! \brief 返回控件能否得到焦点的标志
     *
     *  分组控件永远不能得到焦点
     *  \return false   该控件不能得到焦点
     */
    bool CanGetFocus(void) const { return false; }

protected:
    //##ModelId=3F6193A701A6
    /*! \brief 重画消息\ref FG_MSG_DRAW的处理函数
     *
     *  \param pAdaptor 指向操作系统适配器的指针
     */
	void OnDraw(FG_OSAdaptor * pAdaptor);

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_GROUP_H_HEADER_INCLUDED_C0A7D115 */

/*! @} */

