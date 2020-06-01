/*--------------------------------------------------------------------------

	Win1.cpp - 用户定义的窗口1类的实现文件

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
/*! \addtogroup MVC_Application
 *  @{ 
 */

/*! \file
 *  \brief 用户定义的窗口1类的实现文件
 */

/*! @} */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../Source/OSAdaptor/FG_OSAdaptor.h"
#include "Win1.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
BEGIN_MESSAGE_MAP(Win1, FG_Window)
    ON_ID_NOTIFY    (FCN_CHECKED, ID_CHECK1, Win1::OnCheck1Checked)
    ON_ID_NOTIFY    (FCN_CHECKED, ID_CHECK2, Win1::OnCheck2Checked)
    ON_ID_NOTIFY    (FCN_UNCHECKED, ID_CHECK1, Win1::OnCheck1Unchecked)
    ON_ID_NOTIFY    (FCN_UNCHECKED, ID_CHECK2, Win1::OnCheck2Unchecked)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_BUTTON, Win1::OnButtonPressed)
    ON_TIMER        (ID_TIMER, Win1::OnTimer)
    ON_UPDATE_VIEW  (Win1::OnViewUpdate)
END_MESSAGE_MAP()

/*! \addtogroup MVC_Application
 *  @{ 
 */

    /*! \addtogroup Win1_Rect 窗口1用到的矩形区域定义
     *  @{ 
     */
static const FG_Rect RECT_Win1(520, 180, 750, 390);

static const FG_Rect RECT_Label1(550, 220, 600, 240);
static const FG_Rect RECT_Label2(550, 250, 600, 270);
static const FG_Rect RECT_Display1(610, 220, 720, 240);
static const FG_Rect RECT_Display2(610, 250, 720, 270);
static const FG_Rect RECT_Check1(580, 280, 720, 300);
static const FG_Rect RECT_Check2(580, 310, 720, 330);
static const FG_Rect RECT_Button(565, 340, 705, 370);
    /*! @} */

/*! @} */

Win1::Win1(WORD wID) : m_bData1(true), m_bData2(false), FG_Window("硬件消息模拟窗口", wID, FS_RAISED)
{
    m_Rect.Set(RECT_Win1.wLeft, RECT_Win1.wTop, RECT_Win1.wRight, RECT_Win1.wBottom);

    FG_Factory * pF = FG_GetFactory();
    AddWidget(pF->CreateLabel("数据1：", RECT_Label1));
    AddWidget(pF->CreateLabel("数据2：", RECT_Label2));
    FG_Label * pLabel;
    AddWidget(pLabel = pF->CreateLabel("0", RECT_Display1, ID_DISPLAY1, FS_RECESSED | TS_LEFT));
    pLabel->BGColor(COLOR_WHITE);
    AddWidget(pLabel = pF->CreateLabel("0", RECT_Display2, ID_DISPLAY2, FS_RECESSED | TS_LEFT));
    pLabel->BGColor(COLOR_WHITE);

    FG_CheckBox * pCheck;
    AddWidget(pCheck = pF->CreateCheckBox("发送数据1 [1]", RECT_Check1, ID_CHECK1));
    AddWidget(pF->CreateCheckBox("发送数据2 [2]", RECT_Check2, ID_CHECK2));
    pCheck->SetChecked(true);

    AddWidget(pF->CreateButton("数据调整", RECT_Button, ID_BUTTON));

    RegisterKey('1', FVK_ENTER, ID_CHECK1);
    RegisterKey('2', FVK_ENTER, ID_CHECK2);

    srand((unsigned)time(NULL));
    StartTimer(ID_TIMER, 1000);

    GetMyModel()->RegisterView(this);
}

void Win1::OnTimer(void)
{
    if (m_bData1)
    {
        long data = rand();
        data %= 256;
        GetMyModel()->SendData1((unsigned char)data);
    }
    if (m_bData2)
    {
        long data = rand();
        data %= 256;
        GetMyModel()->SendData2((unsigned char)data);
    }
}

void Win1::OnViewUpdate(void)
{
    FG_Label * pDisplay1 = (FG_Label *)GetChild(ID_DISPLAY1);
    char buf[5];
    sprintf(buf, "%d", GetMyModel()->GetData1(0));
    pDisplay1->SetText(buf);

    FG_Label * pDisplay2 = (FG_Label *)GetChild(ID_DISPLAY2);
    sprintf(buf, "%d", GetMyModel()->GetData2(0));
    pDisplay2->SetText(buf);
}

