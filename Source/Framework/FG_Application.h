/*--------------------------------------------------------------------------

	FG_Application.h - 应用程序抽象类的头文件

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
 *  \brief 应用程序抽象类的头文件
 *
*/

#ifndef FG_APPLICATION_H_HEADER_INCLUDED_C0ADE4E6
#define FG_APPLICATION_H_HEADER_INCLUDED_C0ADE4E6

#include "../OSAdaptor/FG_OSAdaptor.h"

//##ModelId=3F49CDE90267
/*! \brief 应用程序抽象类
 *
 *  应用层应该定义该类的派生类，实现\ref FG_Application::InitApplication函数\n
 *  并且定义一个唯一的\ref theApp，来生成该类的唯一的实例对象
 */
class FG_Application : public FG_OSMsgObserver
{
public:
    //##ModelId=3F5218B803B6
    /*! \brief 构造函数
     *
     *  注册为\ref FG_MSG_STARTUP和\ref FG_MSG_HALT消息的观察者
     */
    FG_Application();
    //##ModelId=3F5218B9000B

    //##ModelId=3F521F4D03B9
    /*! \brief 实现操作系统消息的接收接口
     *
     *  - 对于\ref FG_MSG_STARTUP消息
     *    - 通过访问公共访问点，创建\ref FG_Screen的唯一实例
     *    - 通过访问公共访问点，创建\ref FG_TimerManager的唯一实例
     *    - 调用模板方法\ref InitApplication
     *  - 对于\ref FG_MSG_HALT消息
     *    - 删除\ref FG_Screen的唯一实例
     *    - 删除\ref FG_TimerManager的唯一实例
     *
     *  \param pMsg 发送给应用程序的系统消息
     */
    void OSMessage(FG_Message * pMsg);

    //##ModelId=3F52AB070145
    /*! \brief 初始化应用程序接口
     *
     *  该函数为模板方法，派生类必须实现该接口，执行应用程序的初始化工作，如创建主窗口等
     */
    virtual void InitApplication() = 0;
};

#endif /* FG_APPLICATION_H_HEADER_INCLUDED_C0ADE4E6 */

/*! @}*/

