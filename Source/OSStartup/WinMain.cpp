/*--------------------------------------------------------------------------

	WinMain.cpp - Windows�������ļ�

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
/*! \file
 *  \brief Windows�������ļ�
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
        MessageBox(NULL, "�Ҳ���λͼĿ¼'FishGUI/Win32_Bmp'!\n", "����", MB_OK | MB_ICONSTOP);
        return 0;
    }

    char * pEnd = strstr(pFishGUI, "\\");
    if (! pEnd)
    {
        MessageBox(NULL, "�Ҳ���λͼĿ¼'FishGUI/Win32_Bmp'!\n", "����", MB_OK | MB_ICONSTOP);
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

