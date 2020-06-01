/*--------------------------------------------------------------------------

	FG_MsgMap.h - ��Ϣӳ���ṹ�Լ��궨���ͷ�ļ�

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
 *  \brief ��Ϣӳ���ṹ�Լ��궨���ͷ�ļ�
*/

#ifndef FG_MSGMAP_H_HEADER_INCLUDED_C0AD453B
#define FG_MSGMAP_H_HEADER_INCLUDED_C0AD453B

#include "../Utility/FG_Utility.h"
#include "../OSAdaptor/FG_OSAdaptor.h"

/*! \defgroup MsgMap_Define ��Ϣӳ������ */
/*! @{ */

/*! \brief ������Ϣӳ���ĺ� */
#define DECLARE_MESSAGE_MAP()                                                           \
private:                                                                                \
    static const FG_MSGMAP_ENTRY m_MsgEntries[];                                        \
protected:                                                                              \
    static const FG_MSGMAP m_MsgMap;                                                    \
    virtual const FG_MSGMAP * GetMessageMap() const;                                    \

/*! \brief Ϊ��Ϣӳ�����ֵ�ĺ� */
#define BEGIN_MESSAGE_MAP(theClass, baseClass)                                          \
    const FG_MSGMAP * theClass::GetMessageMap() const                                   \
        { return & theClass::m_MsgMap; }                                                \
    const FG_MSGMAP theClass::m_MsgMap =                                                \
        { & baseClass::m_MsgMap, & theClass::m_MsgEntries[0] };                         \
    const FG_MSGMAP_ENTRY theClass::m_MsgEntries[] =                                    \
    {                                                                                   \

/*! \brief ����\ref FG_MSG_DRAW��Ϣ�ʹ������Ķ�Ӧ��ϵ�ĺ� */
#define ON_DRAW(msgCallback)                                                            \
        { FG_MSG_DRAW, 0, 0, (FG_PMSG_vv)(FG_PMSG_vd)& msgCallback },                   \

/*! \brief ����\ref FG_MSG_DRAW_REQUEST��Ϣ�ʹ������Ķ�Ӧ��ϵ�ĺ� */
#define ON_DRAWREQUEST(msgCallback)                                                     \
        { FG_MSG_DRAW_REQUEST, 0, 0, (FG_PMSG_vv)(FG_PMSG_vm)& msgCallback },           \

/*! \brief ����\ref FG_MSG_KEY��Ϣ�ʹ������Ķ�Ӧ��ϵ�ĺ� */
#define ON_KEY(msgCallback)                                                             \
        { FG_MSG_KEY, 0, 0, (FG_PMSG_vv)(FG_PMSG_bm)& msgCallback },                    \

/*! \brief ����\ref FG_MSG_KEY, \ref FKS_DOWN��Ϣ�ʹ������Ķ�Ӧ��ϵ�ĺ� */
#define ON_KEYDOWN(msgCallback)                                                         \
        { FG_MSG_KEY, FKS_DOWN, 0, (FG_PMSG_vv)(FG_PMSG_bm)& msgCallback },             \

/*! \brief ����\ref FG_MSG_KEY, \ref FKS_UP��Ϣ�ʹ������Ķ�Ӧ��ϵ�ĺ� */
#define ON_KEYUP(msgCallback)                                                           \
        { FG_MSG_KEY, FKS_UP, 0, (FG_PMSG_vv)(FG_PMSG_bm)& msgCallback },               \

/*! \brief ����\ref FG_MSG_MOUSE��Ϣ�ʹ������Ķ�Ӧ��ϵ�ĺ� */
#define ON_MOUSE(msgCallback)                                                           \
        { FG_MSG_MOUSE, 0, 0, (FG_PMSG_vv)(FG_PMSG_bm)& msgCallback },                  \

/*! \brief ����\ref FG_MSG_MOUSE, \ref FMS_LBUTTONDOWN��Ϣ�ʹ������Ķ�Ӧ��ϵ�ĺ� */
#define ON_LBUTTONDOWN(msgCallback)                                                     \
        { FG_MSG_MOUSE, FMS_LBUTTONDOWN, 0, (FG_PMSG_vv)(FG_PMSG_bm)& msgCallback },    \

/*! \brief ����\ref FG_MSG_MOUSE, \ref FMS_LBUTTONUP��Ϣ�ʹ������Ķ�Ӧ��ϵ�ĺ� */
#define ON_LBUTTONUP(msgCallback)                                                       \
        { FG_MSG_MOUSE, FMS_LBUTTONUP, 0, (FG_PMSG_vv)(FG_PMSG_bm)& msgCallback },      \

/*! \brief ����\ref FG_MSG_TIMER, timerID��Ϣ�ʹ������Ķ�Ӧ��ϵ�ĺ�
 * 
 *  ����ʶΪtimerID��֪ͨ��Ϣ
 */
#define ON_TIMER(timerID, msgCallback)                                                  \
        { FG_MSG_TIMER, timerID, 0, (FG_PMSG_vv)& msgCallback },                        \

/*! \brief ����\ref FG_MSG_FOCUS��Ϣ�ʹ������Ķ�Ӧ��ϵ�ĺ� */
#define ON_FOCUS(msgCallback)                                                           \
        { FG_MSG_FOCUS, 0, 0, (FG_PMSG_vv)(FG_PMSG_vm)& msgCallback },                  \

/*! \brief ����\ref FG_MSG_NOTIFY, \ref FG_NOTIFY_ID��Ϣ�ʹ������Ķ�Ӧ��ϵ�ĺ�
 * 
 *  ��IDΪ\ref FG_NOTIFY_ID��֪ͨ��Ϣ
 */
#define ON_NOTIFY(notifyID, msgCallback)                                                \
        { FG_MSG_NOTIFY, notifyID, 0, (FG_PMSG_vv)(FG_PMSG_vm)& msgCallback },          \

/*! \brief ����\ref FG_MSG_NOTIFY, \ref FG_NOTIFY_ID, id��Ϣ�ʹ������Ķ�Ӧ��ϵ�ĺ�
 * 
 *  ��IDΪ\ref FG_NOTIFY_ID��֪ͨ��Ϣ������֪ͨ��Ϣ�Ŀؼ���Ψһ��ʶΪΪid
 */
#define ON_ID_NOTIFY(notifyID, id, msgCallback)                                         \
        { FG_MSG_NOTIFY, notifyID, id, (FG_PMSG_vv)& msgCallback },                     \

/*! \brief ����\ref FG_MSG_UPDATE_VIEW��Ϣ�ʹ������Ķ�Ӧ��ϵ�ĺ� */
#define ON_UPDATE_VIEW(msgCallback)                                                     \
        { FG_MSG_UPDATE_VIEW, 0, 0, (FG_PMSG_vv)& msgCallback },                        \

/*! \brief ��Ϣӳ�������� */
#define END_MESSAGE_MAP()                                                               \
        { 0, 0, 0, (FG_PMSG_vv)NULL }                                                   \
    };                                                                                  \

/*! @} */

class FG_Object;
struct FG_Message;

/*! \defgroup MsgHandler_Type ��Ϣ���������� */
/*! @{ */

//##ModelId=3F58381F03A7
/*! \brief ����Ϊvoid������ֵΪvoid����Ϣ��������\n
 *  
 *  ����������Ϣ��
 *      - \ref FG_MSG_TIMER
 *      - \ref FG_MSG_NOTIFY, \ref FG_NOTIFY_ID, id
 *      - \ref FG_MSG_UPDATE_VIEW
 */
typedef void (FG_Object::* FG_PMSG_vv)(void);

//##ModelId=3F6193A7005C
/*! \brief ����Ϊ\ref FG_OSAdaptor *������ֵΪvoid����Ϣ��������\n
 *  
 *  ����������Ϣ��
 *      - \ref FG_MSG_DRAW
 */
typedef void (FG_Object::* FG_PMSG_vd)(FG_OSAdaptor * pAdaptor);

//##ModelId=3F5B47040163
/*! \brief ����Ϊ\ref FG_OSAdaptor *������ֵΪvoid����Ϣ��������\n
 *  
 *  ����������Ϣ��
 *      - \ref FG_MSG_DRAW_REQUEST
 *      - \ref FG_MSG_FOCUS
 *      - \ref FG_MSG_NOTIFY, notifyID
 */
typedef void (FG_Object::* FG_PMSG_vm)(FG_Message * pMsg);

//##ModelId=3F6167B501F0
/*! \brief ����Ϊ\ref FG_OSAdaptor *������ֵΪvoid����Ϣ��������\n
 *  
 *  ����������Ϣ��
 *      - \ref FG_MSG_KEY
 *      - \ref FG_MSG_KEY, \ref FKS_DOWN
 *      - \ref FG_MSG_KEY, \ref FKS_UP
 *      - \ref FG_MSG_MOUSE
 *      - \ref FG_MSG_MOUSE, \ref FMS_LBUTTONDOWN
 *      - \ref FG_MSG_MOUSE, \ref FMS_LBUTTONUP
 */
typedef bool (FG_Object::* FG_PMSG_bm)(FG_Message * pMsg);

/*! @} */

//##ModelId=3F58381F0375
/*! \brief ��Ϣӳ�����ṹ
 *
 *  ������Ϣӳ����е�ÿһ������
 */
struct FG_MSGMAP_ENTRY
{
    //##ModelId=3F6167B60012
    WORD        m_MsgType;              /*!< \brief ��Ϣ����\ref FG_MSG_TYPE */

    //##ModelId=3F5B584A00E0
    /*! \brief \ref WORD���͵�����
     *
     *  �������״̬\ref FG_KEY_STATUS�����״̬\ref FG_MOUSE_STATUS����ʱ��ID��֪ͨ��ϢID
     */
    WORD        m_wData;
    
    //##ModelId=3F6167B60026
    WORD        m_wID;                  /*!< \brief ����֪ͨ��Ϣ�Ŀؼ�ID */
    
    //##ModelId=3F5838210044
    FG_PMSG_vv  m_Callback;             /*!< \brief ����Ϣ��Ӧ����Ϣ������ */
};

//##ModelId=3F58381F0326
/*! \brief ��Ϣӳ���ṹ
 *
 *  ������Ϣӳ�����������Լ�ָ��������Ϣӳ����ָ��
 */
struct FG_MSGMAP
{
    //##ModelId=3F583820024A
    const FG_MSGMAP * m_pBaseMsgMap;    /*!< \brief ָ��������Ϣӳ����ָ�� */
    //##ModelId=3F583820027C
    const FG_MSGMAP_ENTRY * m_pEntry;   /*!< \brief �������Ϣӳ����ָ�� */

    //##ModelId=3F584C9400FF
    /*! \brief �ڱ������Ϣӳ����в�����Ϣ
     *
     *  Ϊ0�Ĳ�����ʾ��������
     *  \param type Ҫ���ҵ���Ϣ����\ref FG_MSG_TYPE
     *  \param data Ҫ���ҵ���Ϣ����Ϣ��\ref WORD������
     *  \param id ����֪ͨ��Ϣ�Ŀؼ�ID
     *  \return FG_MSGMAP_ENTRY* ���ҵ�����Ϣӳ����\ref NULL��ʾû���ҵ�
     */
    const FG_MSGMAP_ENTRY * FindMsgCallback(const WORD type, const WORD data, const WORD id) const;
};

#endif /* FG_KEYMAP_H_HEADER_INCLUDED_C0AD453B */

/*! @} */

