/*--------------------------------------------------------------------------

	FG_MsgMap.cpp - ��Ϣӳ���ṹ�Լ��궨���ʵ���ļ�

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
 *  \brief ��Ϣӳ���ṹ�Լ��궨���ʵ���ļ�
*/

/*! @} */

#include "FG_MsgMap.h"

//##ModelId=3F584C9400FF
const FG_MSGMAP_ENTRY * FG_MSGMAP::FindMsgCallback(const WORD type, const WORD data, const WORD id) const
{
    int i;
    for (i = 0; m_pEntry[i].m_Callback != NULL; i ++)
    {
        if (type != m_pEntry[i].m_MsgType)
            continue;
        if (m_pEntry[i].m_wData && data != m_pEntry[i].m_wData)
            continue;
        if (m_pEntry[i].m_wID && id != m_pEntry[i].m_wID)
            continue;
        break;
    }

    return & m_pEntry[i];
}

