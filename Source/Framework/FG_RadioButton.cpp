/*--------------------------------------------------------------------------

	RadioButton.cpp - 收音机按钮类的实现文件

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
 *  \brief 收音机按钮类的实现文件
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

	// 绘制位图
	if (m_bChecked)
        pAdaptor->DrawBitmap("Radio_EC", rect.wLeft, y + 2);
	else
        pAdaptor->DrawBitmap("Radio_ENC", rect.wLeft, y + 2);

	// 绘制文本
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

