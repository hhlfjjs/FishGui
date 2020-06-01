/*--------------------------------------------------------------------------

	FG_Edit.h - �༭�ؼ����ʵ���ļ�

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
 *  \brief �༭�ؼ����ʵ���ļ�
 */

/*! @} */

#include "string.h"
#include "FG_Window.h"
#include "FG_Edit.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
BEGIN_MESSAGE_MAP(FG_Edit, FG_Label)
    ON_DRAW         (FG_Edit::OnDraw)
    ON_KEYDOWN      (FG_Edit::OnKeyDown)
    ON_MOUSE        (FG_Edit::OnMouse)
    ON_TIMER        (TIMERID_CURSOR, FG_Edit::OnCursorTimer)
    ON_FOCUS        (FG_Edit::OnFocus)
END_MESSAGE_MAP()

//##ModelId=3F65E8E20322
FG_Edit::FG_Edit(const char * Text, const FG_Rect & Rect, const WORD wLimit, const WORD wID, const WORD wStyle)
	: m_wLimit(wLimit), FG_Label(Text, Rect, wID, wStyle)
{
	BGColor(COLOR_WHITE);
	if (Text)
		m_wCursorPos = strlen(Text);
	else
		m_wCursorPos = 0;
	m_bDrawCursor = true;
	StartTimer(TIMERID_CURSOR, EDIT_CURSOR_INTERVAL);
}

//##ModelId=3F65E8E20368
void FG_Edit::OnDraw(FG_OSAdaptor * pAdaptor)
{
	pAdaptor->BeginDraw(m_Rect);

	FG_Label::OnDraw(pAdaptor);

	if (IsFocus() && m_bDrawCursor)
	{
		// �����
		FG_Rect rect;
		GetClientRect(rect);
		char * temp = new char[m_wCursorPos + 1];
		memcpy(temp, GetText(), m_wCursorPos);
		temp[m_wCursorPos] = 0;
		
		WORD width;
		if (m_wCursorPos)
			width = pAdaptor->GetTextWidth(temp);
		else
			width = 1;
		WORD x = rect.wLeft + width;
		WORD height;
		if (m_wCursorPos)
			height = pAdaptor->GetTextHeight(temp);
		else
			height = pAdaptor->GetTextHeight("A");
		WORD y = rect.wTop + (rect.wBottom - rect.wTop + 1 - height) / 2;
		pAdaptor->Line(x, y, x, y + height, COLOR_BLACK);
		delete [] temp;
	}

	pAdaptor->EndDraw();
}

//##ModelId=3F65E8E2037C
bool FG_Edit::OnKeyDown(FG_Message * pMsg)
{
    // ���⴦��\ref FVK_DELETE��\ref FVK_LEFT��\ref FVK_RIGHT�ȼ�����������0--9
    if (pMsg->lData >= FVK_0 && pMsg->lData <= FVK_9)
    {
        if (TextLength() < m_wLimit)
            InsertChar((WORD)pMsg->lData);
		return true;
	}
    else if (pMsg->lData == FVK_DELETE)
    {
        DeleteChar();
		return true;
	}
    else if (pMsg->lData == FVK_LEFT)
    {
        if (m_wCursorPos > 0)
        {
            m_wCursorPos --;
            DrawWithCursor();
        }
        return true;
    }
    else if (pMsg->lData == FVK_RIGHT)
    {
        if (m_wCursorPos < TextLength())
        {
            m_wCursorPos ++;
            DrawWithCursor();
        }
        return true;
	}
	else
		return false;
}

//##ModelId=3F65E8E203AF
void FG_Edit::OnCursorTimer(void)
{
    if (IsFocus())
    {
	    m_bDrawCursor = ! m_bDrawCursor;
	    RequestDraw();
    }
}

//##ModelId=3F65E8E203B9
void FG_Edit::OnFocus(FG_Message * pMsg)
{
    if (pMsg->wData == FFS_GET)
        m_bDrawCursor = true;
    else
        m_bDrawCursor = false;

    FG_Label::OnFocus(pMsg);
}

//##ModelId=3F65E8E2039A
bool FG_Edit::OnMouse(FG_Message * pMsg)
{
	if (m_pParent)
		((FG_Window *)m_pParent)->ChangeFocus(this);
	return true;
}

//##ModelId=3F65E8E203D7
void FG_Edit::InsertChar(WORD wKey)
{
	WORD length = TextLength();
	char * temp = new char[length + 2];
	
	memcpy(temp, GetText(), m_wCursorPos);
	temp[m_wCursorPos] = (char)wKey;
	memcpy(temp + m_wCursorPos + 1, GetText() + m_wCursorPos, TextLength() - m_wCursorPos);
	temp[length + 1] = 0;
	SetText(temp);
	m_wCursorPos ++;
	delete [] temp;
	
	DrawWithCursor();
}

//##ModelId=3F65E8E30003
void FG_Edit::DeleteChar(void)
{
	if (m_wCursorPos < TextLength())
	{
		WORD length = TextLength();
		if (length > 1)
		{
			char * temp = new char[length];
			
			memcpy(temp, m_Text.DataGet(), m_wCursorPos);
			memcpy(temp + m_wCursorPos, GetText() + m_wCursorPos + 1, TextLength() - m_wCursorPos - 1);
			temp[length - 1] = 0;
			m_Text.DataSet(temp);
			delete []temp;
		}
		else
			m_Text.DataSet(NULL);

		DrawWithCursor();
	}
}

//##ModelId=3F65E8E30017
void FG_Edit::DrawWithCursor(void)
{
	m_bDrawCursor = true;
	RequestDraw();
}

