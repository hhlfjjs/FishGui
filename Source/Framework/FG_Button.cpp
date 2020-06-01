/*--------------------------------------------------------------------------

	FG_Button.cpp - 按钮控件类的实现文件

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
 *  \brief 按钮控件类的实现文件
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
        // 绘制按钮文本
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

