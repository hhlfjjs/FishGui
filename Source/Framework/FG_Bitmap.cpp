/*--------------------------------------------------------------------------

	FG_Bitmap.cpp - λͼ�ؼ����ʵ���ļ�

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
 *  \brief λͼ�ؼ����ʵ���ļ�
*/

/*! @} */

#include "FG_Bitmap.h"

BEGIN_MESSAGE_MAP(FG_Bitmap, FG_Widget)
    ON_DRAW         (FG_Bitmap::OnDraw)
END_MESSAGE_MAP()

//##ModelId=3F5DE0D00284
void FG_Bitmap::OnDraw(FG_OSAdaptor * pAdaptor)
{
	pAdaptor->BeginDraw(m_Rect);

	FG_TextWidget::OnDraw(pAdaptor);

    if (TextLength())
    {
	    FG_Rect rect;
	    GetClientRect(rect);
	    pAdaptor->DrawBitmap(GetText(), rect.wLeft, rect.wTop);
    }

	pAdaptor->EndDraw();
}

