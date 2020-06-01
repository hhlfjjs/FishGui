/*--------------------------------------------------------------------------

	MainWindow.h - 用户定义的主窗口类的头文件

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
 *  \brief 用户定义的主窗口类的头文件
 */

#ifndef MAINWINDOW_H_HEADER_INCLUDED_C0A87F67
#define MAINWINDOW_H_HEADER_INCLUDED_C0A87F67

#include "../Framework/FG_Framework.h"

//##ModelId=3F49CE36016D
/*! \brief 用户定义的主窗口类
 */
class MainWindow : public FG_Window
{
public:
    //##ModelId=3F6EAC940107
    /*! \brief 主窗口上的控件ID
     */
    enum 
    { 
        ID_RADIO1 = 1,
        ID_RADIO2,
        ID_RADIO3,
        ID_RADIO4,
        ID_RADIO5,
        ID_RADIO6,
        ID_EDIT1,
        ID_CHECK1,
        ID_CHECK2,
        ID_EDIT2,
        ID_OPEN,
        ID_FACTORY,
        ID_START,
        ID_STOP,
        ID_BITMAP
    };

    //##ModelId=3F57F6DE01EE
    /*! \brief 主窗口的构造函数
     *  
     *  创建所有的控件，注册快捷键
     *  \param wID 主窗口的唯一标识，缺省为0
     */
    MainWindow(WORD wID = 0);

protected:
    //##ModelId=3F71AB03019B
    /*! \brief 主窗口上的动画1控件的定时器ID
     */
    enum
    {
        ID_ANIMATION_TIMER = 1
    };

    //##ModelId=3F6EAC940143
    /*! \brief 收音机按钮选中通知消息的处理函数
     */
    void OnRadioChecked(FG_Message * pMsg);

    //##ModelId=3F6EAC940157
    /*! \brief 选择按钮选中或取消选中通知消息的处理函数
     */
    void OnCheckChanged(FG_Message * pMsg);

    //##ModelId=3F71AB030245
    /*! \brief “启动”按钮通知消息的处理函数
     */
    void OnStart(void);

    //##ModelId=3F71AB030277
    /*! \brief “停止”按钮通知消息的处理函数
     */
    void OnStop(void);

    //##ModelId=3F71AB0302A9
    /*! \brief “打开窗口1”按钮通知消息的处理函数
     */
    void OnOpen(void);

    //##ModelId=3F71AB0302DB
    /*! \brief “圆角按钮”和“方角按钮”切换按钮通知消息的处理函数
     *
     *  切换当前使用的工厂类
     */
    void OnFactory(void);
    
    //##ModelId=3F71AB03030D
    /*! \brief 定时器（\ref ID_ANIMATION_TIMER）消息的处理函数
     *
     *  显示下一帧位图
     */
    void OnTimer(void);

    //##ModelId=3F71AB0301CD
    int m_iBmpNum;              /*!< \brief 当前显示的动画帧数 */
    //##ModelId=3F71AB0301EB
    bool m_bStart;              /*!< \brief 动画是否启动，true表示启动，false表示停止 */
    //##ModelId=3F71AB03021D
    bool m_bNewFactory;         /*!< \brief 当前使用的工厂类的标志，true表示使用用户定义的工厂类，false表示使用缺省工厂类 */

    DECLARE_MESSAGE_MAP()
};

#endif /* MAINWINDOW_H_HEADER_INCLUDED_C0A87F67 */

/*! @} */

