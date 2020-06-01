/*--------------------------------------------------------------------------

	MyButton.cpp - 用户定义的圆角矩形类的实现文件

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
/*! \addtogroup Application
 *  @{ 
 */

/*! \file
 *  \brief 用户定义的圆角矩形类的实现文件
 */

/*! @} */

#include "MyButton.h"

BEGIN_MESSAGE_MAP(MyButton, FG_Button)
    ON_DRAW         (MyButton::OnDraw)
END_MESSAGE_MAP()

//##ModelId=3F71AB03038F
void MyButton::OnDraw(FG_OSAdaptor * pAdaptor)
{
    pAdaptor->BeginDraw(m_Rect);
    
	FG_Point p[6];
    FG_Rect Rect;
    switch(m_wStyle & FS_MASK)
    {
    case  FS_RAISED:
        Rect = m_Rect;
        pAdaptor->FillRect(Rect, m_Background, m_Background);

		p[0].x = p[1].x = m_Rect.wLeft;
		p[0].y = m_Rect.wBottom - 4;
		p[1].y = m_Rect.wTop + 3;
        p[2].x = m_Rect.wLeft + 3;
		p[2].y = p[3].y = m_Rect.wTop;
		p[3].x = m_Rect.wRight - 3;
		pAdaptor->DrawPolyLine(4, p, COLOR_GRAY);

        // 画高亮区
		p[0].x = p[1].x = m_Rect.wLeft + 1;
		p[0].y = m_Rect.wBottom - 5;
        p[1].y = m_Rect.wTop + 4;
        p[2].x = m_Rect.wLeft + 4;
		p[2].y = p[3].y = m_Rect.wTop + 1;
		p[3].x = m_Rect.wRight - 4;
		pAdaptor->DrawPolyLine(4, p, COLOR_WHITE);

        // 画黑边框
        p[0].x = m_Rect.wRight - 4;
        p[0].y = m_Rect.wTop + 1;
        p[1].x = p[2].x = m_Rect.wRight - 1;
        p[1].y = m_Rect.wTop + 4;
        p[2].y = m_Rect.wBottom - 4;
        p[3].x = m_Rect.wRight - 4;
        p[3].y = p[4].y = m_Rect.wBottom - 1;
        p[4].x = m_Rect.wLeft + 4;
        p[5].x = m_Rect.wLeft + 1;
        p[5].y = m_Rect.wBottom - 4;
        pAdaptor->DrawPolyLine(6, p, COLOR_DARKGRAY);

        // 画阴影
        p[0].x = m_Rect.wRight - 3;
        p[0].y = m_Rect.wTop;
		p[1].x = p[2].x = m_Rect.wRight;
		p[1].y = m_Rect.wTop + 3;
        p[2].y = m_Rect.wBottom - 3;
        p[3].x = m_Rect.wRight - 3;
		p[3].y = p[4].y = m_Rect.wBottom;
		p[4].x = m_Rect.wLeft + 3;
        p[5].x = m_Rect.wLeft;
        p[5].y = m_Rect.wBottom - 3;
		pAdaptor->DrawPolyLine(6, p, COLOR_BLACK);
        break;

    case FS_RECESSED:
        Rect = m_Rect;
        pAdaptor->FillRect(Rect, m_Background, m_Background);

		p[0].x = p[1].x = m_Rect.wRight - 1;
		p[0].y = m_Rect.wTop + 4;
        p[1].y = m_Rect.wBottom - 4;
        p[2].x = m_Rect.wRight - 4;
		p[2].y = p[3].y = m_Rect.wBottom - 1;
		p[3].x = m_Rect.wLeft + 4;
		pAdaptor->DrawPolyLine(4, p, COLOR_GRAY);

        // 画高亮区
		p[0].x = p[1].x = m_Rect.wRight;
		p[0].y = m_Rect.wTop + 3;
        p[1].y = m_Rect.wBottom - 3;
        p[2].x = m_Rect.wRight - 3;
		p[2].y = p[3].y = m_Rect.wBottom;
		p[3].x = m_Rect.wLeft + 3;
		pAdaptor->DrawPolyLine(4, p, COLOR_WHITE);

        // 画黑边框
        p[0].x = m_Rect.wLeft + 3;
        p[0].y = m_Rect.wBottom;
		p[1].x = p[2].x = m_Rect.wLeft;
		p[1].y = m_Rect.wBottom - 3;
        p[2].y = m_Rect.wTop + 3;
        p[3].x = m_Rect.wLeft + 3;
		p[3].y = p[4].y = m_Rect.wTop;
		p[4].x = m_Rect.wRight - 3;
        p[5].x = m_Rect.wRight;
        p[5].y = m_Rect.wTop + 3;
		pAdaptor->DrawPolyLine(6, p, COLOR_DARKGRAY);

        // 画阴影
        p[0].x = m_Rect.wLeft + 4;
        p[0].y = m_Rect.wBottom - 1;
		p[1].x = p[2].x = m_Rect.wLeft + 1;
		p[1].y = m_Rect.wBottom - 4;
        p[2].y = m_Rect.wTop + 4;
        p[3].x = m_Rect.wLeft + 4;
		p[3].y = p[4].y = m_Rect.wTop + 1;
		p[4].x = m_Rect.wRight - 4;
        p[5].x = m_Rect.wRight - 1;
        p[5].y = m_Rect.wTop + 4;
		pAdaptor->DrawPolyLine(6, p, COLOR_BLACK);
        break;

    default:
        break;
    }

    if (TextLength())
    {
        // 写按钮文字
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

