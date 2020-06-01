/*--------------------------------------------------------------------------

	MyFactory.h - 用户定义的工厂类的头文件

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
/*! \addtogroup Application
 *  @{ 
 */

/*! \file
 *  \brief 用户定义的工厂类的头文件
 */

#ifndef MYFACTORY_H_HEADER_INCLUDED_C0A7A9C0
#define MYFACTORY_H_HEADER_INCLUDED_C0A7A9C0

#include "../Framework/FG_Framework.h"
#include "MyButton.h"

//##ModelId=3F71AB0202EE
/*! \brief 用户定义的工厂类
 *
 *  覆盖\ref FG_Factory::CreateButton虚函数，改为创建圆角矩形控件的实例对象
 */
class MyFactory : public FG_Factory
{
public:
    //##ModelId=3F71AB0303C2
    FG_Button * CreateButton(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
    {
        return new MyButton(Text, Rect, wID);
    }
};

#endif /* MYFACTORY_H_HEADER_INCLUDED_C0A7A9C0 */

/*! @} */

