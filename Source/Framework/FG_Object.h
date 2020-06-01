/*--------------------------------------------------------------------------

	FG_Object.h - ����Ԫ�����ͷ�ļ�

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
 *  \brief ����Ԫ�����ͷ�ļ�
 *
*/

#ifndef FG_OBJECT_H_HEADER_INCLUDED_C0AD453B
#define FG_OBJECT_H_HEADER_INCLUDED_C0AD453B

#include "../Utility/FG_Utility.h"
#include "FG_MsgMap.h"
#include "FG_TimerManager.h"

//##ModelId=3F52B635008C
/*! \brief ����Ԫ����
 *
 *  ����Ԫ���������п�������Ļ����ʾ�Ĵ��ڡ��ռ����Ļ���
 */
class FG_Object
{
public:
    //##ModelId=3F58382100BB
    /*! \brief ���캯����������Ϊȱʡ���캯��ʹ��
     *
     *  ǰ��ɫ�ͱ���ɫȱʡΪ��ɫ��\ref COLOR_BLACK���ͻ�ɫ��\ref COLOR_GRAY��
     *  ������ָ��ȱʡΪ\ref NULL
     *  \param wID �ô���Ԫ�ص�Ψһ��ʶ��ȱʡֵ0��0Ϊ��Ч��ʶ��
     *  \param wStyle �ô���Ԫ�صı߿���ȱʡֵΪ\ref FS_NONE
     */
    FG_Object(const WORD wID = 0, const WORD wStyle = FS_NONE)
        : m_ForeColor(COLOR_BLACK), m_Background(COLOR_GRAY), m_wStyle(wStyle), m_wID(wID), m_pParent(NULL)
        {}

    //##ModelId=3F52BE4E0368
    /*! \brief ���캯��
     *
     *  ǰ��ɫ�ͱ���ɫȱʡΪ��ɫ��\ref COLOR_BLACK���ͻ�ɫ��\ref COLOR_GRAY��
     *  ������ָ��ȱʡΪ\ref NULL
     *
     *  \param Rect �ô���Ԫ�صı߿����
     *  \param wID �ô���Ԫ�ص�Ψһ��ʶ��ȱʡֵ0��0Ϊ��Ч��ʶ��
     *  \param wStyle �ô���Ԫ�صı߿���ȱʡֵ
     */
    FG_Object(const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE)
        : m_ForeColor(COLOR_BLACK), m_Background(COLOR_GRAY),
          m_Rect(Rect), m_wStyle(wStyle), m_wID(wID), m_pParent(NULL)
        {}

    //##ModelId=3F52BE4F01BB
    /*! \brief ��������
     *
     *  ����Ϊ�麯����ɾ���ô���Ԫ����������ж�ʱ��
     */
    virtual ~FG_Object() { FG_GetTimerManager()->KillObjectTimer(this); }
    
    //##ModelId=3F52BE4F0251
    /*! \brief �õ��ô���Ԫ�صĿͻ�������
     *
     *  ���ݱ߿����ȥ��ͬ�ı߿��С���ͻ������ο���С�ڱ߿���Σ�
     *  ĳһ������Ĵ���Ԫ�ؿ��Ը��Ǵ˺���,��ȷ���Լ��Ŀͻ�������
     *  \param rect ���ظô���Ԫ�صĿͻ�������
     */
    virtual void GetClientRect(FG_Rect & rect) const;

    //##ModelId=3F52BE4F02E7
    /*! \brief �ж�ĳһ�����ص��Ƿ��ڱ�����Ԫ����
     *
     *  \param Test �����Ե����ص�
     *  \return true ��ʾ���ص��ڱ�����Ԫ����
     *          false ��ʾ���ص㲻�ڱ�����Ԫ����
     */
    bool IsContains(const FG_Point Test) const { return m_Rect.Contains(Test); }
    
    //##ModelId=3F52BE4F0391
    /*! \brief ���ô���Ԫ�ص�ǰ��ɫ
     *
     *  \param color ǰ��ɫ
     */
    void ForeColor(const COLORVAL color) { m_ForeColor = color; }

    //##ModelId=3F52BE50003F
    /*! \brief �õ�����Ԫ�ص�ǰ��ɫ
     *
     *  \return ������Ԫ�ص�ǰ��ɫ
     */
    COLORVAL ForeColor(void) const { return m_ForeColor; }
    
    //##ModelId=3F52BE5000AE
    /*! \brief ���ô���Ԫ�صı���ɫ
     *
     *  \param color ����ɫ
     */
    void BGColor(const COLORVAL color) { m_Background = color; }

    //##ModelId=3F52BE500144
    /*! \brief �õ�����Ԫ�صı���ɫ
     *
     *  \return ������Ԫ�صı���ɫ
     */
    COLORVAL BGColor(void) const { return m_Background; }

    //##ModelId=3F52BE500252
    /*! \brief ���ô���Ԫ�ص�Ψһ��ʶֵ
     *
     *  \param wID Ψһ��ʶֵ
     */
    void ID(const WORD wID) { m_wID = wID;}

    //##ModelId=3F52BE5001C6
    /*! \brief �õ�����Ԫ�ص�Ψһ��ʶֵ
     *
     *  \return ������Ԫ�ص�Ψһ��ʶֵ
     */
    WORD ID(void) const { return m_wID;}

    //##ModelId=3F52BE500375
    /*! \brief ����ָ�򸸴���Ԫ�ص�ָ��
     *
     *  \param object ָ�򸸴���Ԫ�ص�ָ��
     */
    void Parent(FG_Object * const object) { m_pParent = object; }

    //##ModelId=3F52BE5002E8
    /*! \brief ����ָ�򸸴���Ԫ�ص�ָ��
     *
     *  \return ָ�򸸴���Ԫ�ص�ָ��
     */
    FG_Object * Parent(void) const { return m_pParent; }

    //##ModelId=3F52BE51018B
    /*! \brief ���ô���Ԫ�صı߿���
     *
     *  \param wStyle �߿���
     */
    void FrameStyle(WORD wStyle)
    {
        wStyle &= FS_MASK;
        m_wStyle &= ~FS_MASK;
        m_wStyle |= wStyle;
    }

    //##ModelId=3F52BE510236
    /*! \brief �õ�����Ԫ�صı߿���
     *
     *  \return ������Ԫ�صı߿���
     */
    WORD FrameStyle(void) const { return (m_wStyle & FS_MASK); }

    //##ModelId=3F52BE51036C
    /*! \brief ���ô���Ԫ�صķ��
     *
     *  \param wStyle \ref Style
     */
    void Style(const WORD wStyle) { m_wStyle = wStyle; }

    //##ModelId=3F52BE5102CC
    /*! \brief �õ�����Ԫ�صķ��
     *
     *  \return ������Ԫ�ص�\ref Style
     */
    WORD Style(void) const { return m_wStyle; }

    //##ModelId=3F6EAC8F00F6
    /*! \brief ���ô���Ԫ�صķ���еĽ���λ�����Ѹô���Ԫ������Ϊ���㴰�ڻ򽹵�ؼ�
     *
     *  ����λ\ref GS_FOCUSΪ1����ʾ�ô���Ԫ��Ϊ���㴰�ڻ򽹵�ؼ��������Եõ���ǰ�ļ�������
     *  ����ô���Ԫ�ز������뽹��
     */
    void SetFocus(void) { m_wStyle |= GS_FOCUS; }

    //##ModelId=3F6EAC8F0100
    /*! \brief �������Ԫ�صķ���еĽ���λ�����Ѹô���Ԫ������Ϊ�ǽ��㴰�ڻ�ǽ���ؼ�
     *
     *  ����λΪ1����ʾ�ô���Ԫ��Ϊ���㴰�ڻ򽹵�ؼ��������Եõ���ǰ�ļ�������
     *  ����ô���Ԫ�ز������뽹��
     */
    void ResetFocus(void) { m_wStyle &= ~GS_FOCUS; }

    //##ModelId=3F6EAC8F0114
    /*! \brief �ô���Ԫ���Ƿ�Ϊ��ǰ���㴰��Ԫ��
     *
     *  - ���ڴ��ڣ����㴰��ָ������Ĵ���
     *  - ���ڿؼ�������ؼ�ָ��ǰ��������Ŀؼ�
     */
    bool IsFocus(void) const { return (m_wStyle & GS_FOCUS) != 0; }

    //##ModelId=3F58382102A6
    /*! \brief ��Ϣ�ַ�����
     *
     *  ���ȵõ���Ϣӳ����ָ�룬�ӱ���ֱ���������Ϣӳ�����Ѱ�Ҹ���Ϣ��
     *  Ȼ�󣬸�����Ϣ���ͷַ���Ϣ
     *  \param pMsg Ҫ�ַ�����Ϣָ��
     *  \return ����Ϣ�Ƿ��ѱ�����
     *          true    ����Ϣ�ѱ�����
     *          false   ����Ϣδ������
     */
    bool Message(FG_Message * pMsg);

protected:
    //##ModelId=3F5DAA1402B2
    /*! \brief Ϊ��ǰ����Ԫ������һ����ʱ��
     *
     *  \param timerID ��ʱ����Ψһ��ʶ�����ڵ�ǰ����Ԫ��Ψһ��
     *  \param dwInterval ��ʱ���ĵ���ʱ��
     *  \return ��ʱ���Ƿ�ɹ�����
     *          true    �ɹ�
     *          false   ʧ��
     */
    bool StartTimer(const BYTE timerID, const WORD dwInterval)
    {
        return FG_GetTimerManager()->StartTimer(this, timerID, dwInterval);
    }
    
    //##ModelId=3F5DAA140320
    /*! \brief ɾ����ǰ����Ԫ�صĶ�ʱ��
     *
     *  \param timerID ��ʱ����Ψһ��ʶ�����ڵ�ǰ����Ԫ��Ψһ��
     *  \return ��ʱ���Ƿ�ɹ�ɾ��
     *          true    �ɹ�
     *          false   ʧ��
     */
    bool KillTimer(const BYTE timerID)
    {
        return FG_GetTimerManager()->KillTimer(this, timerID);
    }

    //##ModelId=3F52BE520038
    /*! \brief ���ƴ���Ԫ�صı߿�
     *
     *  \param pAdaptor ָ�����ϵͳ��������ָ��
     */
    void DrawBorder(FG_OSAdaptor * pAdaptor);

    //##ModelId=3F603B980280
    /*! \brief ����֪ͨ��Ϣ���ô���Ԫ�صĸ�����
     *
     *  \param wNotification ֪ͨ��Ϣ������
     */
    void NotifyParent(const WORD wNotification);

    //##ModelId=3F603B9802BC
    /*! \brief ����Ҫ���ػ���Ϣ���ô���Ԫ�صĸ�����
     *
     */
    void RequestDraw();

protected:
    //##ModelId=3F52BE4E01E1
    COLORVAL    m_ForeColor;        /*!< \brief ǰ��ɫ */
    //##ModelId=3F52BE4E02BF
    COLORVAL    m_Background;       /*!< \brief ����ɫ */
    //##ModelId=3F52BE4E02DD
    FG_Rect     m_Rect;             /*!< \brief ������Ԫ��ռ�ݵľ������� */

    //##ModelId=3F52BE4E02F1
    WORD        m_wStyle;           /*!< \brief ������Ԫ�صı߿��� */

    //##ModelId=3F52BE4E0305
    WORD        m_wID;              /*!< \brief ������Ԫ�ص�Ψһ��ʶ */

    //##ModelId=3F52BE4E034D
    FG_Object * m_pParent;          /*!< \brief ָ�򱾴���Ԫ�صĸ����ڵ�ָ�� */

//    DECLARE_MESSAGE_MAP()
private:
    //##ModelId=3F5C4D41037C
    static const FG_MSGMAP_ENTRY    m_MsgEntries[];     /*!< \brief ��Ϣӳ��������� */

protected:
    //##ModelId=3F5C4D4103CC
    static const FG_MSGMAP          m_MsgMap;           /*!< \brief �������Ϣӳ��� */

    //##ModelId=3F5C4D42001F
    /*! \brief �õ��������Ϣӳ���ָ��
     *
     *  �麯���������า�Ǹú������������Լ�����Ϣӳ���ָ�룬ͨ����\ref BEGIN_MESSAGE_MAP����
     *  \return �������Ϣӳ���ָ��
     */
    virtual const FG_MSGMAP * GetMessageMap() const;

protected:
    //##ModelId=3F52BE4F01E3
    /*! \brief �ػ���Ϣ\ref FG_MSG_DRAW�Ĵ�����
     *
     *  ���մ���Ԫ�صı߿�����Ʊ߿�
     *  \param pAdaptor ָ�����ϵͳ��������ָ��
     */
    void OnDraw(FG_OSAdaptor * pAdaptor)
    {
        DrawBorder(pAdaptor);
    }

    //##ModelId=3F6EAC8F0128
    /*! \brief �����л���Ϣ\ref FG_MSG_FOCUS�Ĵ�����
     *
     *  \param pMsg ָ�򽹵��л���Ϣ�ṹ��ָ��
     */
    void OnFocus(FG_Message * pMsg);
};

//##ModelId=3FD884F403D9
/*! \brief ���ձ�ʶ���Ҵ���Ԫ�صļ����
 *
 *  �����㷨�������ձ�ʶ���Ҵ���Ԫ��
 */
class FG_CheckObjectID : public FG_ListCheck<FG_Object>
{
public:
    //##ModelId=3FD884F600C5
    /*! \brief ���캯��
     *
     *  \param wID Ҫ���ҵĴ���Ԫ�ص�Ψһ��ʶ
     */
    FG_CheckObjectID(const WORD wID) : m_wID(wID) {}

    //##ModelId=3FD884F600CF
    /*! \brief �������Ƿ���������
     *
     *  ͨ���Ƚϴ���Ԫ�ص�ID�������ô���Ԫ���Ƿ���������
     *  \param pObj Ҫ���Ĵ���Ԫ��ָ��
     *  \return �Ƿ���������\n
     *          true    ��������\n
     *          false   ����������
     */
    virtual bool FindIt(const FG_Object * pObj)
    {
        return pObj->ID() == m_wID;
    }

private:
    //##ModelId=3FD884F600A8
    WORD m_wID;                 /*!< \brief ����Ҫ���ҵĴ���Ԫ�ص�Ψһ��ʶ */
};

#endif /* FG_OBJECT_H_HEADER_INCLUDED_C0AD453B */

/*! @} */

