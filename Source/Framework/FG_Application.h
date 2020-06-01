/*--------------------------------------------------------------------------

	FG_Application.h - Ӧ�ó���������ͷ�ļ�

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
 *  \brief Ӧ�ó���������ͷ�ļ�
 *
*/

#ifndef FG_APPLICATION_H_HEADER_INCLUDED_C0ADE4E6
#define FG_APPLICATION_H_HEADER_INCLUDED_C0ADE4E6

#include "../OSAdaptor/FG_OSAdaptor.h"

//##ModelId=3F49CDE90267
/*! \brief Ӧ�ó��������
 *
 *  Ӧ�ò�Ӧ�ö������������࣬ʵ��\ref FG_Application::InitApplication����\n
 *  ���Ҷ���һ��Ψһ��\ref theApp�������ɸ����Ψһ��ʵ������
 */
class FG_Application : public FG_OSMsgObserver
{
public:
    //##ModelId=3F5218B803B6
    /*! \brief ���캯��
     *
     *  ע��Ϊ\ref FG_MSG_STARTUP��\ref FG_MSG_HALT��Ϣ�Ĺ۲���
     */
    FG_Application();
    //##ModelId=3F5218B9000B

    //##ModelId=3F521F4D03B9
    /*! \brief ʵ�ֲ���ϵͳ��Ϣ�Ľ��սӿ�
     *
     *  - ����\ref FG_MSG_STARTUP��Ϣ
     *    - ͨ�����ʹ������ʵ㣬����\ref FG_Screen��Ψһʵ��
     *    - ͨ�����ʹ������ʵ㣬����\ref FG_TimerManager��Ψһʵ��
     *    - ����ģ�巽��\ref InitApplication
     *  - ����\ref FG_MSG_HALT��Ϣ
     *    - ɾ��\ref FG_Screen��Ψһʵ��
     *    - ɾ��\ref FG_TimerManager��Ψһʵ��
     *
     *  \param pMsg ���͸�Ӧ�ó����ϵͳ��Ϣ
     */
    void OSMessage(FG_Message * pMsg);

    //##ModelId=3F52AB070145
    /*! \brief ��ʼ��Ӧ�ó���ӿ�
     *
     *  �ú���Ϊģ�巽�������������ʵ�ָýӿڣ�ִ��Ӧ�ó���ĳ�ʼ���������紴�������ڵ�
     */
    virtual void InitApplication() = 0;
};

#endif /* FG_APPLICATION_H_HEADER_INCLUDED_C0ADE4E6 */

/*! @}*/

