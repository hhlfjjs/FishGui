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
/*! \addtogroup MVC_Application
 *  @{ 
 */

/*! \file
 *  \brief 用户定义的主窗口类的实现文件
 */

/*! @} */

#include <stdio.h>
#include <string.h>
#include "../../Source/OSAdaptor/FG_OSAdaptor.h"
#include "MyFactory.h"
#include "MainWindow.h"
#include "MyModel.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
BEGIN_MESSAGE_MAP(MainWindow, FG_Window)
    ON_UPDATE_VIEW  (MainWindow::OnViewUpdate)
END_MESSAGE_MAP()

/*! \addtogroup MVC_Application
 *  @{ 
 */

    /*! \addtogroup MainWindow_Rect 主窗口用到的矩形区域定义
     *  @{ 
     */
static const FG_Rect RECT_MainWindow(50, 50, 500, 550);

static const FG_Rect RECT_View(145, 100, 403, 372);

static const FG_Rect RECT_Label1(70, 390, 130, 410);
static const FG_Rect RECT_Label2(70, 420, 130, 440);
static const FG_Rect RECT_Display1(135, 390, 480, 410);
static const FG_Rect RECT_Display2(135, 420, 480, 440);

static const FG_Rect RECT_Label3(100, 450, 210, 470);
static const FG_Rect RECT_Label4(100, 480, 210, 500);
static const FG_Rect RECT_Display3(220, 450, 400, 470);
static const FG_Rect RECT_Display4(220, 480, 400, 500);
    /*! @} */

/*! @} */

MainWindow::MainWindow(WORD wID) : FG_Window("主窗口", wID, FS_RAISED)
{
    m_Rect.Set(RECT_MainWindow.wLeft, RECT_MainWindow.wTop, RECT_MainWindow.wRight, RECT_MainWindow.wBottom);

    MyFactory * pF = (MyFactory *)FG_GetFactory();
    MyView * pView;
    AddWidget(pView = pF->CreateMyView(RECT_View));

    AddWidget(pF->CreateLabel("数据1：", RECT_Label1));
    AddWidget(pF->CreateLabel("数据2：", RECT_Label2));
    FG_Label * pLabel;
    AddWidget(pLabel = pF->CreateLabel("000,000,000,000,000,000,000,000,000,000", RECT_Display1, ID_DISPLAY1, FS_RECESSED | TS_LEFT));
    pLabel->BGColor(COLOR_WHITE);
    AddWidget(pLabel = pF->CreateLabel("000,000,000,000,000,000,000,000,000,000", RECT_Display2, ID_DISPLAY2, FS_RECESSED | TS_LEFT));
    pLabel->BGColor(COLOR_WHITE);

    AddWidget(pF->CreateLabel("数据1的平均值：", RECT_Label3));
    AddWidget(pF->CreateLabel("数据2的平均值：", RECT_Label4));
    AddWidget(pLabel = pF->CreateLabel("0.0", RECT_Display3, ID_DISPLAY3, FS_RECESSED | TS_CENTER));
    pLabel->BGColor(COLOR_WHITE);
    AddWidget(pLabel = pF->CreateLabel("0.0", RECT_Display4, ID_DISPLAY4, FS_RECESSED | TS_CENTER));
    pLabel->BGColor(COLOR_WHITE);

    GetMyModel()->RegisterView(pView);
    GetMyModel()->RegisterView(this);
}

void MainWindow::OnViewUpdate(void)
{
    char buf[41];
    double avg_d1 = 0, avg_d2 = 0;

    strcpy(buf, "");
    int i;
    for (i = 0; i < 10; i ++)
    {
        unsigned char data = GetMyModel()->GetData1(i);
        avg_d1 += data;
        char tmp[5];
        sprintf(tmp, "%03d,", data);
        strcat(buf, tmp);
    }
    buf[strlen(buf) - 1] = 0;
    FG_Label * pDisplay1 = (FG_Label *)GetChild(ID_DISPLAY1);
    pDisplay1->SetText(buf);

    avg_d1 /= 10;
    sprintf(buf, "%.02f", avg_d1);
    FG_Label * pDisplay3 = (FG_Label *)GetChild(ID_DISPLAY3);
    pDisplay3->SetText(buf);

    strcpy(buf, "");
    for (i = 0; i < 10; i ++)
    {
        unsigned char data = GetMyModel()->GetData2(i);
        avg_d2 += data;
        char tmp[5];
        sprintf(tmp, "%03d,", data);
        strcat(buf, tmp);
    }
    buf[strlen(buf) - 1] = 0;
    FG_Label * pDisplay2 = (FG_Label *)GetChild(ID_DISPLAY2);
    pDisplay2->SetText(buf);

    avg_d2 /= 10;
    sprintf(buf, "%.02f", avg_d2);
    FG_Label * pDisplay4 = (FG_Label *)GetChild(ID_DISPLAY4);
    pDisplay4->SetText(buf);
}

