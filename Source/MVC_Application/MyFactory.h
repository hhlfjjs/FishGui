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
/*! \addtogroup MVC_Application
 *  @{ 
 */

/*! \file
 *  \brief �û�����Ĺ������ͷ�ļ�
 */

#ifndef MYFACTORY_H_HEADER_INCLUDED_C0A7A9C0
#define MYFACTORY_H_HEADER_INCLUDED_C0A7A9C0

#include "../Framework/FG_Framework.h"
#include "MyView.h"

/*! \brief �û�����Ĺ�����
 */
class MyFactory : public FG_Factory
{
public:
    /*! \brief ������ͼ�ؼ�
     *
     *  \param Rect ��ͼ�ؼ����ڵľ�������
     *  \return ����������ͼ�ؼ�
     */
    MyView * CreateMyView(const FG_Rect & Rect)
    {
        return new MyView(Rect);
    }
};

#endif /* MYFACTORY_H_HEADER_INCLUDED_C0A7A9C0 */

/*! @} */

