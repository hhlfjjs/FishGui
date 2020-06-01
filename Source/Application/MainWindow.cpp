/*--------------------------------------------------------------------------

	MainWindow.cpp - 用户定义的主窗口类的实现文件

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
 *  \brief 用户定义的主窗口类的实现文件
 */

/*! @} */

#include <stdio.h>
#include <string.h>
#include "../OSAdaptor/FG_OSAdaptor.h"
#include "MyFactory.h"
#include "MainWindow.h"
#include "Win1.h"

BEGIN_MESSAGE_MAP(MainWindow, FG_Window)
    ON_NOTIFY       (FRN_CHECKED, MainWindow::OnRadioChecked)
    ON_NOTIFY       (FCN_CHECKED, MainWindow::OnCheckChanged)
    ON_NOTIFY       (FCN_UNCHECKED, MainWindow::OnCheckChanged)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_START, MainWindow::OnStart)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_STOP, MainWindow::OnStop)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_OPEN, MainWindow::OnOpen)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_FACTORY, MainWindow::OnFactory)
    ON_TIMER        (ID_ANIMATION_TIMER, MainWindow::OnTimer)
END_MESSAGE_MAP()

/*! \addtogroup Application
 *  @{ 
 */

    /*! \addtogroup MainWindow_Rect 主窗口用到的矩形区域定义
     *  @{ 
     */
static const FG_Rect RECT_MainWindow(50, 50, 600, 400);

static const FG_Rect RECT_Group1(300, 80, 585, 200);
static const FG_Rect RECT_Radio1(320, 100, 400, 120);
static const FG_Rect RECT_Radio2(410, 100, 490, 120);
static const FG_Rect RECT_Radio3(500, 100, 580, 120);
static const FG_Rect RECT_Radio4(320, 125, 400, 145);
static const FG_Rect RECT_Radio5(410, 125, 490, 145);
static const FG_Rect RECT_Radio6(500, 125, 580, 145);
static const FG_Rect RECT_Label1(350, 160, 400, 180);
static const FG_Rect RECT_Edit1(450, 160, 560, 180);

static const FG_Rect RECT_Group2(300, 220, 585, 320);
static const FG_Rect RECT_Check1(340, 240, 430, 260);
static const FG_Rect RECT_Check2(450, 240, 540, 260);
static const FG_Rect RECT_Label2(350, 280, 400, 300);
static const FG_Rect RECT_Edit2(450, 280, 560, 300);

static const FG_Rect RECT_Open(320, 340, 445, 365);
static const FG_Rect RECT_Factory(460, 340, 570, 365);

static const FG_Rect RECT_Group3(65, 80, 285, 380);
static const FG_Rect RECT_Bitmap(102, 140, 248, 275);
static const FG_Rect RECT_Start(85, 315, 165, 340);
static const FG_Rect RECT_Stop(185, 315, 265, 340);
    /*! @} */

/*! @} */

//##ModelId=3F57F6DE01EE
MainWindow::MainWindow(WORD wID) : m_iBmpNum(0), m_bStart(false), m_bNewFactory(false), FG_Window("主窗口", wID, FS_RAISED)
{
    m_Rect.Set(RECT_MainWindow.wLeft, RECT_MainWindow.wTop, RECT_MainWindow.wRight, RECT_MainWindow.wBottom);

    FG_Factory * pF = FG_GetFactory();
    AddWidget(pF->CreateGroup("组1", RECT_Group1));
    FG_RadioButton * pRadio1 = pF->CreateRadioButton("100 [A]", RECT_Radio1, NULL, ID_RADIO1);
    pRadio1->SetChecked(true);
    AddWidget(pRadio1);
    AddWidget(pF->CreateRadioButton("200 [B]", RECT_Radio2, pRadio1, ID_RADIO2));
    AddWidget(pF->CreateRadioButton("300 [C]", RECT_Radio3, pRadio1, ID_RADIO3));
    AddWidget(pF->CreateRadioButton("400 [D]", RECT_Radio4, pRadio1, ID_RADIO4));
    AddWidget(pF->CreateRadioButton("500 [E]", RECT_Radio5, pRadio1, ID_RADIO5));
    AddWidget(pF->CreateRadioButton("600 [F]", RECT_Radio6, pRadio1, ID_RADIO6));
    AddWidget(pF->CreateLabel("编辑框1：", RECT_Label1));
    AddWidget(pF->CreateEdit("100", RECT_Edit1, 3, ID_EDIT1));

    AddWidget(pF->CreateGroup("组2", RECT_Group2));
    AddWidget(pF->CreateCheckBox("选择1 [G]", RECT_Check1, ID_CHECK1));
    AddWidget(pF->CreateCheckBox("选择2 [H]", RECT_Check2, ID_CHECK2));
    AddWidget(pF->CreateLabel("编辑框2：", RECT_Label2));

    AddWidget(pF->CreateButton("打开窗口1 [O]", RECT_Open, ID_OPEN));
    AddWidget(pF->CreateButton("圆角按钮 [Y]", RECT_Factory, ID_FACTORY));

    AddWidget(pF->CreateGroup("动画1", RECT_Group3));
    AddWidget(pF->CreateBitmap("baby30", RECT_Bitmap, ID_BITMAP, FS_RECESSED));
    AddWidget(pF->CreateButton("启动 [S]", RECT_Start, ID_START));
    AddWidget(pF->CreateButton("停止 [T]", RECT_Stop, ID_STOP));

    AddWidget(pF->CreateEdit("---", RECT_Edit2, 13, ID_EDIT2));

    RegisterKey('A', FVK_ENTER, ID_RADIO1);
    RegisterKey('B', FVK_ENTER, ID_RADIO2);
    RegisterKey('C', FVK_ENTER, ID_RADIO3);
    RegisterKey('D', FVK_ENTER, ID_RADIO4);
    RegisterKey('E', FVK_ENTER, ID_RADIO5);
    RegisterKey('F', FVK_ENTER, ID_RADIO6);
    RegisterKey('G', FVK_ENTER, ID_CHECK1);
    RegisterKey('H', FVK_ENTER, ID_CHECK2);
    RegisterKey('O', FVK_ENTER, ID_OPEN);
    RegisterKey('Y', FVK_ENTER, ID_FACTORY);
    RegisterKey('S', FVK_ENTER, ID_START);
    RegisterKey('T', FVK_ENTER, ID_STOP);
}

//##ModelId=3F6EAC940143
void MainWindow::OnRadioChecked(FG_Message * pMsg)
{
    char buf[4];
    sprintf(buf, "%d", (pMsg->wID - ID_RADIO1 + 1) * 100);

    FG_Edit * pEdit = (FG_Edit *)GetChild(ID_EDIT1);
    if (pEdit)
        pEdit->SetText(buf);
}

//##ModelId=3F6EAC940157
void MainWindow::OnCheckChanged(FG_Message * pMsg)
{
    FG_CheckBox * pCheck1 = (FG_CheckBox *)GetChild(ID_CHECK1);
    FG_CheckBox * pCheck2 = (FG_CheckBox *)GetChild(ID_CHECK2);

    if (pCheck1 && pCheck2)
    {
        char buf[14];
        strcpy(buf, "-");
        if (pCheck1->IsChecked())
            strcat(buf, "选择1");
        strcat(buf, "-");
        if (pCheck2->IsChecked())
            strcat(buf, "选择2");
        strcat(buf, "-");
        
        FG_Edit * pEdit = (FG_Edit *)GetChild(ID_EDIT2);
        if (pEdit)
            pEdit->SetText(buf);
    }
}

//##ModelId=3F71AB030245
void MainWindow::OnStart(void)
{
    if (! m_bStart)
    {
        StartTimer(ID_ANIMATION_TIMER, 200);
        m_bStart = true;
    }
}

//##ModelId=3F71AB030277
void MainWindow::OnStop(void)
{
    if (m_bStart)
    {
        KillTimer(ID_ANIMATION_TIMER);
        m_bStart = false;
    }
}

//##ModelId=3F71AB0302A9
void MainWindow::OnOpen(void)
{
    FG_GetScreen()->AddWindow(new Win1());
}

//##ModelId=3F71AB0302DB
void MainWindow::OnFactory(void)
{
    MainWindow * pWindow;

    if (m_bNewFactory)
    {
        FG_SetFactory(new FG_Factory());

        FG_GetScreen()->RemoveWindow(this);
        FG_GetScreen()->AddWindow(pWindow = new MainWindow());
        
        pWindow->m_bNewFactory = false;
    
        FG_Button * pButton = (FG_Button *)pWindow->GetChild(ID_FACTORY);
        if (pButton)
            pButton->SetText("圆角按钮 [Y]");
    }
    else
    {
        FG_SetFactory(new MyFactory());

        FG_GetScreen()->RemoveWindow(this);
        FG_GetScreen()->AddWindow(pWindow = new MainWindow());
        
        pWindow->m_bNewFactory = true;
    
        FG_Button * pButton = (FG_Button *)pWindow->GetChild(ID_FACTORY);
        if (pButton)
            pButton->SetText("方形按钮 [Y]");
    }
}

//##ModelId=3F71AB03030D
void MainWindow::OnTimer(void)
{
    if (m_bStart)
    {
        if (++ m_iBmpNum >= 3)
            m_iBmpNum = 0;
        FG_Bitmap * pBitmap = (FG_Bitmap *)GetChild(ID_BITMAP);
        switch (m_iBmpNum)
        {
        case 0:
            pBitmap->SetText("baby30");
            break;
        case 1:
            pBitmap->SetText("baby31");
            break;
        case 2:
            pBitmap->SetText("baby32");
            break;
        }
    }
}

