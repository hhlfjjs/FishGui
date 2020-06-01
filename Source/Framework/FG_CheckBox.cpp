/*--------------------------------------------------------------------------

	FG_CheckBox.cpp - ѡ��ť���ʵ���ļ�

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
 *  \brief ѡ��ť���ʵ���ļ�
 */

/*! @} */

#include "FG_CheckBox.h"

BEGIN_MESSAGE_MAP(FG_CheckBox, FG_TextWidget)
    ON_DRAW         (FG_CheckBox::OnDraw)
    ON_KEYDOWN      (FG_CheckBox::OnKeyDown)
    ON_LBUTTONDOWN  (FG_CheckBox::OnLButtonDown)
END_MESSAGE_MAP()

//##ModelId=3F65E8E20228
void FG_CheckBox::OnDraw(FG_OSAdaptor * pAdaptor)
{
	pAdaptor->BeginDraw(m_Rect);

	FG_TextWidget::OnDraw(pAdaptor);

	FG_Rect rect;
	GetClientRect(rect);
	WORD y = rect.wTop + (rect.wBottom - rect.wTop + 1 - pAdaptor->GetTextHeight(GetText())) / 2;

	// ����λͼ
	if (m_bChecked)
        pAdaptor->DrawBitmap("Check_EC", rect.wLeft, y + 1);
	else
        pAdaptor->DrawBitmap("Check_ENC", rect.wLeft, y + 1);

	// �����ı�
	if (TextLength())
	{
		WORD x = rect.wLeft + 15;
        pAdaptor->DrawText(GetText(), x, y, m_ForeColor);
        DrawTextFocus(pAdaptor, x, y);
	}

	pAdaptor->EndDraw();
}

//##ModelId=3F65E8E2023C
bool FG_CheckBox::OnKeyDown(FG_Message * pMsg)
{
    if (pMsg->lData == FVK_ENTER)
    {
        m_bChecked = ! m_bChecked;
        RequestDraw();
        if (m_bChecked)
            NotifyParent(FCN_CHECKED);
        else
            NotifyParent(FCN_UNCHECKED);
        return true;
    }
    else
        return false;
}

//##ModelId=3F65E8E20247
bool FG_CheckBox::OnLButtonDown(FG_Message * pMsg)
{
    m_bChecked = ! m_bChecked;
    RequestDraw();
    if (m_bChecked)
        NotifyParent(FCN_CHECKED);
    else
        NotifyParent(FCN_UNCHECKED);
    return true;
}

