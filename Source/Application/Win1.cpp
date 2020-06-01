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
/*! \addtogroup Application
 *  @{ 
 */

/*! \file
 *  \brief �û�����Ĵ���1���ʵ���ļ�
 */

/*! @} */

#include <stdio.h>
#include <string.h>
#include "Win1.h"
#include "Win2.h"

BEGIN_MESSAGE_MAP(Win1, FG_Window)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_START, Win1::OnStart)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_STOP, Win1::OnStop)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_OPEN, Win1::OnOpen)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_CLOSE, Win1::OnClose)
    ON_TIMER        (ID_ANIMATION_TIMER, Win1::OnTimer)
END_MESSAGE_MAP()

/*! \addtogroup Application
 *  @{ 
 */

    /*! \addtogroup Win1_Rect ����1�õ��ľ���������
     *  @{ 
     */
static const FG_Rect RECT_Win1(150, 180, 445, 460);

static const FG_Rect RECT_Group1(165, 210, 430, 400);
static const FG_Rect RECT_Bitmap(235, 229, 356, 350);
static const FG_Rect RECT_Start(205, 360, 285, 385);
static const FG_Rect RECT_Stop(305, 360, 385, 385);

static const FG_Rect RECT_Open(175, 415, 285, 440);
static const FG_Rect RECT_Close(305, 415, 425, 440);
    /*! @} */

/*! @} */

//##ModelId=3F71AB0400CA
Win1::Win1(WORD wID) : m_iBmpNum(0), m_bStart(false), FG_Window("����1", wID, FS_RAISED)
{
    m_Rect.Set(RECT_Win1.wLeft, RECT_Win1.wTop, RECT_Win1.wRight, RECT_Win1.wBottom);

    FG_Factory * pF = FG_GetFactory();
    AddWidget(pF->CreateGroup("����2", RECT_Group1));
    AddWidget(pF->CreateBitmap("UnderSea", RECT_Bitmap, ID_BITMAP, FS_THIN));
    AddWidget(pF->CreateButton("���� [S]", RECT_Start, ID_START));
    AddWidget(pF->CreateButton("ֹͣ [T]", RECT_Stop, ID_STOP));

    AddWidget(pF->CreateButton("�򿪴���2 [O]", RECT_Open, ID_OPEN));
    AddWidget(pF->CreateButton("�ر� [C]", RECT_Close, ID_CLOSE));

    RegisterKey('S', FVK_ENTER, ID_START);
    RegisterKey('T', FVK_ENTER, ID_STOP);
    RegisterKey('O', FVK_ENTER, ID_OPEN);
    RegisterKey('C', FVK_ENTER, ID_CLOSE);
}

//##ModelId=3F71AB0400DE
void Win1::OnStart(void)
{
    if (! m_bStart)
    {
        StartTimer(ID_ANIMATION_TIMER, 500);
        m_bStart = true;
    }
}

//##ModelId=3F71AB0400E9
void Win1::OnStop(void)
{
    if (m_bStart)
    {
        KillTimer(ID_ANIMATION_TIMER);
        m_bStart = false;
    }
}

//##ModelId=3F71AB0400FD
void Win1::OnOpen(void)
{
    FG_GetScreen()->AddWindow(new Win2());
}

//##ModelId=3F71AB040110
void Win1::OnClose(void)
{
    FG_GetScreen()->RemoveWindow(this);
}

//##ModelId=3F71AB040124
void Win1::OnTimer(void)
{
    if (m_bStart)
    {
        if (++ m_iBmpNum >= 2)
            m_iBmpNum = 0;
        FG_Bitmap * pBitmap = (FG_Bitmap *)GetChild(ID_BITMAP);
        switch (m_iBmpNum)
        {
        case 0:
            pBitmap->SetText("UnderSea");
            break;
        case 1:
            pBitmap->SetText("UnderSea1");
            break;
        }
    }
}

