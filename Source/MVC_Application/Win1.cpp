/*--------------------------------------------------------------------------

	Win1.cpp - �û�����Ĵ���1���ʵ���ļ�

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
 *  \brief �û�����Ĵ���1���ʵ���ļ�
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

    /*! \addtogroup Win1_Rect ����1�õ��ľ���������
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

Win1::Win1(WORD wID) : m_bData1(true), m_bData2(false), FG_Window("Ӳ����Ϣģ�ⴰ��", wID, FS_RAISED)
{
    m_Rect.Set(RECT_Win1.wLeft, RECT_Win1.wTop, RECT_Win1.wRight, RECT_Win1.wBottom);

    FG_Factory * pF = FG_GetFactory();
    AddWidget(pF->CreateLabel("����1��", RECT_Label1));
    AddWidget(pF->CreateLabel("����2��", RECT_Label2));
    FG_Label * pLabel;
    AddWidget(pLabel = pF->CreateLabel("0", RECT_Display1, ID_DISPLAY1, FS_RECESSED | TS_LEFT));
    pLabel->BGColor(COLOR_WHITE);
    AddWidget(pLabel = pF->CreateLabel("0", RECT_Display2, ID_DISPLAY2, FS_RECESSED | TS_LEFT));
    pLabel->BGColor(COLOR_WHITE);

    FG_CheckBox * pCheck;
    AddWidget(pCheck = pF->CreateCheckBox("��������1 [1]", RECT_Check1, ID_CHECK1));
    AddWidget(pF->CreateCheckBox("��������2 [2]", RECT_Check2, ID_CHECK2));
    pCheck->SetChecked(true);

    AddWidget(pF->CreateButton("���ݵ���", RECT_Button, ID_BUTTON));

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

