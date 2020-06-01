/*--------------------------------------------------------------------------

	Win1.h - 用户定义的窗口1类的头文件

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
 *  \brief 用户定义的窗口1类的头文件
 */

#ifndef WIN1_H_HEADER_INCLUDED_C0A87F67
#define WIN1_H_HEADER_INCLUDED_C0A87F67

#include "../Framework/FG_Framework.h"

//##ModelId=3F71AB020316
/*! \brief 用户定义的窗口1类
 */
class Win1 : public FG_Window
{
public:
    //##ModelId=3F71AB040016
    /*! \brief 窗口1上的控件ID
     */
    enum
    {
        ID_BITMAP = 1,
        ID_START,
        ID_STOP,
        ID_OPEN,
        ID_CLOSE
    };

    //##ModelId=3F71AB0400CA
    /*! \brief 窗口1的构造函数
     *  
     *  创建所有的控件，注册快捷键
     *  \param wID 窗口1的唯一标识，缺省为0
     */
    Win1(WORD wID = 0);

protected:
    //##ModelId=3F71AB040066
    /*! \brief 窗口1上的动画2控件的定时器ID
     */
    enum
    {
        ID_ANIMATION_TIMER = 1
    };

    //##ModelId=3F71AB0400DE
    /*! \brief “启动”按钮按下通知消息（\ref FBN_PRESSED，\ref ID_START）的处理函数
     */
    void OnStart(void);

    //##ModelId=3F71AB0400E9
    /*! \brief “停止”按钮按下通知消息（\ref FBN_PRESSED，\ref ID_STOP）的处理函数
     */
    void OnStop(void);

    //##ModelId=3F71AB0400FD
    /*! \brief “打开窗口2”按钮按下通知消息（\ref FBN_PRESSED，\ref ID_OPEN）的处理函数
     */
    void OnOpen(void);

    //##ModelId=3F71AB040110
    /*! \brief “关闭”按钮按下通知消息（\ref FBN_PRESSED，\ref ID_CLOSE）的处理函数
     */
    void OnClose(void);

    //##ModelId=3F71AB040124
    /*! \brief 定时器消息（\ref ID_ANIMATION_TIMER）的处理函数
     *
     *  显示下一帧位图
     */
    void OnTimer(void);

    //##ModelId=3F71AB0400A2
    int m_iBmpNum;              /*!< \brief 当前显示的动画帧数 */
    //##ModelId=3F71AB0400B6
    bool m_bStart;              /*!< \brief 动画是否启动，true表示启动，false表示停止 */

    DECLARE_MESSAGE_MAP()
};

#endif /* WIN1_H_HEADER_INCLUDED_C0A87F67 */

/*! @} */

