/*--------------------------------------------------------------------------

	FG_Object.cpp - 窗口元素类的实现文件

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
 *  \brief 窗口元素类的实现文件
 *
*/

/*! @} */

#include "../OSAdaptor/FG_OSAdaptor.h"
#include "FG_Container.h"

// message map of base object
//##ModelId=3F5C4D4103CC
const FG_MSGMAP FG_Object::m_MsgMap = { NULL, & FG_Object::m_MsgEntries[0] };
//##ModelId=3F5C4D41037C
const FG_MSGMAP_ENTRY FG_Object::m_MsgEntries[] =
{ 
    ON_DRAW        (FG_Object::OnDraw)
    ON_FOCUS       (FG_Object::OnFocus)
    { false, 0, 0, (FG_PMSG_vv)NULL } 
};

//##ModelId=3F5C4D42001F
const FG_MSGMAP * FG_Object::GetMessageMap() const
{
    return & FG_Object::m_MsgMap;
}

void FG_Object::DrawBorder(FG_OSAdaptor * pAdaptor)
{
	FG_Rect Rect;
	if (m_wStyle & GS_TRANSPARENT)
		return;

	pAdaptor->BeginDraw(m_Rect);

	FG_Point p[3];
    switch(m_wStyle & FS_MASK)
    {
    case  FS_RAISED:
        Rect = m_Rect;
        Rect -= 2;
        pAdaptor->FillRect(Rect, m_Background, m_Background);

		p[0].x = p[1].x = m_Rect.wLeft;
		p[0].y = m_Rect.wBottom - 1;
		p[1].y = p[2].y = m_Rect.wTop;
		p[2].x = m_Rect.wRight - 1;
		pAdaptor->DrawPolyLine(3, p, COLOR_GRAY);

		p[0].x = p[1].x = m_Rect.wLeft + 1;
		p[0].y = m_Rect.wBottom - 2;
		p[1].y = p[2].y = m_Rect.wTop + 1;
		p[2].x = m_Rect.wRight - 2;
		pAdaptor->DrawPolyLine(3, p, COLOR_WHITE);

		p[0].x = p[1].x = m_Rect.wRight - 1;
		p[0].y = m_Rect.wTop + 1;
		p[1].y = p[2].y = m_Rect.wBottom - 1;
		p[2].x = m_Rect.wLeft + 1;
		pAdaptor->DrawPolyLine(3, p, COLOR_DARKGRAY);

		p[0].x = p[1].x = m_Rect.wRight;
		p[0].y = m_Rect.wTop;
		p[1].y = p[2].y = m_Rect.wBottom;
		p[2].x = m_Rect.wLeft;
		pAdaptor->DrawPolyLine(3, p, COLOR_BLACK);
        break;

    case FS_RECESSED:
        Rect = m_Rect;
        Rect -= 2;
        pAdaptor->FillRect(Rect, m_Background, m_Background);

		p[0].x = p[1].x = m_Rect.wRight - 1;
		p[0].y = m_Rect.wTop + 1;
		p[1].y = p[2].y = m_Rect.wBottom - 1;
		p[2].x = m_Rect.wLeft + 1;
		pAdaptor->DrawPolyLine(3, p, COLOR_GRAY);

		p[0].x = p[1].x = m_Rect.wRight;
		p[0].y = m_Rect.wTop;
		p[1].y = p[2].y = m_Rect.wBottom;
		p[2].x = m_Rect.wLeft;
		pAdaptor->DrawPolyLine(3, p, COLOR_WHITE);

		p[0].x = p[1].x = m_Rect.wLeft;
		p[0].y = m_Rect.wBottom - 1;
		p[1].y = p[2].y = m_Rect.wTop;
		p[2].x = m_Rect.wRight - 1;
		pAdaptor->DrawPolyLine(3, p, COLOR_DARKGRAY);

		p[0].x = p[1].x = m_Rect.wLeft + 1;
		p[0].y = m_Rect.wBottom - 2;
		p[1].y = p[2].y = m_Rect.wTop + 1;
		p[2].x = m_Rect.wRight - 2;
		pAdaptor->DrawPolyLine(3, p, COLOR_BLACK);
        break;

    case FS_THIN:
        pAdaptor->FillRect(m_Rect, COLOR_BLACK, m_Background);
        break;

    case FS_NONE:
        pAdaptor->FillRect(m_Rect, m_Background, m_Background);
        break;

    default:
        break;
    }

	pAdaptor->EndDraw();
}

void FG_Object::GetClientRect(FG_Rect & rect) const
{
    // 根据边框风格除去不同的边框大小
	switch (m_wStyle & FS_MASK)
	{
	case FS_RAISED:
	case FS_RECESSED:
		rect = m_Rect;
		rect -= 2;
		break;
	case FS_THIN:
		rect = m_Rect;
		rect -= 1;
		break;
	case FS_NONE:
		rect = m_Rect;
		break;
	default:
		rect.Set(0, 0, 0, 0);
		break;
	}
}

bool FG_Object::Message(FG_Message * pMsg)
{
    // 通过虚函数得到该类的消息映射表指针
    const FG_MSGMAP * pMsgMap = GetMessageMap();

    // 从本类向基类循环查找消息映射表，直到找到该消息，或到达最后的基类
    for ( ; pMsgMap; pMsgMap = pMsgMap->m_pBaseMsgMap)
    {
        // 在一个消息映射表中查找该消息
        const FG_MSGMAP_ENTRY * lpEntry = pMsgMap->FindMsgCallback(pMsg->wType, pMsg->wData, pMsg->wID);
        if (lpEntry->m_Callback)
        {
            // 根据消息类型分发消息
            switch (pMsg->wType)
            {
            case FG_MSG_DRAW:
                {
                    FG_OSAdaptor * pAdaptor = FG_GetAdaptor();
                    if (! pAdaptor)
                        return false;
                    // 把消息处理函数的指针强制转换成正确的类型
                    FG_PMSG_vd pfn = (FG_PMSG_vd)lpEntry->m_Callback;
                    // 调用消息处理函数
                    (this->*pfn)(pAdaptor);
                }
                return true;
            case FG_MSG_KEY:
            case FG_MSG_MOUSE:
                {
                    FG_PMSG_bm pfn = (FG_PMSG_bm)lpEntry->m_Callback;
                    return (this->*pfn)(pMsg);
                }
            case FG_MSG_FOCUS:
            case FG_MSG_DRAW_REQUEST:
                {
                    FG_PMSG_vm pfn = (FG_PMSG_vm)lpEntry->m_Callback;
                    (this->*pfn)(pMsg);
                }
                return true;
            case FG_MSG_TIMER:
            case FG_MSG_UPDATE_VIEW:
                (this->*(lpEntry->m_Callback))();
                return true;
            case FG_MSG_NOTIFY:
                if (lpEntry->m_wID)
                    (this->*(lpEntry->m_Callback))();
                else
                {
                    FG_PMSG_vm pfn = (FG_PMSG_vm)lpEntry->m_Callback;
                    (this->*pfn)(pMsg);
                }
                return true;
            default:
                return false;;
            }
        }
    }
    return false;
}

void FG_Object::NotifyParent(WORD wNotification)
{
    if (m_pParent)
    {
        FG_Message Msg(FG_MSG_NOTIFY, wNotification, ID());
        m_pParent->Message(& Msg);
    }
}

void FG_Object::RequestDraw()
{
    if (m_pParent)
    {
        FG_Message Msg(FG_MSG_DRAW_REQUEST);
        Msg.lData = (DWORD)this;
        m_pParent->Message(& Msg);
    }
}

//##ModelId=3F6EAC8F0128
void FG_Object::OnFocus(FG_Message * pMsg)
{
    if (pMsg->wData == FFS_LOSE)
        ResetFocus();
    else
        SetFocus();

    RequestDraw();
}

