/*--------------------------------------------------------------------------

	FG_Bitmap.h - 位图控件类的头文件

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
 *  \brief 位图控件类的头文件
*/

#ifndef FG_BITMAP_H_HEADER_INCLUDED_C0A7F853
#define FG_BITMAP_H_HEADER_INCLUDED_C0A7F853

#include "FG_TextWidget.h"

//##ModelId=3F37D72700AE
/*! \brief 位图控件类
 *
 *  位图控件可以放在窗口上，用来显示静态的位图。\n
 *  通过定时器改变当前显示的位图，可以实现动画的显示。
 */
class FG_Bitmap : public FG_TextWidget
{
public:
    //##ModelId=3F5DE0D00234
    /*! \brief 构造函数
     *
     *  \param Text 要显示的位图名称
     *  \param Rect 位图显示的矩形区域，在没有裁减区的情况下，Rect的左上角坐标为位图显示的左上角坐标，
     *              Rect的右下角坐标被忽略，位图不会被裁剪。
     *  \param wID 位图控件的唯一标识，缺省值为0
     *　\param wStyle 位图控件的边框风格，缺省值为\ref FS_NONE|\ref GS_TRANSPARENT
     */
	FG_Bitmap(const char * Text, const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE|GS_TRANSPARENT)
		: FG_TextWidget(Text, Rect, wID, wStyle) {}

    //##ModelId=3F71AB1E03A2
    /*! \brief 返回控件能否得到焦点的标志
     *
     *  位图控件永远不能得到焦点
     *  \return false   该控件不能得到焦点
     */
    bool CanGetFocus(void) const { return false; }

protected:
    //##ModelId=3F5DE0D00284
    /*! \brief \ref FG_MSG_DRAW消息的处理函数
     *
     *  \param pAdaptor 指向操作系统适配器接口的指针
     */
	void OnDraw(FG_OSAdaptor * pAdaptor);

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_BITMAP_H_HEADER_INCLUDED_C0A7F853 */

/*! @} */

