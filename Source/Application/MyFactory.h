/*--------------------------------------------------------------------------

	MyFactory.h - �û�����Ĺ������ͷ�ļ�

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
/*! \addtogroup Application
 *  @{ 
 */

/*! \file
 *  \brief �û�����Ĺ������ͷ�ļ�
 */

#ifndef MYFACTORY_H_HEADER_INCLUDED_C0A7A9C0
#define MYFACTORY_H_HEADER_INCLUDED_C0A7A9C0

#include "../Framework/FG_Framework.h"
#include "MyButton.h"

//##ModelId=3F71AB0202EE
/*! \brief �û�����Ĺ�����
 *
 *  ����\ref FG_Factory::CreateButton�麯������Ϊ����Բ�Ǿ��οؼ���ʵ������
 */
class MyFactory : public FG_Factory
{
public:
    //##ModelId=3F71AB0303C2
    FG_Button * CreateButton(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
    {
        return new MyButton(Text, Rect, wID);
    }
};

#endif /* MYFACTORY_H_HEADER_INCLUDED_C0A7A9C0 */

/*! @} */

