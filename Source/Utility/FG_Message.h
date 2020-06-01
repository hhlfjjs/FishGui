/*--------------------------------------------------------------------------

	FG_Message.h -  ��Ϣ���Ͷ���ͷ�ļ�

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
/*! \addtogroup Utility
 *  @{ 
 */

/*! \file 
 *  \brief ��Ϣ���Ͷ���ͷ�ļ�
 *
 *  ���ļ��ж���FishGUI���ϵͳ���õ������е���Ϣ���ͺ���Ϣ�ṹ
 */

#ifndef FG_MESSAGE_H_HEADER_INCLUDED_C0B10BA4
#define FG_MESSAGE_H_HEADER_INCLUDED_C0B10BA4

#include "FG_Point.h"

//##ModelId=40BB6FFD03A9
/*! \brief ��Ϣ���͵�ö������
 *
 *  ʵ�ʵĴ洢����Ϊ\ref WORD
 */
enum FG_MSG_TYPE
{
    FG_MSG_STARTUP,         /*!< \brief ϵͳ������Ϣ */
    FG_MSG_HALT,            /*!< \brief ϵͳֹͣ��Ϣ */
    FG_MSG_DRAW,            /*!< \brief ��Ļˢ�»򴰿�Ԫ���ػ���Ϣ */
    FG_MSG_KEY,             /*!< \brief ������Ϣ */ 
    FG_MSG_MOUSE,           /*!< \brief �����Ϣ */
    FG_MSG_TIMER,           /*!< \brief ��ʱ����Ϣ */
                            // ����Ϊ���е�ϵͳ��Ϣ
    /*! \brief ϵͳ�ڲ�ʹ�ã�����һ����Ϣ���ͣ���ʾ����ϵͳ��Ϣ������
     *  ֮ǰΪ���е�ϵͳ��Ϣ��֮��Ϊ�ڲ���Ϣ */
    FG_MAX_SYS_MSG,

    /*! \brief �����ػ���Ϣ���ؼ���Ҫ�ػ�ʱ�򴰿ڷ��ʹ���Ϣ��������Ҫ�ػ�ʱ����Ļ���ʹ���Ϣ��
     *  ����Ļ���ݸô����Ƿ��ǽ��㴰������������ػ� */
    FG_MSG_DRAW_REQUEST,

    FG_MSG_FOCUS,           /*!< \brief �����л���Ϣ */
    FG_MSG_NOTIFY,          /*!< \brief ֪ͨ��Ϣ */
    FG_MSG_UPDATE_VIEW      /*!< \brief MVCģʽ����ͼ������Ϣ */
};

/*! \brief ����״̬
 *
 *  ���ڼ������͵���Ϣ��Ч��ʵ�ʵĴ洢����Ϊ\ref WORD������\ref FG_Message::wData�У�0Ϊ����ֵ
 */
//##ModelId=40BB6FFD0308
enum FG_KEY_STATUS
{
    FKS_NONE = 0,           /*!< \brief ����״̬ */
    FKS_DOWN,               /*!< \brief ���̰���״̬ */
    FKS_UP                  /*!< \brief ���̵���״̬ */
};

/*! \addtogroup Virtual_Key �������
 *  @{ 
 */
const WORD FVK_0        = 0x30;           /*!< \brief '0' */
const WORD FVK_1        = 0x31;           /*!< \brief '1' */
const WORD FVK_2        = 0x32;           /*!< \brief '2' */
const WORD FVK_3        = 0x33;           /*!< \brief '3' */
const WORD FVK_4        = 0x34;           /*!< \brief '4' */
const WORD FVK_5        = 0x35;           /*!< \brief '5' */
const WORD FVK_6        = 0x36;           /*!< \brief '6' */
const WORD FVK_7        = 0x37;           /*!< \brief '7' */
const WORD FVK_8        = 0x38;           /*!< \brief '8' */
const WORD FVK_9        = 0x39;           /*!< \brief '9' */
const WORD FVK_A        = 0x41;           /*!< \brief 'A' */
// B.C.D......
const WORD FVK_Z        = 0x5a;           /*!< \brief 'Z' */

const WORD FVK_ENTER    = 0x8000;         /*!< \brief ENTER */
const WORD FVK_DELETE   = 0x8001;         /*!< \brief DELETE */
const WORD FVK_LEFT     = 0x8002;         /*!< \brief LEFT */
const WORD FVK_RIGHT    = 0x8003;         /*!< \brief RIGHT */
const WORD FVK_TAB      = 0x8004;         /*!< \brief TAB */
/* @} */

/*! \brief ���״̬
 *
 *  ����������͵���Ϣ��Ч��ʵ�ʵĴ洢����Ϊ\ref WORD������\ref FG_Message::wData�У�0Ϊ����ֵ
 */
//##ModelId=40BB6FFD0363
enum FG_MOUSE_STATUS
{
    FMS_NONE = 0,           /*!< \brief ����״̬ */
    FMS_LBUTTONDOWN,        /*!< \brief ����������״̬ */
    FMS_LBUTTONUP           /*!< \brief ����������״̬ */
};

/*! \brief ����״̬
 *
 *  ���ڽ������͵���Ϣ��Ч��ʵ�ʵĴ洢����Ϊ\ref WORD������\ref FG_Message::wData�У�0Ϊ����ֵ
 */
//##ModelId=40BB6FFD02B8
enum FG_FOCUS_STATUS
{
    FFS_NONE = 0,           /*!< \brief ����״̬ */
    FFS_GET,                /*!< \brief �õ�����״̬ */
    FFS_LOSE                /*!< \brief ʧȥ����״̬ */
};

/*! \brief ֪ͨ��ϢID
 *
 *  ����֪ͨ��Ϣ��Ч��ʵ�ʵĴ洢����Ϊ\ref WORD������\ref FG_Message::wData�У�0Ϊ����ֵ
 */
//##ModelId=40BB6FFE0007
enum FG_NOTIFY_ID
{
    FN_NONE = 0,           /*!< \brief ����״̬ */
    // CheckBox֪ͨ��Ϣ
    FBN_PRESSED,           /*!< \brief ��ť�ؼ�����״̬ */
    
    // CheckBox֪ͨ��Ϣ
    FCN_CHECKED,           /*!< \brief ѡ��ť�ؼ���ѡ��״̬ */
    FCN_UNCHECKED,         /*!< \brief ѡ��ť�ؼ���ȡ��ѡ��״̬ */
    
    // RadioButton֪ͨ��Ϣ
    FRN_CHECKED,           /*!< \brief ��������ť�ؼ���ѡ��״̬ */
    FRN_UNCHECKED          /*!< \brief ��������ť�ؼ���ȡ��ѡ��״̬ */
};

//##ModelId=3F603B29014A
/*! \brief ��Ϣ�ṹ
 *
 *  �ýṹ��װϵͳ�д��ݵ�������Ϣ
 */
struct FG_Message
{
    //##ModelId=3F603B2902C9
    /*! \brief ȱʡ���캯�� */
    FG_Message() 
        : wType(0), wData(0), wID(0), lData(0) {}

    //##ModelId=3F603B2902D0
    /*! \brief ���캯��
     *
     *  \param type ��Ϣ����
     */
    FG_Message(WORD type) 
        : wType(type), wData(0), wID(0), lData(0) {}

    //##ModelId=3F6167C1034C
    /*! \brief ���캯��
     *
     *  \param type ��Ϣ����
     *  \param data ��Ϣ����WORD������
     */
    FG_Message(WORD type, WORD data) 
        : wType(type), wData(data), wID(0), lData(0) {}

    //##ModelId=3F6167C1036A
    /*! \brief ���캯��
     *
     *  \param type ��Ϣ����
     *  \param data ��Ϣ����WORD������
     *  \param id ֪ͨ��Ϣ�ķ�����ID
     */
    FG_Message(WORD type, WORD data, WORD id) 
        : wType(type), wData(data), wID(id), lData(0) {}

    //##ModelId=3F6167C10325
    WORD wType;                   /*!< \brief ��Ϣ���� */
    //##ModelId=3F603B2902C0
    WORD wData;                   /*!< \brief WORD�͵����ݣ����������Ϣ״̬�������Ϣ״̬��֪ͨ��Ϣ */
    //##ModelId=3F6167C10339
    WORD wID;                     /*!< \brief ֪ͨ��Ϣ�ķ�����ID */
    union
    {
        void *      pData;        /*!< \brief �û�����ָ�� */
        DWORD       lData;        /*!< \brief DWORD���û����� */
        FG_Point    Point;        /*!< \brief ���λ�ã�ֻ�������Ϣ��Ч */
    };
};

#endif /* FG_MESSAGE_H_HEADER_INCLUDED_C0B10BA4 */

/*! @} */

