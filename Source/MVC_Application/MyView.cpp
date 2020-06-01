/*--------------------------------------------------------------------------

	MyView.cpp - 用户定义的视图类的实现文件

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
/*! \addtogroup MVC_Application
 *  @{ 
 */

/*! \file
 *  \brief 用户定义的视图类的实现文件
 *
*/

/*! @} */

#include "MyView.h"
#include "MyModel.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
BEGIN_MESSAGE_MAP(MyView, FG_Widget)
    ON_DRAW         (MyView::OnDraw)
    ON_UPDATE_VIEW  (MyView::OnViewUpdate)
END_MESSAGE_MAP()

void MyView::OnDraw(FG_OSAdaptor * pAdaptor)
{
    pAdaptor->BeginDraw(m_Rect);

    pAdaptor->FillRect(m_Rect, COLOR_BLACK, COLOR_BLACK);

    FG_Point point[10];
    int i;
    for (i = 0; i < 10; i ++)
    {
        point[i].x = m_Rect.wLeft + GetMyModel()->GetData1(i) + 1;
        point[i].y = m_Rect.wTop + i * 30 + 1;
    }
    pAdaptor->DrawPolyLine(10, point, COLOR_BLUE1);
    
    for (i = 0; i < 10; i ++)
    {
        point[i].x = m_Rect.wLeft + GetMyModel()->GetData2(i) + 1;
        point[i].y = m_Rect.wTop + i * 30 + 1;
    }
    pAdaptor->DrawPolyLine(10, point, COLOR_RED);

    pAdaptor->EndDraw();
}

