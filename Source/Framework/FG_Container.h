/*--------------------------------------------------------------------------

	FG_Container.h - 窗口元素容器类的头文件

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
 *  \brief 窗口元素容器类的头文件
 *
*/

#ifndef FG_CONTAINER_H_HEADER_INCLUDED_C0AD6615
#define FG_CONTAINER_H_HEADER_INCLUDED_C0AD6615

#include "../Utility/FG_Utility.h"
#include "FG_Object.h"

//##ModelId=3F52B6A10055
/*! \brief 窗口元素容器类
 *
 *  该类的派生类可以容纳其他的窗口元素，屏幕和窗口都是该类的派生类。
 *  通过\ref FG_BList保存其他的窗口元素（\ref FG_Object）指针
 */
class FG_Container : public FG_Object
{
public:
    //##ModelId=3F56008E01F9
    /*! \brief 容器类的构造函数
     *
     *  \param Rect 容器类占据的矩形区域
     *  \param wID 容器类的唯一标识，缺省为0
     *  \param wStyle 容器类的\ref Style，缺省为\ref FS_NONE
     */
    FG_Container(const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE)
        : FG_Object(Rect, wID, wStyle)
        {}

    //##ModelId=3F583820002D
    /*! \brief 容器类的构造函数，可以作为缺省构造函数使用
     *
     *  \param wID 容器类的唯一标识，缺省为0
     *  \param wStyle 容器类的\ref Style，缺省为\ref FS_NONE
     *  \return  
     */
    FG_Container(const WORD wID = 0, const WORD wStyle = FS_NONE) 
        : FG_Object(wID, wStyle) {}

    //##ModelId=40925CC101B2
    /*! \brief 容器类的析构函数
     *
     *  删除所有的子窗口元素
     */
    ~FG_Container() { RemoveAllChild(); }

    //##ModelId=3F6EAC8F0056
    /*! \brief 得到标识为wID的子窗口元素的指针
     *
     *  \param wID 要查找的子窗口元素的唯一标识
     *  \return 找到的子窗口元素的指针，\ref NULL表示未找到
     */
    FG_Object * GetChild(const WORD wID) const;

protected:
    //##ModelId=3F56008E020D
    /*! \brief 添加一个子窗口元素
     *
     *  该方法为保护方法，客户不能直接调用，屏幕类和窗口类中会添加两个新的方法给客户程序使用。\n
     *  添加子窗口元素是要设置指向父窗口的指针
     *  \param pChild 要添加的子窗口元素的指针
     *  \return bool 添加操作是否成功\n
     *               true   成功\n
     *               false  失败
     */
    bool AddChild(FG_Object * const pChild);

    //##ModelId=3F56008E0235
    /*! \brief 删除一个子窗口元素
     *
     *  \param pChild 要删除的子窗口元素的指针
     *  \return bool 删除操作是否成功\n
     *               true   成功\n
     *               false  失败
     */
    bool RemoveChild(FG_Object * const pChild);

    //##ModelId=3F56008E025D
    /*! \brief 删除所有的子窗口元素
     */
    bool RemoveAllChild();

    //##ModelId=3F5DD96500A3
    typedef FG_BList<FG_Object> FG_OBJECTLIST;          /*!< \brief 容纳子窗口元素的双向链表容器类（\ref FG_BList） */

    //##ModelId=3F5DD965025D
    FG_OBJECTLIST m_ObjectList;                         /*!< \brief 容纳子窗口元素的双向链表容器对象 */

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_CONTAINER_H_HEADER_INCLUDED_C0AD6615 */

/* @} */

