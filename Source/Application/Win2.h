/*--------------------------------------------------------------------------

	Win2.h - 用户定义的窗口2类的头文件

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
 *  \brief 用户定义的窗口2类的头文件
 */

#ifndef WIN2_H_HEADER_INCLUDED_C0A87F67
#define WIN2_H_HEADER_INCLUDED_C0A87F67

#include "../Framework/FG_Framework.h"

//##ModelId=3F71AB020366
/*! \brief 用户定义的窗口2类
 */
class Win2 : public FG_Window
{
public:
    //##ModelId=3F71AB040142
    /*! \brief 窗口2上的控件ID
     */
    enum
    {
        ID_RADIO1 = 1,
        ID_RADIO2,
        ID_RADIO3,
        ID_RADIO4,
        ID_RADIO5,
        ID_RADIO6,
        ID_OK,
        ID_CANCEL
    };

    //##ModelId=3F71AB0401CE
    /*! \brief 窗口2的构造函数
     *  
     *  创建所有的控件，注册快捷键
     *  \param wID 窗口2的唯一标识，缺省为0
     */
    Win2(WORD wID = 0);

protected:
    //##ModelId=3F71AB0401D8
    /*! \brief “确定”按钮按下通知消息（\ref FBN_PRESSED，\ref ID_OK）的处理函数
     */
    void OnOK(void);

    //##ModelId=3F71AB0401EC
    /*! \brief “取消”按钮按下通知消息（\ref FBN_PRESSED，\ref ID_CANCEL）的处理函数
     */
    void OnCancel(void);

    DECLARE_MESSAGE_MAP()
};

#endif /* WIN2_H_HEADER_INCLUDED_C0A87F67 */

/*! @} */

