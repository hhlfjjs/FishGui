/*--------------------------------------------------------------------------

	MyButton.cpp - �û������Բ�Ǿ������ʵ���ļ�

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
 *  \brief �û������Բ�Ǿ������ʵ���ļ�
 */

/*! @} */

#include "MyButton.h"

BEGIN_MESSAGE_MAP(MyButton, FG_Button)
    ON_DRAW         (MyButton::OnDraw)
END_MESSAGE_MAP()

//##ModelId=3F71AB03038F
void MyButton::OnDraw(FG_OSAdaptor * pAdaptor)
{
    pAdaptor->BeginDraw(m_Rect);
    
	FG_Point p[6];
    FG_Rect Rect;
    switch(m_wStyle & FS_MASK)
    {
    case  FS_RAISED:
        Rect = m_Rect;
        pAdaptor->FillRect(Rect, m_Background, m_Background);

		p[0].x = p[1].x = m_Rect.wLeft;
		p[0].y = m_Rect.wBottom - 4;
		p[1].y = m_Rect.wTop + 3;
        p[2].x = m_Rect.wLeft + 3;
		p[2].y = p[3].y = m_Rect.wTop;
		p[3].x = m_Rect.wRight - 3;
		pAdaptor->DrawPolyLine(4, p, COLOR_GRAY);

        // ��������
		p[0].x = p[1].x = m_Rect.wLeft + 1;
		p[0].y = m_Rect.wBottom - 5;
        p[1].y = m_Rect.wTop + 4;
        p[2].x = m_Rect.wLeft + 4;
		p[2].y = p[3].y = m_Rect.wTop + 1;
		p[3].x = m_Rect.wRight - 4;
		pAdaptor->DrawPolyLine(4, p, COLOR_WHITE);

        // ���ڱ߿�
        p[0].x = m_Rect.wRight - 4;
        p[0].y = m_Rect.wTop + 1;
        p[1].x = p[2].x = m_Rect.wRight - 1;
        p[1].y = m_Rect.wTop + 4;
        p[2].y = m_Rect.wBottom - 4;
        p[3].x = m_Rect.wRight - 4;
        p[3].y = p[4].y = m_Rect.wBottom - 1;
        p[4].x = m_Rect.wLeft + 4;
        p[5].x = m_Rect.wLeft + 1;
        p[5].y = m_Rect.wBottom - 4;
        pAdaptor->DrawPolyLine(6, p, COLOR_DARKGRAY);

        // ����Ӱ
        p[0].x = m_Rect.wRight - 3;
        p[0].y = m_Rect.wTop;
		p[1].x = p[2].x = m_Rect.wRight;
		p[1].y = m_Rect.wTop + 3;
        p[2].y = m_Rect.wBottom - 3;
        p[3].x = m_Rect.wRight - 3;
		p[3].y = p[4].y = m_Rect.wBottom;
		p[4].x = m_Rect.wLeft + 3;
        p[5].x = m_Rect.wLeft;
        p[5].y = m_Rect.wBottom - 3;
		pAdaptor->DrawPolyLine(6, p, COLOR_BLACK);
        break;

    case FS_RECESSED:
        Rect = m_Rect;
        pAdaptor->FillRect(Rect, m_Background, m_Background);

		p[0].x = p[1].x = m_Rect.wRight - 1;
		p[0].y = m_Rect.wTop + 4;
        p[1].y = m_Rect.wBottom - 4;
        p[2].x = m_Rect.wRight - 4;
		p[2].y = p[3].y = m_Rect.wBottom - 1;
		p[3].x = m_Rect.wLeft + 4;
		pAdaptor->DrawPolyLine(4, p, COLOR_GRAY);

        // ��������
		p[0].x = p[1].x = m_Rect.wRight;
		p[0].y = m_Rect.wTop + 3;
        p[1].y = m_Rect.wBottom - 3;
        p[2].x = m_Rect.wRight - 3;
		p[2].y = p[3].y = m_Rect.wBottom;
		p[3].x = m_Rect.wLeft + 3;
		pAdaptor->DrawPolyLine(4, p, COLOR_WHITE);

        // ���ڱ߿�
        p[0].x = m_Rect.wLeft + 3;
        p[0].y = m_Rect.wBottom;
		p[1].x = p[2].x = m_Rect.wLeft;
		p[1].y = m_Rect.wBottom - 3;
        p[2].y = m_Rect.wTop + 3;
        p[3].x = m_Rect.wLeft + 3;
		p[3].y = p[4].y = m_Rect.wTop;
		p[4].x = m_Rect.wRight - 3;
        p[5].x = m_Rect.wRight;
        p[5].y = m_Rect.wTop + 3;
		pAdaptor->DrawPolyLine(6, p, COLOR_DARKGRAY);

        // ����Ӱ
        p[0].x = m_Rect.wLeft + 4;
        p[0].y = m_Rect.wBottom - 1;
		p[1].x = p[2].x = m_Rect.wLeft + 1;
		p[1].y = m_Rect.wBottom - 4;
        p[2].y = m_Rect.wTop + 4;
        p[3].x = m_Rect.wLeft + 4;
		p[3].y = p[4].y = m_Rect.wTop + 1;
		p[4].x = m_Rect.wRight - 4;
        p[5].x = m_Rect.wRight - 1;
        p[5].y = m_Rect.wTop + 4;
		pAdaptor->DrawPolyLine(6, p, COLOR_BLACK);
        break;

    default:
        break;
    }

    if (TextLength())
    {
        // д��ť����
        WORD x = m_Rect.wLeft + (m_Rect.wRight - m_Rect.wLeft + 1 - pAdaptor->GetTextWidth(GetText())) / 2;
        WORD y = m_Rect.wTop + (m_Rect.wBottom - m_Rect.wTop + 1 - pAdaptor->GetTextHeight(GetText())) / 2;
        pAdaptor->DrawText(GetText(), x, y, m_ForeColor);
        if (IsFocus())
        {
            FG_Rect rect;
            GetClientRect(rect);
            rect -= 1;
            pAdaptor->DrawDotRect(rect, COLOR_BLACK);
        }
    }

    pAdaptor->EndDraw();
}

