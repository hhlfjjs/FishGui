/*--------------------------------------------------------------------------

	FG_Screen.cpp - 屏幕类的实现文件

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
 *  \brief 屏幕类的实现文件
 *
*/

/*! @} */

#include "FG_Screen.h"
#include "FG_Factory.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
BEGIN_MESSAGE_MAP(FG_Screen, FG_Container)
    ON_DRAWREQUEST  (FG_Screen::OnDrawRequest)
    ON_TIMER        (TIMERID_DRAW, FG_Screen::OnDrawTimer)
END_MESSAGE_MAP()

//##ModelId=3F57524C0393
FG_Screen * FG_Screen::m_pScreen = NULL;

FG_Screen * FG_GetScreen()
{
    return FG_Screen::GetScreen();
}

FG_Factory * FG_GetFactory()
{
    return FG_Screen::GetScreen()->GetFactory();
}

void FG_SetFactory(FG_Factory * pFactory)
{
    FG_Screen::GetScreen()->SetFactory(pFactory);
}

//##ModelId=3F57524C03BA
FG_Screen * FG_Screen::GetScreen()
{
    if (! m_pScreen)
    {
        FG_Rect rect(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
        m_pScreen = new FG_Screen(rect);
    }
    return m_pScreen;
}

void FG_Screen::SetFactory(FG_Factory * pFactory)
{ 
    // 释放此前设置的工厂对象
    if (m_pFactory)
        delete m_pFactory;
    m_pFactory = pFactory;
}

//##ModelId=3F71AB1F0386
void FG_Screen::DeleteScreen(void)
{
    if (m_pScreen)
        delete m_pScreen;
}

//##ModelId=3F57524D0036
FG_Screen::FG_Screen(const FG_Rect & Rect) : FG_Container(Rect, 0, FS_NONE)
{
    BGColor(COLOR_BLACK);

    m_pFactory = new FG_Factory();

    FG_GetAdaptor()->SetMsgObserver(FG_MSG_DRAW, this);
    FG_GetAdaptor()->SetMsgObserver(FG_MSG_KEY, this);
    FG_GetAdaptor()->SetMsgObserver(FG_MSG_MOUSE, this);
}

//##ModelId=3F71AB20003E
FG_Screen::~FG_Screen()
{
    if (m_pFactory)
        delete m_pFactory;
}

bool FG_Screen::AddWindow(FG_Window * pWindow)
{
    if (AddChild(pWindow))
    {
        FG_OBJECTLIST::back_iterator pLast = m_ObjectList.Last();
        pLast ++;
        FG_Message Msg(FG_MSG_FOCUS, FFS_LOSE);
        if (! 
            pLast.IsDone())
            pLast->Message(& Msg);

        Msg.wType = FG_MSG_FOCUS;
        Msg.wData = FFS_GET;
        pLast = m_ObjectList.Last();
        pLast->Message(& Msg);
        return true;
    }
    else
        return false;
}

bool FG_Screen::RemoveWindow(FG_Window * pWindow)
{
    FG_OBJECTLIST::back_iterator pLast = m_ObjectList.Last();
    if (RemoveChild(pWindow))
    {
        FG_OBJECTLIST::back_iterator pNewLast = m_ObjectList.Last();
        if (! pNewLast.IsDone() && pNewLast != pLast)
        {
            FG_Message Msg(FG_MSG_FOCUS, FFS_GET);
            pNewLast->Message(& Msg);
        }
        DrawAllWindow();
        return true;
    }
    else
        return false;
}

//##ModelId=3F57524C03C5
void FG_Screen::OSMessage(FG_Message * pMsg)
{
    switch (pMsg->wType)
    {
    case FG_MSG_DRAW:
        DrawAllWindow();
        break;
    case FG_MSG_KEY:
        m_ObjectList.Last()->Message(pMsg);
        break;
    case FG_MSG_MOUSE:
        {
            if (m_ObjectList.Last()->IsContains(pMsg->Point))
                m_ObjectList.Last()->Message(pMsg);
        }
        break;
    }
}

//##ModelId=3F6193A70319
void FG_Screen::OnDrawRequest(FG_Message * pMsg)
{
    // 对于窗口对象发来的重画请求，并不直接重画，而是启动一个时间为\ref SCREEN_DRAW_INTERVAL（50毫秒）的定时器，
    // 定时器到期时才执行重画操作，该定时器在删除之前只能被成功一次，因此50 毫秒内只会发生一次重画操作，
    // 提高了重画的效率，不会引起闪烁感
    StartTimer(TIMERID_DRAW, SCREEN_DRAW_INTERVAL);
}

//##ModelId=3F71AB1F03C2
void FG_Screen::OnDrawTimer(void)
{
    DrawAllWindow();
    KillTimer(TIMERID_DRAW);
}

//##ModelId=3F6193A70337
void FG_Screen::DrawAllWindow()
{
    FG_OSAdaptor * pAdaptor = FG_GetAdaptor();
    if (! pAdaptor)
        return;

    pAdaptor->BeginDraw(m_Rect);

    FG_Container::OnDraw(pAdaptor);

    FG_OBJECTLIST::forward_iterator i;
    for (i = m_ObjectList.First(); ! i.IsDone(); ++ i)
    {
        FG_Message Msg(FG_MSG_DRAW);
        i->Message(& Msg);
    }

    pAdaptor->EndDraw();
}

