/*--------------------------------------------------------------------------

	FG_Widget.h - 控件抽象类的头文件

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
 *  \brief 控件抽象类的头文件
 *
*/

#ifndef FG_WIDGET_H_HEADER_INCLUDED_C0A7936B
#define FG_WIDGET_H_HEADER_INCLUDED_C0A7936B

#include "FG_Object.h"

//##ModelId=3F37D6A30299
/*! \brief 控件抽象类
 *
 *  该类的派生类可以放置在窗口上作为控件，控件类中不能再容纳其他窗口元素
 */
class FG_Widget : public FG_Object
{
public:
    //##ModelId=3F5B47050100
    /*! \brief 构造函数
     *
     *  \param Rect 该控件占据的矩形区域
     *  \param wID 该控件的唯一标识，缺省为0
     *  \param wStyle 该控件的边框风格，缺省为\ref FS_NONE
     */
    FG_Widget(const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE)
        : m_bCanGetFocus(true), FG_Object(Rect, wID, wStyle)
    {}

    //##ModelId=3F6193A80071
    /*! \brief 返回控件能否得到焦点的标志
     *
     *  \return 控件能否得到焦点的标志\n
     *          true    该控件能得到焦点\n
     *          false   该控件不能得到焦点
     */
    virtual bool CanGetFocus(void) const { return m_bCanGetFocus; }

    //##ModelId=3F6193A8007C
    /*! \brief 设置控件能否得到焦点的标志
     *
     *  \param flag 控件能否得到焦点的标志
     */
    void SetCanGetFocus(const bool flag) { m_bCanGetFocus = flag; }

protected:
    //##ModelId=3F6193A703AF
    /*! \brief 该控件是否能得到焦点的标志设
     *  
     *  置了快捷键的控件不能得到焦点
     */
    bool m_bCanGetFocus;

    DECLARE_MESSAGE_MAP()
};

//##ModelId=3FD884F403BC
/*! \brief 判断一个控件能否得到焦点的检查类
 *
 *  用于迭代器查找窗口中能得到焦点的的控件
 */
class FG_CheckCanGetFocus : public FG_ListCheck<FG_Object>
{
public:
    //##ModelId=3FD884F60089
    /*! \brief 检查对象是否满足条件
     *
     *  通过比较控件是否能得到焦点来判断控件是否满足条件
     *  \param pObj 要检查的控件
     *  \return 是否满足条件\n
     *          true    满足条件\n
     *          false   不满足条件
     */
    virtual bool FindIt(const FG_Object * pObj)
    {
        return ((FG_Widget *)pObj)->CanGetFocus();
    }
};

#endif /* FG_WIDGET_H_HEADER_INCLUDED_C0A7936B */

/*! @} */

