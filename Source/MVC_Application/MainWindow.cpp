/*--------------------------------------------------------------------------

	MainWindow.cpp - �û���������������ʵ���ļ�

	��������FishGUI�����һ����

	��Ȩ���� (C) 2003,2004 ��ӽ��
	http://www.contextfree.net/wangyw/

----------------------------------------------------------------------------

	���߶� FishGUI �����������Դ������Ȩ���£�

	�����κθ��ˡ���֯����������ҵ�޳���á��޸ġ�ʹ�á����·��� FishGUI ��
	������Դ���룬�����г������޳��ķ�ʽ���л��� FishGUI Դ�����ȫ����
	�����ݿ����������Ʒ����������ʹ����Ȩ��ʱ������������Լ����

	1�����·��� FishGUI �������Դ����ʱ��������ȥ�������Դ������ԭ�еİ�
	   Ȩ��Ϣ�Ϳ����߱�ʶ��

	2�����л��� FishGUI Դ�����ȫ���򲿷����ݿ����������Ʒʱ�������ڲ�Ʒ
	   ������λ�ñ�������������

	   ������Ʒ��һ���ֹ����ǻ�����ӽ���� FishGUI ����еĹ�����ɵġ�

	3������ʽ������������ FishGUI ���ĵ���Դ�����ע�����ݵģ�Ӧע�������
	   ԭ����Ϊ��ӽ�䡣

--------------------------------------------------------------------------*/
/*! \addtogroup MVC_Application
 *  @{ 
 */

/*! \file
 *  \brief �û���������������ʵ���ļ�
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

    /*! \addtogroup MainWindow_Rect �������õ��ľ���������
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

MainWindow::MainWindow(WORD wID) : FG_Window("������", wID, FS_RAISED)
{
    m_Rect.Set(RECT_MainWindow.wLeft, RECT_MainWindow.wTop, RECT_MainWindow.wRight, RECT_MainWindow.wBottom);

    MyFactory * pF = (MyFactory *)FG_GetFactory();
    MyView * pView;
    AddWidget(pView = pF->CreateMyView(RECT_View));

    AddWidget(pF->CreateLabel("����1��", RECT_Label1));
    AddWidget(pF->CreateLabel("����2��", RECT_Label2));
    FG_Label * pLabel;
    AddWidget(pLabel = pF->CreateLabel("000,000,000,000,000,000,000,000,000,000", RECT_Display1, ID_DISPLAY1, FS_RECESSED | TS_LEFT));
    pLabel->BGColor(COLOR_WHITE);
    AddWidget(pLabel = pF->CreateLabel("000,000,000,000,000,000,000,000,000,000", RECT_Display2, ID_DISPLAY2, FS_RECESSED | TS_LEFT));
    pLabel->BGColor(COLOR_WHITE);

    AddWidget(pF->CreateLabel("����1��ƽ��ֵ��", RECT_Label3));
    AddWidget(pF->CreateLabel("����2��ƽ��ֵ��", RECT_Label4));
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

