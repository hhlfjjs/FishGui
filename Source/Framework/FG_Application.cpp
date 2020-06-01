/*--------------------------------------------------------------------------

	FG_Application.cpp - Ӧ�ó���������ʵ���ļ�

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
 *  \brief Ӧ�ó���������ʵ���ļ�
 *
*/

/*! @} */

#include "FG_Application.h"
#include "FG_Screen.h"

//##ModelId=3F5218B803B6
FG_Application::FG_Application()
{
    // ע��������ͽ�����Ϣ�Ĺ۲���
    FG_GetAdaptor()->SetMsgObserver(FG_MSG_STARTUP, this);
    FG_GetAdaptor()->SetMsgObserver(FG_MSG_HALT, this);
}

//##ModelId=3F521F4D03B9
void FG_Application::OSMessage(FG_Message * pMsg)
{
    if (pMsg->wType == FG_MSG_STARTUP)
    {
        FG_GetScreen();                 // ͨ�����ʹ������ʵ㣬����\ref FG_Screen��Ψһʵ��
        FG_GetTimerManager();           // ͨ�����ʹ������ʵ㣬����\ref FG_TimerManager��Ψһʵ��

        InitApplication();
    }
    else
    {
        FG_GetScreen()->DeleteScreen();
        FG_GetTimerManager()->DeleteTimerManager();
    }
}

