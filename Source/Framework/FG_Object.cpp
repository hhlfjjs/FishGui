/*--------------------------------------------------------------------------

	FG_Object.cpp - ����Ԫ�����ʵ���ļ�

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
 *  \brief ����Ԫ�����ʵ���ļ�
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
    // ���ݱ߿����ȥ��ͬ�ı߿��С
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
    // ͨ���麯���õ��������Ϣӳ���ָ��
    const FG_MSGMAP * pMsgMap = GetMessageMap();

    // �ӱ��������ѭ��������Ϣӳ���ֱ���ҵ�����Ϣ���򵽴����Ļ���
    for ( ; pMsgMap; pMsgMap = pMsgMap->m_pBaseMsgMap)
    {
        // ��һ����Ϣӳ����в��Ҹ���Ϣ
        const FG_MSGMAP_ENTRY * lpEntry = pMsgMap->FindMsgCallback(pMsg->wType, pMsg->wData, pMsg->wID);
        if (lpEntry->m_Callback)
        {
            // ������Ϣ���ͷַ���Ϣ
            switch (pMsg->wType)
            {
            case FG_MSG_DRAW:
                {
                    FG_OSAdaptor * pAdaptor = FG_GetAdaptor();
                    if (! pAdaptor)
                        return false;
                    // ����Ϣ��������ָ��ǿ��ת������ȷ������
                    FG_PMSG_vd pfn = (FG_PMSG_vd)lpEntry->m_Callback;
                    // ������Ϣ������
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

