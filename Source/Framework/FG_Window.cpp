/*--------------------------------------------------------------------------

	FG_Window.cpp - 窗口类的实现文件

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
 *  \brief 窗口类的实现文件
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
    
// VC++下只需要写：
//     ON_DRAW         (OnDraw)
// gcc更严格，必须加类名
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
            // 把焦点切换到刚添加的控件
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
        // 如果删除的是当前焦点控件，把焦点指针置为NULL
        // 之后，用户需要自己调整焦点
        ChangeFocus(NULL);
    }
    if (RemoveChild(pWidget))
    {
        // 要求重画
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
            // 给失去焦点的控件发送焦点失去消息
            Msg.wData = FFS_LOSE;
		    m_pFocus->Message(& Msg);
        }
	    m_pFocus = pWidget;
	    if (m_pFocus)
        {
            // 给得到焦点的控件发送焦点得到消息
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
        // 画标题
        FG_Rect Rect;
        FG_Object::GetClientRect(Rect);
        Rect.wBottom = Rect.wTop + TITLE_HEIGHT;
        pAdaptor->FillRect(Rect, COLOR_BLUE, COLOR_BLUE);
        pAdaptor->DrawText(m_Title.DataGet(), Rect.wLeft + 2, Rect.wTop + 1, COLOR_WHITE);
    }

    // 按照覆盖顺序把FG_MSG_DRAW消息发送给每个子控件，要求他们重画自己
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
    //  - 如果本窗口为焦点窗口
    //      - 直接发送FG_MSG_DRAW消息给要求重画控件，使其重画自己
    //  - 否则
    //      - 给屏幕对象发送要求重画消息\ref FG_MSG_DRAW_REQUEST
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
        // TAB键，按顺序切换焦点
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
        // 发送给快捷键管理器处理
        // 如果不是快捷键（快捷键管理器未处理），发送给当前焦点窗口
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
    // 把该消息发送给鼠标指针所在的窗口元素，并且使该窗口元素得到焦点
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

