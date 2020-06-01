/*--------------------------------------------------------------------------

	MyModel.cpp - �û������ģ�����ʵ���ļ�

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
/*! \addtogroup MVC_Application
 *  @{ 
 */

/*! \file
 *  \brief �û������ģ�����ʵ���ļ�
 *
*/

/*! @} */

#include "MyModel.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
MyModel * GetMyModel(void)
{
    return MyModel::GetModel();
}

MyModel * MyModel::m_pModel = NULL;

MyModel * MyModel::GetModel(void)
{
    if (! m_pModel)
    {
        m_pModel = new MyModel();
    }
    return m_pModel;
}

MyModel::MyModel()
{
    for (int i = 0; i < 2; i ++)
        for (int j = 0; j < 10; j ++)
            m_Data[i][j] = 0;
}

void MyModel::SendData1(unsigned char data)
{
    for (int i = 9; i > 0; i --)
        m_Data[0][i] = m_Data[0][i - 1];
    m_Data[0][0] = data;
    UpdateView();
}

void MyModel::SendData2(unsigned char data)
{
    for (int i = 9; i > 0; i --)
        m_Data[1][i] = m_Data[1][i - 1];
    m_Data[1][0] = data;
    UpdateView();
}

void MyModel::AdjustData(void)
{
    for (int i = 0; i < 2; i ++)
        for (int j = 0; j < 10; j ++)
            m_Data[i][j] = 255 - m_Data[i][j];
    UpdateView();
}

