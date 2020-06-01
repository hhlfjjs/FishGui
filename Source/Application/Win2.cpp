/*--------------------------------------------------------------------------

	Win2.cpp - �û�����Ĵ���2���ʵ���ļ�

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
/*! \addtogroup Application
 *  @{ 
 */

/*! \file
 *  \brief �û�����Ĵ���2���ʵ���ļ�
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

    /*! \addtogroup Win2_Rect ����2�õ��ľ���������
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
Win2::Win2(WORD wID) : FG_Window("����2", wID, FS_RAISED)
{
    m_Rect.Set(RECT_Win2.wLeft, RECT_Win2.wTop, RECT_Win2.wRight, RECT_Win2.wBottom);

    FG_Factory * pF = FG_GetFactory();
    AddWidget(pF->CreateGroup("��3", RECT_Group1));
    FG_RadioButton * pRadio1 = pF->CreateRadioButton("100 [A]", RECT_Radio1, NULL, ID_RADIO1);
    pRadio1->SetChecked(true);
    AddWidget(pRadio1);
    AddWidget(pF->CreateRadioButton("200 [B]", RECT_Radio2, pRadio1, ID_RADIO2));
    AddWidget(pF->CreateRadioButton("300 [C]", RECT_Radio3, pRadio1, ID_RADIO3));
    AddWidget(pF->CreateRadioButton("400 [D]", RECT_Radio4, pRadio1, ID_RADIO4));
    AddWidget(pF->CreateRadioButton("500 [E]", RECT_Radio5, pRadio1, ID_RADIO5));
    AddWidget(pF->CreateRadioButton("600 [F]", RECT_Radio6, pRadio1, ID_RADIO6));

    AddWidget(pF->CreateGroup("��4", RECT_Group2));
    AddWidget(pF->CreateCheckBox("ѡ��1", RECT_Check1));
    AddWidget(pF->CreateCheckBox("ѡ��2", RECT_Check2));
    AddWidget(pF->CreateCheckBox("ѡ��3", RECT_Check3));
    AddWidget(pF->CreateCheckBox("ѡ��4", RECT_Check4));
    AddWidget(pF->CreateCheckBox("ѡ��5", RECT_Check5));
    AddWidget(pF->CreateCheckBox("ѡ��6", RECT_Check6));

    AddWidget(pF->CreateButton("ȡ��", RECT_Cancel, ID_CANCEL));
    AddWidget(pF->CreateButton("ȷ��", RECT_OK, ID_OK));

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

