/*--------------------------------------------------------------------------

	FG_OSMsgObeserver.h - 操作系统消息的观察者接口的头文件

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
/*! \addtogroup Utility
 *  @{ 
 */

/*! \file
 *  \brief 操作系统消息的观察者接口的头文件
 *
*/

#ifndef FG_OSMSGOBSERVER_H_HEADER_INCLUDED_C0ADAC2E
#define FG_OSMSGOBSERVER_H_HEADER_INCLUDED_C0ADAC2E

//##ModelId=409260760103
/*! \brief 操作系统消息的观察者接口
 *
 *  实现了该接口的类可以从操作系统适配层接收操作系统消息
 */
class FG_OSMsgObserver
{
public:
    //##ModelId=409260760301
    /*! \brief 虚析构函数
     *
     */
    virtual ~FG_OSMsgObserver() {}

    //##ModelId=40926076030B
    /*! \brief 用于接收系统消息的接口
     *
     *  注册为操作系统的接收者的对象通过该接口来接收系统消息
     */
    virtual void OSMessage(FG_Message * pMsg) = 0;
};

#endif /* FG_OSMSGOBSERVER_H_HEADER_INCLUDED_C0ADAC2E */

/*! @} */

