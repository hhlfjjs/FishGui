/*--------------------------------------------------------------------------

	MyView.h - �û��������ͼ�ؼ����ͷ�ļ�

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
 *  \brief �û��������ͼ�ؼ����ͷ�ļ�
 */

#ifndef MYVIEW_H_HEADER_INCLUDED_C0A7A9C0
#define MYVIEW_H_HEADER_INCLUDED_C0A7A9C0

#include "../../Source/Framework/FG_Framework.h"

/*! \brief �û��������ͼ�ؼ���
 */
class MyView : public FG_Widget
{
public:
    /*! \brief ��ͼ�ؼ���Ĺ��캯��
     * 
     *  \param Rect ��ͼ�ؼ�ռ�ݵ���Ļ��������
     */
    MyView(const FG_Rect & Rect) : FG_Widget(Rect, 0) {}

protected:
    /*! \brief \ref FG_MSG_DRAW��Ϣ�Ĵ����� */
    void OnDraw(FG_OSAdaptor * pAdaptor);

    /*! \brief ��ͼ֪ͨ��Ϣ�Ĵ����� */
    void OnViewUpdate(void) { RequestDraw(); }

    DECLARE_MESSAGE_MAP()
};

#endif /* MYVIEW_H_HEADER_INCLUDED_C0A7A9C0 */

/*! @} */

