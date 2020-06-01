/*--------------------------------------------------------------------------

	FG_Screen.cpp - ��Ļ���ʵ���ļ�

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
/*! \addtogroup Framework
 *  @{ 
 */

/*! \file
 *  \brief ��Ļ���ʵ���ļ�
 *
*/

/*! @} */

#include "FG_Screen.h"
#include "FG_Factory.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
BEGIN_MESSAGE_MAP(FG_Screen, FG_Container)
    ON_DRAWREQUEST  (FG_Screen::OnDrawRequest)
    ON_TIMER        (TIMERID_DRAW, FG_Screen::OnDrawTimer)
END_MESSAGE_MAP()

//##ModelId=3F57524C0393
FG_Screen * FG_Screen::m_pScreen = NULL;

FG_Screen * FG_GetScreen()
{
    return FG_Screen::GetScreen();
}

FG_Factory * FG_GetFactory()
{
    return FG_Screen::GetScreen()->GetFactory();
}

void FG_SetFactory(FG_Factory * pFactory)
{
    FG_Screen::GetScreen()->SetFactory(pFactory);
}

//##ModelId=3F57524C03BA
FG_Screen * FG_Screen::GetScreen()
{
    if (! m_pScreen)
    {
        FG_Rect rect(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
        m_pScreen = new FG_Screen(rect);
    }
    return m_pScreen;
}

void FG_Screen::SetFactory(FG_Factory * pFactory)
{ 
    // �ͷŴ�ǰ���õĹ�������
    if (m_pFactory)
        delete m_pFactory;
    m_pFactory = pFactory;
}

//##ModelId=3F71AB1F0386
void FG_Screen::DeleteScreen(void)
{
    if (m_pScreen)
        delete m_pScreen;
}

//##ModelId=3F57524D0036
FG_Screen::FG_Screen(const FG_Rect & Rect) : FG_Container(Rect, 0, FS_NONE)
{
    BGColor(COLOR_BLACK);

    m_pFactory = new FG_Factory();

    FG_GetAdaptor()->SetMsgObserver(FG_MSG_DRAW, this);
    FG_GetAdaptor()->SetMsgObserver(FG_MSG_KEY, this);
    FG_GetAdaptor()->SetMsgObserver(FG_MSG_MOUSE, this);
}

//##ModelId=3F71AB20003E
FG_Screen::~FG_Screen()
{
    if (m_pFactory)
        delete m_pFactory;
}

bool FG_Screen::AddWindow(FG_Window * pWindow)
{
    if (AddChild(pWindow))
    {
        FG_OBJECTLIST::back_iterator pLast = m_ObjectList.Last();
        pLast ++;
        FG_Message Msg(FG_MSG_FOCUS, FFS_LOSE);
        if (! 
            pLast.IsDone())
            pLast->Message(& Msg);

        Msg.wType = FG_MSG_FOCUS;
        Msg.wData = FFS_GET;
        pLast = m_ObjectList.Last();
        pLast->Message(& Msg);
        return true;
    }
    else
        return false;
}

bool FG_Screen::RemoveWindow(FG_Window * pWindow)
{
    FG_OBJECTLIST::back_iterator pLast = m_ObjectList.Last();
    if (RemoveChild(pWindow))
    {
        FG_OBJECTLIST::back_iterator pNewLast = m_ObjectList.Last();
        if (! pNewLast.IsDone() && pNewLast != pLast)
        {
            FG_Message Msg(FG_MSG_FOCUS, FFS_GET);
            pNewLast->Message(& Msg);
        }
        DrawAllWindow();
        return true;
    }
    else
        return false;
}

//##ModelId=3F57524C03C5
void FG_Screen::OSMessage(FG_Message * pMsg)
{
    switch (pMsg->wType)
    {
    case FG_MSG_DRAW:
        DrawAllWindow();
        break;
    case FG_MSG_KEY:
        m_ObjectList.Last()->Message(pMsg);
        break;
    case FG_MSG_MOUSE:
        {
            if (m_ObjectList.Last()->IsContains(pMsg->Point))
                m_ObjectList.Last()->Message(pMsg);
        }
        break;
    }
}

//##ModelId=3F6193A70319
void FG_Screen::OnDrawRequest(FG_Message * pMsg)
{
    // ���ڴ��ڶ��������ػ����󣬲���ֱ���ػ�����������һ��ʱ��Ϊ\ref SCREEN_DRAW_INTERVAL��50���룩�Ķ�ʱ����
    // ��ʱ������ʱ��ִ���ػ��������ö�ʱ����ɾ��֮ǰֻ�ܱ��ɹ�һ�Σ����50 ������ֻ�ᷢ��һ���ػ�������
    // ������ػ���Ч�ʣ�����������˸��
    StartTimer(TIMERID_DRAW, SCREEN_DRAW_INTERVAL);
}

//##ModelId=3F71AB1F03C2
void FG_Screen::OnDrawTimer(void)
{
    DrawAllWindow();
    KillTimer(TIMERID_DRAW);
}

//##ModelId=3F6193A70337
void FG_Screen::DrawAllWindow()
{
    FG_OSAdaptor * pAdaptor = FG_GetAdaptor();
    if (! pAdaptor)
        return;

    pAdaptor->BeginDraw(m_Rect);

    FG_Container::OnDraw(pAdaptor);

    FG_OBJECTLIST::forward_iterator i;
    for (i = m_ObjectList.First(); ! i.IsDone(); ++ i)
    {
        FG_Message Msg(FG_MSG_DRAW);
        i->Message(& Msg);
    }

    pAdaptor->EndDraw();
}

