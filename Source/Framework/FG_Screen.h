/*--------------------------------------------------------------------------

	FG_Screen.h - 屏幕类的头文件

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
 *  \brief 屏幕类的头文件
 *
*/

#ifndef FG_SCREEN_H_HEADER_INCLUDED_C0AD5887
#define FG_SCREEN_H_HEADER_INCLUDED_C0AD5887

#include "../Utility/FG_Utility.h"
#include "../OSAdaptor/FG_OSAdaptor.h"
#include "FG_Window.h"

class FG_Factory;

//##ModelId=3F52B6B70300
/*! \brief 屏幕类
 *
 *  该类为单件类，代表物理屏幕设备，在屏幕上可以放置多个可相互覆盖的窗口
 */
class FG_Screen : public FG_Container, FG_OSMsgObserver
{
public:
    //##ModelId=3F57524C03BA
    /*! \brief 得到屏幕类的唯一实例对象的全局访问点函数
     *
     *  注册为\ref FG_MSG_DRAW、\ref FG_MSG_KEY和\ref FG_MSG_MOUSE消息的观察者
     *  \return 指向屏幕类的唯一实例对象的指针
     */
    static FG_Screen * GetScreen(void);

    //##ModelId=3F71AB1F0386
    /*! \brief 删除屏幕类的唯一实例对象
     */
    static void DeleteScreen(void);

    //##ModelId=3F57F111009E
    /*! \brief 在屏幕上添加一个窗口
     *
     *  代理调用\ref FG_Container::AddChild，需要发送焦点切换消息
     *  \param pWindow 要添加的窗口对象的指针
     *  \return 添加操作是否成功
     *          true    成功
     *          false   失败
     */
    bool AddWindow(FG_Window * pWindow);

    //##ModelId=3F57F1110120
    /*! \brief 从屏幕上删除一个窗口
     *
     *  代理调用\ref FG_Container::RemoveChild，需要发送焦点切换消息
     *  \param pWindow 要删除的窗口对象的指针
     *  \return 删除操作是否成功
     *          true    成功
     *          false   失败
     */
    bool RemoveWindow(FG_Window * pWindow);

    //##ModelId=3F57524C03C5
    void OSMessage(FG_Message * pMsg);

    //##ModelId=3F6EAC8F01AA
    /*! \brief 得到当前使用的工厂对象
     *
     *  \return 指向当前使用的工厂对象的指针
     */
    FG_Factory * GetFactory() const { return m_pFactory; }

    //##ModelId=3F6EAC8F01B4
    /*! \brief 设置当前使用的工厂对象
     *
     *  \param pFactory 要设置的工厂对象的指针
     */
    void SetFactory(FG_Factory * pFactory);

protected:
    //##ModelId=3F6193A70319
    /*! \brief 窗口发送的要求重画消息\ref FG_MSG_DRAW_REQUEST的处理函数
     *
     *  对于窗口对象发来的重画请求，并不直接重画，而是启动一个时间为\ref SCREEN_DRAW_INTERVAL（50毫秒）的定时器，
     *  定时器到期时才执行重画操作，该定时器在删除之前只能被成功一次，因此50 毫秒内的只会发生一次重画操作，
     *  提高了重画的效率，不会引起闪烁感
     *  \param pMsg 指向要求重画消息结构的指针
     */
    void OnDrawRequest(FG_Message * pMsg);

    //##ModelId=3F71AB1F03C2
    /*! \brief 用于减少重画次数的定时器消息（\ref TIMERID_DRAW）的处理函数
     *
     *  依次重画所有的窗口
     */
    void OnDrawTimer(void);

    //##ModelId=3F6193A70337
    /*! \brief 依次重画所有窗口
     *
     *  通过发送\ref FG_MSG_DRAW消息要求窗口重画自己
     */
    void DrawAllWindow();

    //##ModelId=3F57524D0036
    /*! \brief 屏幕类的构造函数，用户不能直接调用
     *
     *  \param Rect 屏幕占据的矩形区域，左上角坐标总是（0, 0），右下角坐标为（\ref SCREEN_WIDTH, \ref SCREEN_HEIGHT）
     */
    FG_Screen(const FG_Rect & Rect);

    //##ModelId=3F71AB20003E
    /*! \brief 析构函数，用户不能直接调用 */
    ~FG_Screen();

    //##ModelId=3F71ACB000E4
    FG_Factory * m_pFactory;            /*!< \brief 指向当前使用的工厂对象的指针 */

private:
    //##ModelId=3F71AB1F034A
    /*! \brief 定时器ID
     */
    enum 
    {
        TIMERID_DRAW = 0xff             /*!< \brief 用于减少重画次数的定时器ID */
    };

    //##ModelId=3F57524C0393
    static FG_Screen * m_pScreen;       /*!< \brief 指向唯一的屏幕类的实例对象的指针，用于实现单件类 */

    DECLARE_MESSAGE_MAP()
};

/*! \brief 封装屏幕类的全局访问点函数（\ref FG_Screen::GetScreen）的全局函数
 *
 *  \return 指向屏幕类的唯一实例对象的指针
 */
FG_Screen * FG_GetScreen();

/*! \brief 封装得到当前使用的工厂对象（\ref FG_Screen::GetFactory）的全局函数
 *
 *  \return 指向当前使用的工厂对象的指针
 */
FG_Factory * FG_GetFactory();

/*! \brief 封装设置当前使用的工厂对象（\ref FG_Screen::SetFactory）的全局函数
 *
 *  \param pFactory 要设置的工厂对象的指针
 */
void FG_SetFactory(FG_Factory * pFactory);

#endif /* FG_SCREEN_H_HEADER_INCLUDED_C0AD5887 */

/*! @} */

