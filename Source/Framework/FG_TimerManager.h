/*--------------------------------------------------------------------------

	FG_TimerManager.h - ��ʱ�����������ͷ�ļ�

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
 *  \brief ��ʱ�����������ͷ�ļ�
 *
 */

#ifndef FG_TIMERMANAGER_H_HEADER_INCLUDED_C0A3F06D
#define FG_TIMERMANAGER_H_HEADER_INCLUDED_C0A3F06D

#include "../Utility/FG_Utility.h"
#include "../OSAdaptor/FG_OSAdaptor.h"
class FG_Object;

//##ModelId=3FD884F5022C
/*! \brief ��ʱ����
 *
 *  ����ʱ���ı�ʶ������ʱ�䡢����ö�ʱ���Ĵ���Ԫ�ص���Ϣ
 */
class FG_Timer
{
public:
    //##ModelId=3FD884F70347
    /*! \brief ���캯��
     *
     *  \param pTarget ���붨ʱ���Ĵ���Ԫ��
     *  \param timerID ��ʱ����Ψһ��ʶ
     *  \param dwInterval ��ʱ���ĵ���ʱ��
     */
    FG_Timer(FG_Object * pTarget, BYTE timerID, DWORD dwInterval) 
        : m_TimerID(timerID), m_dwInterval(dwInterval), m_dwCount(dwInterval),
        m_pTarget(pTarget)
        {}

    /*! \brief ��ʱ����઴�����
     *
     *  ���ö�ʱ���Ƿ��ڣ�������ڣ����Ͷ�ʱ����Ϣ����Ӧ�Ĵ���Ԫ��
     */
    //##ModelId=40BB6F970366
    void Tick(void);

    //##ModelId=3FD884F702E4
    BYTE        m_TimerID;          /*!< ��ʱ����Ψһ��ʶ������ͬһ������Ԫ��Ψһ�� */
    //##ModelId=3FD884F702F8
    DWORD       m_dwInterval;       /*!< ��ʱ���ĵ���ʱ�䣨��λ�����룩 */
    //##ModelId=3FD884F70316
    DWORD       m_dwCount;          /*!< ��ǰ������ */
    //##ModelId=3FD884F7032A
    FG_Object * m_pTarget;          /*!< ���붨ʱ���Ĵ���Ԫ�أ���ʱ��������Ϣ�ᱻ���͸��ô���Ԫ�� */
};

//##ModelId=3F5C4ED700C1
/*! \brief ��ʱ����������
 *
 *  ����ϵͳ�е����ж�ʱ���������ࡣ
 */
class FG_TimerManager : public FG_OSMsgObserver
{
public:
    //##ModelId=3F5C57A203B7
    /*! \brief �õ���ʱ����������Ψһʵ�������ȫ�ַ��ʵ㺯��
     *
     *  \return ָ��ʱ����������Ψһʵ�������ָ��
     */
    static FG_TimerManager * GetTimerManager(void);

    //##ModelId=3F71AB2000E8
    /*! \brief ɾ����ʱ����������Ψһʵ������
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
    /*! \brief ���캯��
     *
     *  �û�����ֱ�ӷ���
     */
    FG_TimerManager();

    //##ModelId=3F71AB20019C
    /*! \brief ��������
     *
     *  �û�����ֱ�ӷ��ʣ�ɾ�����еĶ�ʱ��
     */
    ~FG_TimerManager() { KillAllTimer(); }

private:
    //##ModelId=3F5DD9650193
    typedef FG_SList<FG_Timer> FG_TIMERLIST;    /*!< ���涨ʱ������������ */

    //##ModelId=3F5DD9660087
    FG_TIMERLIST m_TimerList;                   /*!< ���涨ʱ������������ */

    //##ModelId=3F5C57A2039C
    static FG_TimerManager * m_pTimerManager;   /*!< ָ��Ψһ�Ķ�ʱ��������ʵ�������ָ�� */
};

/*! \brief ��װ��ʱ����������ȫ�ַ��ʵ�\ref FG_TimerManager::GetTimerManager��ȫ�ֺ���
 *
 *  \return ָ��Ψһ�Ķ�ʱ����������ָ��
 */
FG_TimerManager * FG_GetTimerManager(void);

//##ModelId=3FD884F5002D
/*! \brief ���Ҷ�ʱ���ļ����
 *
 *  ���ڵ��������Ҷ�ʱ���������е����ж�ʱ��
 */
class FG_CheckTimer : public FG_ListCheck<FG_Timer>
{
public:
    //##ModelId=3FD884F60165
    /*! \brief ��ʱ���ļ����Ĺ��캯��
     *
     *  \param pObject ���붨ʱ����Ŀ�괰��Ԫ��
     *  \param timerID ��ʱ��ID
     */
    FG_CheckTimer(FG_Object * pObject, BYTE timerID) : m_pTarget(pObject), m_TimerID(timerID) {}

    //##ModelId=3FD884F60183
    /*! \brief �������Ƿ���������
     *
     *  ͨ���Ƚ϶�ʱ����ID��Ŀ�괰��Ԫ���������ö�ʱ���Ƿ���������
     *  \param pTimer Ҫ���Ķ�ʱ��
     *  \return �Ƿ���������\n
     *          true    ��������\n
     *          false   ����������
     */
    virtual bool FindIt(const FG_Timer * pTimer) { return (pTimer->m_pTarget == m_pTarget && pTimer->m_TimerID == m_TimerID); }

private:
    //##ModelId=3FD884F60134
    FG_Object * m_pTarget;          /*!< \brief ���붨ʱ����Ŀ�괰��Ԫ�� */
    //##ModelId=3FD884F60152
    BYTE        m_TimerID;          /*!< \brief ��ʱ��ID */
};

#endif /* FG_TIMERMANAGER_H_HEADER_INCLUDED_C0A3F06D */

/*! @} */

