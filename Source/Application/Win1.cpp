/*--------------------------------------------------------------------------

	Win1.cpp - 用户定义的窗口1类的实现文件

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
 *  \brief 用户定义的窗口1类的实现文件
 */

/*! @} */

#include <stdio.h>
#include <string.h>
#include "Win1.h"
#include "Win2.h"

BEGIN_MESSAGE_MAP(Win1, FG_Window)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_START, Win1::OnStart)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_STOP, Win1::OnStop)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_OPEN, Win1::OnOpen)
    ON_ID_NOTIFY    (FBN_PRESSED, ID_CLOSE, Win1::OnClose)
    ON_TIMER        (ID_ANIMATION_TIMER, Win1::OnTimer)
END_MESSAGE_MAP()

/*! \addtogroup Application
 *  @{ 
 */

    /*! \addtogroup Win1_Rect 窗口1用到的矩形区域定义
     *  @{ 
     */
static const FG_Rect RECT_Win1(150, 180, 445, 460);

static const FG_Rect RECT_Group1(165, 210, 430, 400);
static const FG_Rect RECT_Bitmap(235, 229, 356, 350);
static const FG_Rect RECT_Start(205, 360, 285, 385);
static const FG_Rect RECT_Stop(305, 360, 385, 385);

static const FG_Rect RECT_Open(175, 415, 285, 440);
static const FG_Rect RECT_Close(305, 415, 425, 440);
    /*! @} */

/*! @} */

//##ModelId=3F71AB0400CA
Win1::Win1(WORD wID) : m_iBmpNum(0), m_bStart(false), FG_Window("窗口1", wID, FS_RAISED)
{
    m_Rect.Set(RECT_Win1.wLeft, RECT_Win1.wTop, RECT_Win1.wRight, RECT_Win1.wBottom);

    FG_Factory * pF = FG_GetFactory();
    AddWidget(pF->CreateGroup("动画2", RECT_Group1));
    AddWidget(pF->CreateBitmap("UnderSea", RECT_Bitmap, ID_BITMAP, FS_THIN));
    AddWidget(pF->CreateButton("启动 [S]", RECT_Start, ID_START));
    AddWidget(pF->CreateButton("停止 [T]", RECT_Stop, ID_STOP));

    AddWidget(pF->CreateButton("打开窗口2 [O]", RECT_Open, ID_OPEN));
    AddWidget(pF->CreateButton("关闭 [C]", RECT_Close, ID_CLOSE));

    RegisterKey('S', FVK_ENTER, ID_START);
    RegisterKey('T', FVK_ENTER, ID_STOP);
    RegisterKey('O', FVK_ENTER, ID_OPEN);
    RegisterKey('C', FVK_ENTER, ID_CLOSE);
}

//##ModelId=3F71AB0400DE
void Win1::OnStart(void)
{
    if (! m_bStart)
    {
        StartTimer(ID_ANIMATION_TIMER, 500);
        m_bStart = true;
    }
}

//##ModelId=3F71AB0400E9
void Win1::OnStop(void)
{
    if (m_bStart)
    {
        KillTimer(ID_ANIMATION_TIMER);
        m_bStart = false;
    }
}

//##ModelId=3F71AB0400FD
void Win1::OnOpen(void)
{
    FG_GetScreen()->AddWindow(new Win2());
}

//##ModelId=3F71AB040110
void Win1::OnClose(void)
{
    FG_GetScreen()->RemoveWindow(this);
}

//##ModelId=3F71AB040124
void Win1::OnTimer(void)
{
    if (m_bStart)
    {
        if (++ m_iBmpNum >= 2)
            m_iBmpNum = 0;
        FG_Bitmap * pBitmap = (FG_Bitmap *)GetChild(ID_BITMAP);
        switch (m_iBmpNum)
        {
        case 0:
            pBitmap->SetText("UnderSea");
            break;
        case 1:
            pBitmap->SetText("UnderSea1");
            break;
        }
    }
}

