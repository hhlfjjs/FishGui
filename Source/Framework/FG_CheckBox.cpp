/*--------------------------------------------------------------------------

	FG_CheckBox.cpp - 选择按钮类的实现文件

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
 *  \brief 选择按钮类的实现文件
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

	// 绘制位图
	if (m_bChecked)
        pAdaptor->DrawBitmap("Check_EC", rect.wLeft, y + 1);
	else
        pAdaptor->DrawBitmap("Check_ENC", rect.wLeft, y + 1);

	// 绘制文本
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

