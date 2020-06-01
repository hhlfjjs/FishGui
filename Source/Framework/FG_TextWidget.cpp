/*--------------------------------------------------------------------------

	FG_TextWidget.cpp - �ı��ؼ��������ʵ���ļ�

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
 *  \brief �ı��ؼ��������ʵ���ļ�
*/

/*! @} */

#include "FG_TextWidget.h"

BEGIN_MESSAGE_MAP(FG_TextWidget, FG_Widget)
END_MESSAGE_MAP()

//##ModelId=3F6EAC8F01F0
void FG_TextWidget::DrawTextFocus(FG_OSAdaptor * const pAdaptor, const WORD x, const WORD y)
{
    if (IsFocus())
    {
        char * text = GetText();
        WORD w = pAdaptor->GetTextWidth(text);
        WORD h = pAdaptor->GetTextHeight(text);

        FG_Rect rect(x - 1, y - 1, x + w + 1, y + h + 1);

        pAdaptor->DrawDotRect(rect, COLOR_BLACK);
    }
}

