/*--------------------------------------------------------------------------

	WinMain.cpp - Windows的启动文件

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
/*! \file
 *  \brief Windows的启动文件
*/

#include "windows.h"
#include <crtdbg.h>
#include "../OSAdaptor/FG_Win32Adaptor.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
/*! \brief WinMain
 *
 *  \param hInstance 
 *  \param hPrevInstance 
 *  \param pCmd 
 *  \param nCmdShow 
 *  \return int WINAPI 
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmd, int nCmdShow)
{
#if defined(WIN32) && defined(_DEBUG)
    int tmpDbgFlag;

    tmpDbgFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    tmpDbgFlag |= _CRTDBG_DELAY_FREE_MEM_DF;
    tmpDbgFlag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(tmpDbgFlag);
#endif  /* _DEBUG */

    char Name[MAX_PATH + 1];
    GetModuleFileName(NULL, Name, MAX_PATH);
    for (WORD i = 0; i < strlen(Name); i ++)
        Name[i] = toupper(Name[i]);

    char * pFishGUI = strstr(Name, "FISHGUI");
    if (! pFishGUI)
    {
        MessageBox(NULL, "找不到位图目录'FishGUI/Win32_Bmp'!\n", "错误", MB_OK | MB_ICONSTOP);
        return 0;
    }

    char * pEnd = strstr(pFishGUI, "\\");
    if (! pEnd)
    {
        MessageBox(NULL, "找不到位图目录'FishGUI/Win32_Bmp'!\n", "错误", MB_OK | MB_ICONSTOP);
        return 0;
    }
    short length = pEnd - Name;

    FG_Win32Adaptor * pAdp = (FG_Win32Adaptor *)FG_GetAdaptor();
    pAdp->SetBmpPath(Name, length);

    pAdp->SetInst(hInstance);
    pAdp->SetPrevInst(hPrevInstance);
    pAdp->SetCmdShow(nCmdShow);
    pAdp->Run();

    return 0;
}

