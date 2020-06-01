/*--------------------------------------------------------------------------

	FG_Button.cpp - ��ť�ؼ����ʵ���ļ�

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
 *  \brief ��ť�ؼ����ʵ���ļ�
*/

/*! @} */

#include "../OSAdaptor/FG_OSAdaptor.h"
#include "FG_Button.h"

BEGIN_MESSAGE_MAP(FG_Button, FG_TextWidget)
    ON_DRAW         (FG_Button::OnDraw)
    ON_KEYDOWN      (FG_Button::OnKeyDown)
    ON_KEYUP        (FG_Button::OnKeyUp)
    ON_LBUTTONDOWN  (FG_Button::OnLButtonDown)
    ON_LBUTTONUP    (FG_Button::OnLButtonUp)
    ON_TIMER        (FG_Button::TIMERID_UP, FG_Button::OnTimerUp)
END_MESSAGE_MAP()

//##ModelId=3F71AE3103C2
void FG_Button::OnDraw(FG_OSAdaptor * pAdaptor)
{
    pAdaptor->BeginDraw(m_Rect);
    
    FG_TextWidget::OnDraw(pAdaptor);

    if (TextLength())
    {
        // ���ư�ť�ı�
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

//##ModelId=3F71AE3103D6
bool FG_Button::OnKeyDown(FG_Message * pMsg)
{
    if (pMsg->lData == FVK_ENTER)
    {
        if (FrameStyle() == FS_RAISED)
        {
            FrameStyle(FS_RECESSED);
            RequestDraw();
        }
        return true;
    }
    return false;
}

//##ModelId=3F71AE320002
bool FG_Button::OnKeyUp(FG_Message * pMsg)
{
    if (pMsg->lData == FVK_ENTER)
    {
        if (FrameStyle() == FS_RECESSED)
        {
            FrameStyle(FS_RAISED);
            RequestDraw();
        	NotifyParent(FBN_PRESSED);
        }
        return true;
    }
    return false;
}

//##ModelId=3F71AE320016
bool FG_Button::OnLButtonDown(FG_Message * pMsg)
{
    if (FrameStyle() == FS_RAISED)
    {
        FrameStyle(FS_RECESSED);
        RequestDraw();
        StartTimer(TIMERID_UP, BUTTON_UP_INTERVAL);
    }
    return true;
}

//##ModelId=3F71AE32002A
bool FG_Button::OnLButtonUp(FG_Message * pMsg)
{
    if (FrameStyle() == FS_RECESSED)
    {
        FrameStyle(FS_RAISED);
        RequestDraw();
        KillTimer(TIMERID_UP);
      	NotifyParent(FBN_PRESSED);
    }
    return true;
}

//##ModelId=3F71AE32003E
void FG_Button::OnTimerUp()
{
	FrameStyle(FS_RAISED);
    RequestDraw();
	KillTimer(TIMERID_UP);
  	NotifyParent(FBN_PRESSED);
}

