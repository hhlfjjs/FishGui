/*--------------------------------------------------------------------------

	FG_Label.h - 文字标签类的头文件

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
 *  \brief 文字标签类的头文件
 */

#ifndef FG_LABEL_H_HEADER_INCLUDED_C0A7989C
#define FG_LABEL_H_HEADER_INCLUDED_C0A7989C

#include "FG_TextWidget.h"

//##ModelId=3F37D70F0185
/*! \brief 文字标签类
 *
 *  用于在窗口上显示静态文本
 */
class FG_Label : public FG_TextWidget
{
public:
    //##ModelId=3F5EE86B009C
	/*! \brief 文字标签的构造函数
	 *
     *  文字的对齐方式缺省为\ref TS_CENTER
	 *  \param Text 文字标签的文本，以\ref NULL结束的字符串
	 *  \param Rect 文字标签占据的矩形区域
	 *  \param wID 文字标签的唯一标识，缺省为0
	 *  \param wStyle 文字标签的边框风格，缺省为\ref FS_NONE|\ref GS_TRANSPARENT
	 *  \return  
	 */
	FG_Label(const char * Text, const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE|GS_TRANSPARENT)
		: FG_TextWidget(Text, Rect, wID, wStyle)
	{
		if (! (m_wStyle & TS_MASK))
			m_wStyle |= TS_CENTER;
	}

    //##ModelId=3F6EAC8F00A6
    /*! \brief 返回控件能否得到焦点的标志
     *
     *  文本标签永远不能得到焦点
     *  \return false   该控件不能得到焦点
     */
    bool CanGetFocus(void) const { return false; }

protected:
    //##ModelId=3F5EE86B00C6
    /*! \brief 重画消息\ref FG_MSG_DRAW的处理函数
     *
     *  \param pAdaptor 指向操作系统适配器的指针
     */
	void OnDraw(FG_OSAdaptor * pAdaptor);

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_LABEL_H_HEADER_INCLUDED_C0A7989C */

/*! @} */

