/*--------------------------------------------------------------------------

	FG_Container.cpp - 窗口元素容器类的实现文件

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
 *  \brief 窗口元素容器类的实现文件
 *
*/

/*! @} */

#include "FG_Container.h"

BEGIN_MESSAGE_MAP(FG_Container, FG_Object)
END_MESSAGE_MAP()

//##ModelId=3F6EAC8F0056
FG_Object * FG_Container::GetChild(const WORD wID) const
{
    FG_OBJECTLIST::forward_iterator i = m_ObjectList.First();
    FG_CheckObjectID check(wID);

    if (FG_ListFind_If(i, check))
        return i;
    else
        return NULL;
}

//##ModelId=3F56008E020D
bool FG_Container::AddChild(FG_Object * const pChild)
{
    // 添加子窗口元素是要设置指向父窗口的指针
    pChild->Parent(this);
    m_ObjectList.Add(pChild);
    return true;
}

//##ModelId=3F56008E0235
bool FG_Container::RemoveChild(FG_Object * const pChild)
{
    bool ret = m_ObjectList.Remove(pChild);
    delete pChild;
    return ret;
}

//##ModelId=3F56008E025D
bool FG_Container::RemoveAllChild(void)
{
    FG_OBJECTLIST::forward_iterator i;
    for (i = m_ObjectList.First(); ! i.IsDone(); ++ i)
        delete i;
    m_ObjectList.RemoveAll();
    return true;
}

