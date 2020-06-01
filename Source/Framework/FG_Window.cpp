/*--------------------------------------------------------------------------

	FG_Window.cpp - �������ʵ���ļ�

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
 *  \brief �������ʵ���ļ�
 *
*/

/*! @} */

#include "../OSAdaptor/FG_OSAdaptor.h"
#include "FG_Screen.h"
#include "FG_Window.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
// VC++��ֻ��Ҫд��
//     ON_DRAW         (OnDraw)
// gcc���ϸ񣬱��������
BEGIN_MESSAGE_MAP(FG_Window, FG_Container)
    ON_DRAW         (FG_Window::OnDraw)
    ON_KEY          (FG_Window::OnKey)
    ON_MOUSE        (FG_Window::OnMouse)
    ON_DRAWREQUEST  (FG_Window::OnDrawRequest)
    ON_FOCUS        (FG_Window::OnFocus)
END_MESSAGE_MAP()

bool FG_Window::AddWidget(FG_Widget * const pWidget)
{
    if (AddChild(pWidget))
    {
        if (pWidget->CanGetFocus())
        {
            // �ѽ����л�������ӵĿؼ�
	        ChangeFocus(pWidget);
        }
        return true;
    }
    else
        return false;
}

bool FG_Window::RemoveWidget(FG_Widget * pWidget)
{
    if (m_pFocus && m_pFocus == pWidget)
    {		            
        // ���ɾ�����ǵ�ǰ����ؼ����ѽ���ָ����ΪNULL
        // ֮���û���Ҫ�Լ���������
        ChangeFocus(NULL);
    }
    if (RemoveChild(pWidget))
    {
        // Ҫ���ػ�
        RequestDraw();
        return true;
    }
    else
        return false;
}

//##ModelId=3F6193A800D6
void FG_Window::GetClientRect(FG_Rect & rect) const
{
	FG_Object::GetClientRect(rect);
	if (m_Title.Length())
		rect.wTop += TITLE_HEIGHT;
}

//##ModelId=3F6193A800F4
void FG_Window::ChangeFocus(FG_Widget * const pWidget)
{
    if (! pWidget || (pWidget && pWidget->CanGetFocus()))
    {
        FG_Message Msg(FG_MSG_FOCUS);
	    if (m_pFocus)
        {
            // ��ʧȥ����Ŀؼ����ͽ���ʧȥ��Ϣ
            Msg.wData = FFS_LOSE;
		    m_pFocus->Message(& Msg);
        }
	    m_pFocus = pWidget;
	    if (m_pFocus)
        {
            // ���õ�����Ŀؼ����ͽ���õ���Ϣ
            Msg.wData = FFS_GET;
		    m_pFocus->Message(& Msg);
        }
    }
}

bool FG_Window::RegisterKey(const WORD wOrgKey, const WORD wActKey, const WORD wID)
{
    FG_Widget * pTarget = (FG_Widget *)GetChild(wID);
    if (pTarget)
    {
        bool ret = m_KeyMap.RegisterKey(wOrgKey, wActKey, pTarget); 
        if (ret)
        {
            pTarget->SetCanGetFocus(false);
            if (pTarget == m_pFocus)
                ChangeFocus(NULL);
        }
        return ret;
    }
    else
        return false;
}

//##ModelId=3F584C9403D0
void FG_Window::OnDraw(FG_OSAdaptor * pAdaptor)
{
    pAdaptor->BeginDraw(m_Rect);

    FG_Container::OnDraw(pAdaptor);

    if (m_Title.Length())
    {
        // ������
        FG_Rect Rect;
        FG_Object::GetClientRect(Rect);
        Rect.wBottom = Rect.wTop + TITLE_HEIGHT;
        pAdaptor->FillRect(Rect, COLOR_BLUE, COLOR_BLUE);
        pAdaptor->DrawText(m_Title.DataGet(), Rect.wLeft + 2, Rect.wTop + 1, COLOR_WHITE);
    }

    // ���ո���˳���FG_MSG_DRAW��Ϣ���͸�ÿ���ӿؼ���Ҫ�������ػ��Լ�
    FG_OBJECTLIST::forward_iterator i;
    for (i = m_ObjectList.First(); ! i.IsDone(); ++ i)
    {
        FG_Message Msg(FG_MSG_DRAW);
        i->Message(& Msg);
    }

    pAdaptor->EndDraw();
}

//##ModelId=3F603B980398
void FG_Window::OnDrawRequest(FG_Message * pMsg)
{
    //  - ���������Ϊ���㴰��
    //      - ֱ�ӷ���FG_MSG_DRAW��Ϣ��Ҫ���ػ��ؼ���ʹ���ػ��Լ�
    //  - ����
    //      - ����Ļ������Ҫ���ػ���Ϣ\ref FG_MSG_DRAW_REQUEST
	if (IsFocus())
	{
        FG_Object * pSender = (FG_Object *)pMsg->pData;
        FG_Message Msg(FG_MSG_DRAW);
		pSender->Message(& Msg);
	}
	else
    {
		RequestDraw();
    }
}

//##ModelId=3F5C4AEB0321
bool FG_Window::OnKey(FG_Message * pMsg)
{
    if (pMsg->lData == FVK_TAB)
    {
        // TAB������˳���л�����
        if (m_pFocus && pMsg->wData == FKS_DOWN)
        {
            FG_OBJECTLIST::loop_iterator i = m_ObjectList.Loop(m_pFocus);
            FG_CheckCanGetFocus tmp;

            if (FG_ListFind_If(i, tmp))
                ChangeFocus((FG_Widget *)(FG_Object *)i);
        }
        return true;
    }
    else
    {
        // ���͸���ݼ�����������
        // ������ǿ�ݼ�����ݼ�������δ���������͸���ǰ���㴰��
        if (m_KeyMap.SendKey(pMsg))
            return true;
        else if (m_pFocus)
            return m_pFocus->Message(pMsg);
        else
            return false;
    }
}

//##ModelId=3F5C4AEB032B
bool FG_Window::OnMouse(FG_Message * pMsg)
{
    // �Ѹ���Ϣ���͸����ָ�����ڵĴ���Ԫ�أ�����ʹ�ô���Ԫ�صõ�����
    FG_OBJECTLIST::back_iterator i;
    for (i = m_ObjectList.Last(); ! i.IsDone(); ++ i)
    {
        if (i->IsContains(pMsg->Point))
        {
            if (pMsg->wData == FMS_LBUTTONDOWN)
                ChangeFocus((FG_Widget *)(FG_Object *)i);

            if (i->Message(pMsg))
				return true;
        }
    }
    return false;
}

//##ModelId=3F6193A80162
void FG_Window::OnFocus(FG_Message * pMsg)
{
    if (m_pFocus)
        m_pFocus->Message(pMsg);

    FG_Container::OnFocus(pMsg);
}

