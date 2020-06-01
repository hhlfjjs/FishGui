/*--------------------------------------------------------------------------

	MyView.cpp - �û��������ͼ���ʵ���ļ�

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
 *  \brief �û��������ͼ���ʵ���ļ�
 *
*/

/*! @} */

#include "MyView.h"
#include "MyModel.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
BEGIN_MESSAGE_MAP(MyView, FG_Widget)
    ON_DRAW         (MyView::OnDraw)
    ON_UPDATE_VIEW  (MyView::OnViewUpdate)
END_MESSAGE_MAP()

void MyView::OnDraw(FG_OSAdaptor * pAdaptor)
{
    pAdaptor->BeginDraw(m_Rect);

    pAdaptor->FillRect(m_Rect, COLOR_BLACK, COLOR_BLACK);

    FG_Point point[10];
    int i;
    for (i = 0; i < 10; i ++)
    {
        point[i].x = m_Rect.wLeft + GetMyModel()->GetData1(i) + 1;
        point[i].y = m_Rect.wTop + i * 30 + 1;
    }
    pAdaptor->DrawPolyLine(10, point, COLOR_BLUE1);
    
    for (i = 0; i < 10; i ++)
    {
        point[i].x = m_Rect.wLeft + GetMyModel()->GetData2(i) + 1;
        point[i].y = m_Rect.wTop + i * 30 + 1;
    }
    pAdaptor->DrawPolyLine(10, point, COLOR_RED);

    pAdaptor->EndDraw();
}

