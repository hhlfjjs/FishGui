/*--------------------------------------------------------------------------

	Win2.cpp - 用户定义的窗口2类的实现文件

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
 *  \brief 用户定义的窗口2类的实现文件
 */

/*! @} */

#include <stdio.h>
#include <string.h>
#include "Win2.h"

BEGIN_MESSAGE_MAP(Win2, FG_Window)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_OK, Win2::OnOK)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_CANCEL, Win2::OnCancel)
END_MESSAGE_MAP()

/*! \addtogroup Application
 *  @{ 
 */

    /*! \addtogroup Win2_Rect 窗口2用到的矩形区域定义
     *  @{ 
     */
static const FG_Rect RECT_Win2(60, 300, 420, 520);

static const FG_Rect RECT_Group1(72, 330, 200, 505);
static const FG_Rect RECT_Radio1(100, 350, 190, 370);
static const FG_Rect RECT_Radio2(100, 374, 190, 394);
static const FG_Rect RECT_Radio3(100, 398, 190, 418);
static const FG_Rect RECT_Radio4(100, 422, 190, 442);
static const FG_Rect RECT_Radio5(100, 446, 190, 466);
static const FG_Rect RECT_Radio6(100, 470, 190, 490);

static const FG_Rect RECT_Group2(210, 330, 330, 505);
static const FG_Rect RECT_Check1(230, 350, 320, 370);
static const FG_Rect RECT_Check2(230, 374, 320, 394);
static const FG_Rect RECT_Check3(230, 398, 320, 418);
static const FG_Rect RECT_Check4(230, 422, 320, 442);
static const FG_Rect RECT_Check5(230, 446, 320, 466);
static const FG_Rect RECT_Check6(230, 470, 320, 490);

static const FG_Rect RECT_OK(340, 330, 400, 355);
static const FG_Rect RECT_Cancel(340, 360, 400, 385);
    /*! @} */

/*! @} */

//##ModelId=3F71AB0401CE
Win2::Win2(WORD wID) : FG_Window("窗口2", wID, FS_RAISED)
{
    m_Rect.Set(RECT_Win2.wLeft, RECT_Win2.wTop, RECT_Win2.wRight, RECT_Win2.wBottom);

    FG_Factory * pF = FG_GetFactory();
    AddWidget(pF->CreateGroup("组3", RECT_Group1));
    FG_RadioButton * pRadio1 = pF->CreateRadioButton("100 [A]", RECT_Radio1, NULL, ID_RADIO1);
    pRadio1->SetChecked(true);
    AddWidget(pRadio1);
    AddWidget(pF->CreateRadioButton("200 [B]", RECT_Radio2, pRadio1, ID_RADIO2));
    AddWidget(pF->CreateRadioButton("300 [C]", RECT_Radio3, pRadio1, ID_RADIO3));
    AddWidget(pF->CreateRadioButton("400 [D]", RECT_Radio4, pRadio1, ID_RADIO4));
    AddWidget(pF->CreateRadioButton("500 [E]", RECT_Radio5, pRadio1, ID_RADIO5));
    AddWidget(pF->CreateRadioButton("600 [F]", RECT_Radio6, pRadio1, ID_RADIO6));

    AddWidget(pF->CreateGroup("组4", RECT_Group2));
    AddWidget(pF->CreateCheckBox("选择1", RECT_Check1));
    AddWidget(pF->CreateCheckBox("选择2", RECT_Check2));
    AddWidget(pF->CreateCheckBox("选择3", RECT_Check3));
    AddWidget(pF->CreateCheckBox("选择4", RECT_Check4));
    AddWidget(pF->CreateCheckBox("选择5", RECT_Check5));
    AddWidget(pF->CreateCheckBox("选择6", RECT_Check6));

    AddWidget(pF->CreateButton("取消", RECT_Cancel, ID_CANCEL));
    AddWidget(pF->CreateButton("确定", RECT_OK, ID_OK));

    RegisterKey('A', FVK_ENTER, ID_RADIO1);
    RegisterKey('B', FVK_ENTER, ID_RADIO2);
    RegisterKey('C', FVK_ENTER, ID_RADIO3);
    RegisterKey('D', FVK_ENTER, ID_RADIO4);
    RegisterKey('E', FVK_ENTER, ID_RADIO5);
    RegisterKey('F', FVK_ENTER, ID_RADIO6);
}

//##ModelId=3F71AB0401D8
void Win2::OnOK(void)
{
    FG_GetScreen()->RemoveWindow(this);
}

//##ModelId=3F71AB0401EC
void Win2::OnCancel(void)
{
    FG_GetScreen()->RemoveWindow(this);
}

