/*--------------------------------------------------------------------------

	FG_Edit.h - 编辑控件类的实现文件

	本程序是FishGUI软件的一部分

	版权所有 (C) 2003,2004 王咏武
	http://www.contextfree.net/wangyw/

----------------------------------------------------------------------------

	作者对 FishGUI 软件及其所有源代码授权如下：

	允许任何个人、组织、机构、企业无偿获得、修改、使用、重新发布 FishGUI 软
	件及其源代码，或按照有偿或者无偿的方式发行基于 FishGUI 源代码的全部或部
	分内容开发的软件产品，——但行使以上权利时，须遵守以下约定：

	1、重新发布 FishGUI 软件及其源代码时，不得隐去软件及其源代码中原有的版
	   权信息和开发者标识。

	2、发行基于 FishGUI 源代码的全部或部分内容开发的软件产品时，必须在产品
	   的显著位置标明以下字样：

	   【本产品的一部分功能是基于王咏武在 FishGUI 软件中的工作完成的】

	3、在正式出版物中引用 FishGUI 的文档、源代码或注释内容的，应注明软件的
	   原作者为王咏武。

--------------------------------------------------------------------------*/
/*! \addtogroup Framework
 *  @{ 
 */

/*! \file
 *  \brief 编辑控件类的实现文件
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
		// 画光标
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
    // 特殊处理\ref FVK_DELETE、\ref FVK_LEFT、\ref FVK_RIGHT等键，输入数字0--9
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

