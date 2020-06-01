/*--------------------------------------------------------------------------

	FG_Label.cpp - ���ֱ�ǩ���ʵ���ļ�

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
 *  \brief ���ֱ�ǩ���ʵ���ļ�
 */

/*! @} */

#include "FG_Label.h"

BEGIN_MESSAGE_MAP(FG_Label, FG_TextWidget)
    ON_DRAW         (FG_Label::OnDraw)
END_MESSAGE_MAP()

//##ModelId=3F5EE86B00C6
void FG_Label::OnDraw(FG_OSAdaptor * pAdaptor)
{
	pAdaptor->BeginDraw(m_Rect);

	FG_TextWidget::OnDraw(pAdaptor);

	if (TextLength())
	{
        // �����ı�
		FG_Rect rect;
		GetClientRect(rect);
		WORD x;
		if (m_wStyle & TS_LEFT)
			x = rect.wLeft + 1;
		else if (m_wStyle & TS_CENTER)
			x = rect.wLeft + (rect.wRight - rect.wLeft + 1 - pAdaptor->GetTextWidth(GetText())) / 2;
		else
			x = rect.wRight - pAdaptor->GetTextWidth(m_Text.DataGet());
		WORD y = rect.wTop + (rect.wBottom - rect.wTop + 1 - pAdaptor->GetTextHeight(GetText())) / 2;
		pAdaptor->DrawText(GetText(), x, y, m_ForeColor);
	}

	pAdaptor->EndDraw();
}

