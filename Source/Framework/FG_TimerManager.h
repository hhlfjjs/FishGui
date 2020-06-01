/*--------------------------------------------------------------------------

	FG_TimerManager.h - 定时器管理器类的头文件

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
 *  \brief 定时器管理器类的头文件
 *
 */

#ifndef FG_TIMERMANAGER_H_HEADER_INCLUDED_C0A3F06D
#define FG_TIMERMANAGER_H_HEADER_INCLUDED_C0A3F06D

#include "../Utility/FG_Utility.h"
#include "../OSAdaptor/FG_OSAdaptor.h"
class FG_Object;

//##ModelId=3FD884F5022C
/*! \brief 定时器类
 *
 *  管理定时器的标识、到期时间、申请该定时器的窗口元素等信息
 */
class FG_Timer
{
public:
    //##ModelId=3FD884F70347
    /*! \brief 构造函数
     *
     *  \param pTarget 申请定时器的窗口元素
     *  \param timerID 定时器的唯一标识
     *  \param dwInterval 定时器的到期时间
     */
    FG_Timer(FG_Object * pTarget, BYTE timerID, DWORD dwInterval) 
        : m_TimerID(timerID), m_dwInterval(dwInterval), m_dwCount(dwInterval),
        m_pTarget(pTarget)
        {}

    /*! \brief 定时器嘀嗒处理函数
     *
     *  检查该定时器是否到期，如果到期，发送定时器消息给对应的窗口元素
     */
    //##ModelId=40BB6F970366
    void Tick(void);

    //##ModelId=3FD884F702E4
    BYTE        m_TimerID;          /*!< 定时器的唯一标识（对于同一个窗口元素唯一） */
    //##ModelId=3FD884F702F8
    DWORD       m_dwInterval;       /*!< 定时器的到期时间（单位：毫秒） */
    //##ModelId=3FD884F70316
    DWORD       m_dwCount;          /*!< 当前计数器 */
    //##ModelId=3FD884F7032A
    FG_Object * m_pTarget;          /*!< 申请定时器的窗口元素，定时器到期消息会被发送给该窗口元素 */
};

//##ModelId=3F5C4ED700C1
/*! \brief 定时器管理器类
 *
 *  管理系统中的所有定时器，单件类。
 */
class FG_TimerManager : public FG_OSMsgObserver
{
public:
    //##ModelId=3F5C57A203B7
    /*! \brief 得到定时器管理器的唯一实例对象的全局访问点函数
     *
     *  \return 指向定时器管理器的唯一实例对象的指针
     */
    static FG_TimerManager * GetTimerManager(void);

    //##ModelId=3F71AB2000E8
    /*! \brief 删除定时器管理器的唯一实例对象
     */
    static void DeleteTimerManager(void);

    //##ModelId=3F5C57A30001
    bool StartTimer(FG_Object * pTarget, BYTE timerID, DWORD dwInterval);
    //##ModelId=3F5DAA150033
    bool KillTimer(FG_Object * pTarget, BYTE timerID);
    //##ModelId=3F71AB20011A
    bool KillObjectTimer(FG_Object * pTarget);
    //##ModelId=3F71AB20014C
    bool IsTimerStart(FG_Object * pTarget, BYTE timerID);
    //##ModelId=3F5DAA150051
    bool KillAllTimer();

    //##ModelId=3F5C57A30138
    void OSMessage(FG_Message * pMsg);

protected:
    //##ModelId=3F5C57A3028C
    /*! \brief 构造函数
     *
     *  用户不能直接访问
     */
    FG_TimerManager();

    //##ModelId=3F71AB20019C
    /*! \brief 析构函数
     *
     *  用户不能直接访问，删除所有的定时器
     */
    ~FG_TimerManager() { KillAllTimer(); }

private:
    //##ModelId=3F5DD9650193
    typedef FG_SList<FG_Timer> FG_TIMERLIST;    /*!< 保存定时器的容器类型 */

    //##ModelId=3F5DD9660087
    FG_TIMERLIST m_TimerList;                   /*!< 保存定时器的容器变量 */

    //##ModelId=3F5C57A2039C
    static FG_TimerManager * m_pTimerManager;   /*!< 指向唯一的定时器管理器实例对象的指针 */
};

/*! \brief 封装定时器管理器的全局访问点\ref FG_TimerManager::GetTimerManager的全局函数
 *
 *  \return 指向唯一的定时器管理器的指针
 */
FG_TimerManager * FG_GetTimerManager(void);

//##ModelId=3FD884F5002D
/*! \brief 查找定时器的检查类
 *
 *  用于迭代器查找定时器管理其中的所有定时器
 */
class FG_CheckTimer : public FG_ListCheck<FG_Timer>
{
public:
    //##ModelId=3FD884F60165
    /*! \brief 定时器的检查类的构造函数
     *
     *  \param pObject 申请定时器的目标窗口元素
     *  \param timerID 定时器ID
     */
    FG_CheckTimer(FG_Object * pObject, BYTE timerID) : m_pTarget(pObject), m_TimerID(timerID) {}

    //##ModelId=3FD884F60183
    /*! \brief 检查对象是否满足条件
     *
     *  通过比较定时器的ID和目标窗口元素来决定该定时器是否满足条件
     *  \param pTimer 要检查的定时器
     *  \return 是否满足条件\n
     *          true    满足条件\n
     *          false   不满足条件
     */
    virtual bool FindIt(const FG_Timer * pTimer) { return (pTimer->m_pTarget == m_pTarget && pTimer->m_TimerID == m_TimerID); }

private:
    //##ModelId=3FD884F60134
    FG_Object * m_pTarget;          /*!< \brief 申请定时器的目标窗口元素 */
    //##ModelId=3FD884F60152
    BYTE        m_TimerID;          /*!< \brief 定时器ID */
};

#endif /* FG_TIMERMANAGER_H_HEADER_INCLUDED_C0A3F06D */

/*! @} */

