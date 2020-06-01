/*--------------------------------------------------------------------------

	FG_KeyMap.cpp - ����ӳ������ʵ���ļ�

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
 *  \brief ����ӳ������ʵ���ļ�
 */

/*! @} */

#include "FG_KeyMap.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
//##ModelId=40925CC102B6
FG_KeyMap::~FG_KeyMap()
{
    FG_KEYMAPLIST::iterator i;
    for (i = m_KeyMapList.First(); ! i.IsDone(); ++ i)
        delete i;
    m_KeyMapList.RemoveAll();
}

//##ModelId=3F5EDD9E0335
bool FG_KeyMap::SendKey(FG_Message * pMsg)
{
    FG_KEYMAPLIST::iterator i = m_KeyMapList.First();
    FG_CheckOriginKey check((WORD)pMsg->lData);
    
    if (FG_ListFind_If(i, check))
    {	
        // �пؼ�ע���˸ÿ�ݼ�
        FG_Message Msg = *pMsg;
        Msg.lData = i->m_wActualKey;			// �ṩ��ֵ��ת������
        return i->m_pTarget->Message(& Msg);	// ���ͼ�����Ϣ
    }
    return false;
}

