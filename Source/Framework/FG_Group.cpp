/*--------------------------------------------------------------------------

	FG_Group.cpp - ����ؼ����ʵ���ļ�

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
 *  \brief ����ؼ����ʵ���ļ�
 */

/*! @} */

#include "FG_Group.h"

BEGIN_MESSAGE_MAP(FG_Group, FG_TextWidget)
    ON_DRAW         (FG_Group::OnDraw)
END_MESSAGE_MAP()

//##ModelId=3F6193A701A6
void FG_Group::OnDraw(FG_OSAdaptor * pAdaptor)
{
	pAdaptor->BeginDraw(m_Rect);

	FG_Widget::OnDraw(pAdaptor);

	if (TextLength())
	{
        // ������
		FG_Rect rect;
		GetClientRect(rect);
		WORD x;
		x = pAdaptor->GetTextWidth(GetText());

		// ���߿�
		FG_Point p[6];
		p[0].y = p[1].y = p[4].y = p[5].y = rect.wTop + 6;
		p[0].x = rect.wLeft + 16;
		p[1].x = p[2].x = rect.wLeft;
		p[2].y = p[3].y = rect.wBottom - 1;
		p[3].x = p[4].x = rect.wRight - 1;
		p[5].x = rect.wLeft + 20 + x;
		pAdaptor->DrawPolyLine(6, p, COLOR_DARKGRAY);

		p[0].y = p[1].y = rect.wTop + 7;
		p[0].x = rect.wLeft + 16;
        p[1].x = p[2].x = rect.wLeft + 1;
        p[2].y = rect.wBottom - 2;
        pAdaptor->DrawPolyLine(3, p, COLOR_WHITE);

        p[0].y = p[1].y = rect.wBottom;
        p[0].x = rect.wLeft;
        p[1].x = p[2].x = rect.wRight;
        p[2].y = rect.wTop + 6;
        pAdaptor->DrawPolyLine(3, p, COLOR_WHITE);

        pAdaptor->Line(rect.wLeft + 20 + x, rect.wTop + 7, rect.wRight - 2, rect.wTop + 7, COLOR_WHITE);

        pAdaptor->DrawText(GetText(), rect.wLeft+18, rect.wTop+1, m_ForeColor);
	}

	pAdaptor->EndDraw();
}

