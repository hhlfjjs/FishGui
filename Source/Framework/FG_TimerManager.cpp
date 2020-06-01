/*--------------------------------------------------------------------------

	FG_TimerManager.cpp - ��ʱ�����������ʵ���ļ�

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
 *  \brief ��ʱ�����������ʵ���ļ�
 *
 */

/*! @} */

#include "FG_TimerManager.h"
#include "FG_Object.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
FG_TimerManager * FG_GetTimerManager(void)
{
    return FG_TimerManager::GetTimerManager();
}

//##ModelId=40BB6F970366
void FG_Timer::Tick(void)
{
    // �޸Ķ�ʱ���ļ�����
    m_dwCount -= 50;
    
    if (m_dwCount <= 0)
    {
        // ����������
        m_dwCount = m_dwInterval;
        FG_Message Msg(FG_MSG_TIMER, m_TimerID);
        m_pTarget->Message(& Msg);
        // ������Ϣ��Ŀ�����
    }
}

//##ModelId=3F5C57A2039C
FG_TimerManager * FG_TimerManager::m_pTimerManager = NULL;

//##ModelId=3F5C57A203B7
FG_TimerManager * FG_TimerManager::GetTimerManager(void)
{
    if (! m_pTimerManager)
    {
        m_pTimerManager = new FG_TimerManager();
    }
    return m_pTimerManager;
}

//##ModelId=3F71AB2000E8
void FG_TimerManager::DeleteTimerManager(void)
{
    if (m_pTimerManager)
        delete m_pTimerManager;
}

FG_TimerManager::FG_TimerManager()
{
    FG_GetAdaptor()->SetMsgObserver(FG_MSG_TIMER, this);
}

bool FG_TimerManager::StartTimer(FG_Object * pTarget, BYTE timerID, DWORD dwInterval)
{
    FG_TIMERLIST::iterator i = m_TimerList.First();
    FG_CheckTimer check(pTarget, timerID);
    
    if (FG_ListFind_If(i, check))
        return false;

    FG_Timer * pTimer = new FG_Timer(pTarget, timerID, dwInterval);
    if (! pTimer)
        return false;
    m_TimerList.Add(pTimer);
    return true;
}

//##ModelId=3F5DAA150033
bool FG_TimerManager::KillTimer(FG_Object * pTarget, BYTE timerID)
{
    FG_TIMERLIST::iterator i = m_TimerList.First();
    FG_CheckTimer check(pTarget, timerID);
    
    if (FG_ListFind_If(i, check))
    {
        delete i;
        m_TimerList.Remove(i);
        return true;
    }
    else
        return false;
}

//##ModelId=3F71AB20011A
bool FG_TimerManager::KillObjectTimer(FG_Object * pTarget)
{
    FG_TIMERLIST::iterator i, j;
    for (i = m_TimerList.First(); ! i.IsDone(); i = j)
    {
        j = i;
        ++ j;
        if (i->m_pTarget == pTarget)
        {
            delete i;
            m_TimerList.Remove(i);
        }
    }
    return true;
}

//##ModelId=3F71AB20014C
bool FG_TimerManager::IsTimerStart(FG_Object * pTarget, BYTE timerID)
{
    FG_TIMERLIST::iterator i = m_TimerList.First();
    FG_CheckTimer check(pTarget, timerID);
    
    if (FG_ListFind_If(i, check))
            return true;
    else
        return false;
}

//##ModelId=3F5DAA150051
bool FG_TimerManager::KillAllTimer()
{
    FG_TIMERLIST::iterator i;
    for (i = m_TimerList.First(); ! i.IsDone(); ++ i)
        delete i;
    m_TimerList.RemoveAll();
    return true;
}

//##ModelId=3F5C57A30138
void FG_TimerManager::OSMessage(FG_Message * pMsg)
{
    FG_TIMERLIST::iterator i, j;
    for (i = m_TimerList.First(); ! i.IsDone(); i = j)
    {	
        j = i;
        ++ j;
        i->Tick();
    }
}

