/*--------------------------------------------------------------------------

	FG_Group.cpp - 分组控件类的实现文件

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
 *  \brief 分组控件类的实现文件
 */

/*! @} */

#include "FG_Group.h"

BEGIN_MESSAGE_MAP(FG_Group, FG_TextWidget)
    ON_DRAW         (FG_Group::OnDraw)
END_MESSAGE_MAP()

//##ModelId=3F6193A701A6
void FG_Group::OnDraw(FG_OSAdaptor * pAdaptor)
{
	pAdaptor->BeginDraw(m_Rect);

	FG_Widget::OnDraw(pAdaptor);

	if (TextLength())
	{
        // 画标题
		FG_Rect rect;
		GetClientRect(rect);
		WORD x;
		x = pAdaptor->GetTextWidth(GetText());

		// 画边框
		FG_Point p[6];
		p[0].y = p[1].y = p[4].y = p[5].y = rect.wTop + 6;
		p[0].x = rect.wLeft + 16;
		p[1].x = p[2].x = rect.wLeft;
		p[2].y = p[3].y = rect.wBottom - 1;
		p[3].x = p[4].x = rect.wRight - 1;
		p[5].x = rect.wLeft + 20 + x;
		pAdaptor->DrawPolyLine(6, p, COLOR_DARKGRAY);

		p[0].y = p[1].y = rect.wTop + 7;
		p[0].x = rect.wLeft + 16;
        p[1].x = p[2].x = rect.wLeft + 1;
        p[2].y = rect.wBottom - 2;
        pAdaptor->DrawPolyLine(3, p, COLOR_WHITE);

        p[0].y = p[1].y = rect.wBottom;
        p[0].x = rect.wLeft;
        p[1].x = p[2].x = rect.wRight;
        p[2].y = rect.wTop + 6;
        pAdaptor->DrawPolyLine(3, p, COLOR_WHITE);

        pAdaptor->Line(rect.wLeft + 20 + x, rect.wTop + 7, rect.wRight - 2, rect.wTop + 7, COLOR_WHITE);

        pAdaptor->DrawText(GetText(), rect.wLeft+18, rect.wTop+1, m_ForeColor);
	}

	pAdaptor->EndDraw();
}

