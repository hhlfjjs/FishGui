/*--------------------------------------------------------------------------

	FG_TimerManager.cpp - 定时器管理器类的实现文件

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
/*! \addtogroup Framework
 *  @{ 
 */

/*! \file
 *  \brief 定时器管理器类的实现文件
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
    // 修改定时器的计数器
    m_dwCount -= 50;
    
    if (m_dwCount <= 0)
    {
        // 计数器到期
        m_dwCount = m_dwInterval;
        FG_Message Msg(FG_MSG_TIMER, m_TimerID);
        m_pTarget->Message(& Msg);
        // 发送消息给目标对象
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

