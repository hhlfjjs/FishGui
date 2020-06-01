/*--------------------------------------------------------------------------

	FG_Factory.h - 工厂类的头文件

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
 *  \brief 工厂类的头文件
 */

#ifndef FG_FACTORY_H_HEADER_INCLUDED_C0A7A9C0
#define FG_FACTORY_H_HEADER_INCLUDED_C0A7A9C0

#include "../Utility/FG_Utility.h"
#include "FG_Button.h"
#include "FG_Bitmap.h"
#include "FG_Label.h"
#include "FG_Group.h"
#include "FG_Edit.h"
#include "FG_CheckBox.h"
#include "FG_RadioButton.h"

//##ModelId=3F37D6AD0116
/*! \brief 工厂类
 *
 *  负责封装所有控件的创建过程，用户可覆盖此类中的接口函数，改为创建不同的控件类型
 */
class FG_Factory
{
public:
    //##ModelId=3F5B470401E5
    /*! \brief 构造函数
     */
    FG_Factory() {}

    //##ModelId=3F71ACAE0181
    /*! \brief 虚析构函数
     */
    virtual ~FG_Factory() {}

    //##ModelId=3F71ACAE0195
    /*! \brief 创建位图控件
     *
     *  \param Text 位图控件的标题，以\ref NULL结束的字符串
     *  \param Rect 位图控件所在的矩形区域
     *  \param wID 位图控件的唯一标识
     *  \param wStyle 位图控件的\ref Style
     *  \return 创建出的位图控件
     */
    virtual FG_Bitmap * CreateBitmap(const char * Text, const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE|GS_TRANSPARENT)
    {
        return new FG_Bitmap(Text, Rect, wID, wStyle);
    }

    //##ModelId=3F71ACAE0221
    /*! \brief 创建按钮控件
     *
     *  \param Text 按钮控件的标题，以\ref NULL结束的字符串
     *  \param Rect 按钮所在的矩形区域
     *  \param wID 按钮的唯一标识
     *  \return 创建出的按钮指针
     */
    virtual FG_Button * CreateButton(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
    {
        return new FG_Button(Text, Rect, wID);
    }

    //##ModelId=3F71ACAE02A3
    /*! \brief 创建选择按钮控件
     *
     *  \param Text 选择按钮控件的标题，以\ref NULL结束的字符串
     *  \param Rect 选择按钮所在的矩形区域
     *  \param wID 选择按钮的唯一标识
     *  \return 创建出的选择按钮指针
     */
    virtual FG_CheckBox * CreateCheckBox(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
    {
        return new FG_CheckBox(Text, Rect, wID);
    }

    //##ModelId=3F71ACAE032F
    /*! \brief 创建编辑控件
     *
     *  \param Text 编辑控件的初始文本，以\ref NULL结束的字符串
     *  \param Rect 编辑控件所在的矩形区域
     *  \param wLimit 编辑控件能容纳的最大字符个数
     *  \param wID 编辑控件的唯一标识
     *  \param wStyle 编辑控件的\ref Style
     *  \return 创建出的编辑控件指针
     */
    virtual FG_Edit * CreateEdit(const char * Text, const FG_Rect & Rect, const WORD wLimit, WORD wID = 0, const WORD wStyle = TS_LEFT|FS_RECESSED)
    {
        return new FG_Edit(Text, Rect, wLimit, wID, wStyle);
    }

    //##ModelId=3F71ACAF0038
    /*! \brief 创建分组控件
     *
     *  \param Text 分组控件的标题，以\ref NULL结束的字符串
     *  \param Rect 分组控件所在的矩形区域
     *  \param wID 分组控件的唯一标识
     *  \return 创建出的分组控件指针
     */
    virtual FG_Group * CreateGroup(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
    {
        return new FG_Group(Text, Rect, wID);
    }

    //##ModelId=3F71ACAF00E2
    /*! \brief 创建文字标签
     *
     *  \param Text 文字标签的标题，以\ref NULL结束的字符串
     *  \param Rect 文字标签所在的矩形区域
     *  \param wID 文字标签的唯一标识
     *  \param wStyle 文字标签的\ref Style
     *  \return 创建出的文字标签指针
     */
    virtual FG_Label * CreateLabel(const char * Text, const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE|GS_TRANSPARENT)
    {
        return new FG_Label(Text, Rect, wID, wStyle);
    }

    //##ModelId=3F71ACAF01BE
    /*! \brief 创建收音机按钮控件
     *
     *  \param Text 收音机按钮控件的标题，以\ref NULL结束的字符串
     *  \param Rect 收音机按钮所在的矩形区域
     *  \param pSameGroup 同组的收音机按钮，通过链表把一组收音机按钮连接起来
     *  \param wID 收音机按钮的唯一标识
     *  \return 创建出的收音机按钮指针
     */
    virtual FG_RadioButton * CreateRadioButton(const char * Text, const FG_Rect & Rect, FG_RadioButton * const pSameGroup = NULL, const WORD wID = 0)
    {
        return new FG_RadioButton(Text, Rect, pSameGroup, wID);
    }
};

#endif /* FG_FACTORY_H_HEADER_INCLUDED_C0A7A9C0 */

/*! @} */

