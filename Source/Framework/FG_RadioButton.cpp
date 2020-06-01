/*--------------------------------------------------------------------------

	RadioButton.cpp - ��������ť���ʵ���ļ�

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
 *  \brief ��������ť���ʵ���ļ�
 */

/*! @} */

#include "../Utility/FG_Utility.h"
#include "FG_RadioButton.h"

BEGIN_MESSAGE_MAP(FG_RadioButton, FG_TextWidget)
    ON_DRAW         (FG_RadioButton::OnDraw)
    ON_KEYDOWN      (FG_RadioButton::OnKeyDown)
    ON_LBUTTONDOWN  (FG_RadioButton::OnLButtonDown)
END_MESSAGE_MAP()

FG_RadioButton::FG_RadioButton(const char * Text, const FG_Rect & Rect, FG_RadioButton * const pSameGroup, const WORD wID)
: m_bChecked(false), FG_TextWidget(Text, Rect, wID, FS_NONE)
{
    if (pSameGroup)
    {
        m_pNext = pSameGroup->m_pNext;
        pSameGroup->m_pNext = this;
    }
    else
    {
        m_pNext = this;
    }
}

//##ModelId=3F65E8E3031A
void FG_RadioButton::OnDraw(FG_OSAdaptor * pAdaptor)
{
	pAdaptor->BeginDraw(m_Rect);

	FG_TextWidget::OnDraw(pAdaptor);

	FG_Rect rect;
	GetClientRect(rect);
	WORD y = rect.wTop + (rect.wBottom - rect.wTop + 1 - pAdaptor->GetTextHeight(GetText())) / 2;

	// ����λͼ
	if (m_bChecked)
        pAdaptor->DrawBitmap("Radio_EC", rect.wLeft, y + 2);
	else
        pAdaptor->DrawBitmap("Radio_ENC", rect.wLeft, y + 2);

	// �����ı�
	if (TextLength())
	{
		WORD x = rect.wLeft + 14;
        pAdaptor->DrawText(GetText(), x, y, m_ForeColor);
        DrawTextFocus(pAdaptor, x, y);
	}

	pAdaptor->EndDraw();
}

//##ModelId=3F65E8E3032E
bool FG_RadioButton::OnKeyDown(FG_Message * pMsg)
{
    if (pMsg->lData == FVK_ENTER)
    {
        UncheckGroup();
        m_bChecked = true;
        RequestDraw();
        NotifyParent(FRN_CHECKED);
        return true;
    }
    else
        return false;
}

//##ModelId=3F65E8E30342
bool FG_RadioButton::OnLButtonDown(FG_Message * pMsg)
{
    UncheckGroup();
    m_bChecked = true;
    RequestDraw();
    NotifyParent(FRN_CHECKED);
    return true;
}

//##ModelId=3F65EDEC0183
void FG_RadioButton::UncheckGroup(void)
{
    FG_RadioButton * pRadio = m_pNext;

    while (pRadio != this)
    {
        if (pRadio->m_bChecked)
        {
            pRadio->m_bChecked = false;
            pRadio->RequestDraw();
            NotifyParent(FRN_UNCHECKED);
        }
        pRadio = pRadio->m_pNext;
    }
}

