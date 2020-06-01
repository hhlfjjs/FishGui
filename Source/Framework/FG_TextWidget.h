/*--------------------------------------------------------------------------

	FG_TextWidget.h - 文本控件抽象类的头文件

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
 *  \brief 文本控件抽象类的头文件
*/

#ifndef FG_TEXTWIDGET_H_HEADER_INCLUDED_C0A7F838
#define FG_TEXTWIDGET_H_HEADER_INCLUDED_C0A7F838

#include "../Utility/FG_Utility.h"
#include "FG_Widget.h"

//##ModelId=3F388AF702A9
/*! \brief 文本控件抽象类的头文件
 *
 *  该类的派生类具有处理文本的能力
*/
class FG_TextWidget : public FG_Widget
{
public:
    //##ModelId=3F5B47050056
    /*! \brief 文本控件抽象类的构造函数
     *
     *  \param Text 文本控件抽象类的文本
     *  \param Rect 文本控件抽象类所占据的屏幕矩形
     *  \param wID 文本控件抽象类的唯一标识
     *  \param wStyle 文本控件抽象类的\ref Style
     */
    FG_TextWidget(const char * Text, const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE)
        : m_Text(Text), FG_Widget(Rect, wID, wStyle)
    {}

    //##ModelId=3F5B470500B0
    /*! \brief 得到该控件的文本
     *
     *  \return 该控件的文本
     */
    char * GetText(void) const { return m_Text.DataGet(); }
    
    //##ModelId=3F5B470500C4
    /*! \brief 设置该控件的文本
     *
     *  需要重画该控件
     *  \param Text 要设置的文本
     */
    void SetText(char * const Text) { m_Text.DataSet(Text); RequestDraw(); }
    
    //##ModelId=3F6EAC8F01DC
    /*! \brief 得到该控件的文本的长度
     *
     *  \return 该控件的文本的长度
     */
    WORD TextLength(void) const { return m_Text.Length(); }

    //##ModelId=3F6EAC8F01F0
    /*! \brief 绘制文本的焦点框
     *
     *  \param pAdaptor 指向操作系统适配器对象的指针
     *  \param x 焦点框的左上角横坐标
     *  \param y 焦点框的左上角纵坐标
     */
    void DrawTextFocus(FG_OSAdaptor * const pAdaptor, const WORD x, const WORD y);

protected:
    //##ModelId=409260D50150
    FG_String m_Text;           /*!< \brief 该控件中保存的文本 */

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_TEXTWIDGET_H_HEADER_INCLUDED_C0A7F838 */

/*! @} */

