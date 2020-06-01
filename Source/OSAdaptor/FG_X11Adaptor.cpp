/*--------------------------------------------------------------------------

	FG_X11Adaptor.cpp - X11的适配器类的实现文件

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
/*! \addtogroup OSAdaptor
 *  @{ 
 */

/*! \file
 *  \brief X11的适配器类的实现文件
 */

/*! @} */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "FG_X11DrawInterface.h"
#include "FG_X11Adaptor.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
COLORVAL COLOR_BLACK;
COLORVAL COLOR_GRAY;
COLORVAL COLOR_WHITE;
COLORVAL COLOR_DARKGRAY;
COLORVAL COLOR_BLUE;
COLORVAL COLOR_BLUE1;
COLORVAL COLOR_RED;

//##ModelId=3F6EB00003E2
bool FG_X11Adaptor::InitInstance()
{
    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        printf("Failed to open display\n");
        return 0;
    }

    screen = DefaultScreen(display);
    Window rootwin = RootWindow(display, screen);
    win = XCreateSimpleWindow(display, rootwin, 10, 10, SCREEN_WIDTH, SCREEN_HEIGHT, 5,
                              BlackPixel(display, screen), BlackPixel(display, screen));

    static XSizeHints size_hints;
    size_hints.flags = PSize | PMinSize | PMaxSize;
    size_hints.min_width = SCREEN_WIDTH;
    size_hints.max_width = SCREEN_WIDTH;
    size_hints.min_height = SCREEN_HEIGHT;
    size_hints.max_height = SCREEN_HEIGHT;

    char szAppName[] = "FishGUI Win32 Simulator";
    char * icon_name = "window";
    XSetStandardProperties(display, win, szAppName, icon_name, None, 0, 0, & size_hints); 

    XSelectInput(display, win, ExposureMask | ButtonPressMask | KeyPressMask | ButtonReleaseMask | KeyReleaseMask);
    XMapWindow(display, win);

    m_pDraw = new FG_X11DrawInterface(win, display, screen);

    FG_Message Msg(FG_MSG_STARTUP);
    SendMsg(& Msg);

    return true;
}

//##ModelId=3F6EB00003E3
bool FG_X11Adaptor::ExitInstance()
{
    delete m_pDraw;
	XCloseDisplay(display);
    return true;
}

//##ModelId=3F6EB00003E4
bool FG_X11Adaptor::Execute()
{
    XEvent xev;
    int i, num_events;
    timeval last_tv = {0, 0};
    timeval tv;

    while (1)
    {
        gettimeofday(& tv, NULL);
        if (tv.tv_sec > last_tv.tv_sec || tv.tv_usec - last_tv.tv_usec > 50000)
        {
            FG_Message Msg(FG_MSG_TIMER);
            FG_GetAdaptor()->SendMsg(& Msg);
            last_tv = tv;
        }
    	XFlush(display);
    	num_events = XPending(display);
    	while((num_events != 0))
    	{
    		num_events--;
    		XNextEvent(display, &xev);
    		process_event(xev);
    	}
    }
    return true;
}

//##ModelId=40925CB001FE
void FG_X11Adaptor::SetXpmPath(const char * pPath)
{
    char * env = getenv("HOME_FISHGUI");
    if (env)
    {
        strcpy(XpmPath, env);
        if (XpmPath[strlen(XpmPath) - 1] == '/')
            XpmPath[strlen(XpmPath) - 1] = 0;
    }
    else
    {
        if (pPath[0] == '/')
        {
            strcpy(XpmPath, pPath);
        }
        else
        {
            getcwd(XpmPath, MAXPATHLEN);
            strcat(XpmPath, "/");
            strcat(XpmPath, pPath);
        }
    
        char * pFishGUI = strstr(XpmPath, "FishGUI");
        if (! pFishGUI)
        {
            printf("找不到位图目录'FishGUI/X11_Xpm'\n");
            exit(0);
        }
        char * pEnd = strstr(pFishGUI, "/");
        if (! pEnd)
        {
            printf("找不到位图目录'FishGUI/X11_Xpm'\n");
            exit(0);
        }
        * pEnd = 0;
    }
    strcat(XpmPath, "/X11_Xpm");
}
    
//##ModelId=40925CB00226
void FG_X11Adaptor::DrawBitmap(const char * pBmpName, const short x1, const short y1)
{
    char name[MAXPATHLEN + 1];
    sprintf(name, "%s/%s.xpm", XpmPath, pBmpName);
    
    m_pDraw->DrawBitmap(name, x1, y1);
}
    
//##ModelId=3F6EB0010005
void FG_X11Adaptor::process_event(XEvent report)
{
	switch(report.type)
	{
	    case Expose:
	        {
                FG_Message Msg(FG_MSG_DRAW);
                FG_GetAdaptor()->SendMsg(& Msg);
            }
	        break;
		case KeyPress:
		    {
                KeySym key = XLookupKeysym(& report.xkey, 0);
                FG_Message Msg(FG_MSG_KEY, FKS_DOWN);
                if (key >= '0' && key <= '9')
                    Msg.lData = key;
                else if (key >= 'a' && key <= 'z')
                    Msg.lData = key - 'a' + 'A';
                else if (key == XK_Return)
                    Msg.lData = FVK_ENTER;
                else if (key == XK_Left)
                    Msg.lData = FVK_LEFT;
                else if (key == XK_Right)
                    Msg.lData = FVK_RIGHT;
                else if (key == XK_Delete)
                    Msg.lData = FVK_DELETE;
                else if (key == XK_Tab)
                    Msg.lData = FVK_TAB;
                FG_GetAdaptor()->SendMsg(& Msg);
            }
			break;

		case KeyRelease:
		    {
    			KeySym key = XLookupKeysym(& report.xkey, 0);
                FG_Message Msg(FG_MSG_KEY, FKS_UP);
                if (key >= '0' && key <= '9')
                    Msg.lData = key;
                else if (key >= 'a' && key <= 'z')
                    Msg.lData = key - 'a' + 'A';
                else if (key == XK_Return)
                    Msg.lData = FVK_ENTER;
                else if (key == XK_Left)
                    Msg.lData = FVK_LEFT;
                else if (key == XK_Right)
                    Msg.lData = FVK_RIGHT;
                else if (key == XK_Delete)
                    Msg.lData = FVK_DELETE;
                else if (key == XK_Tab)
                    Msg.lData = FVK_TAB;
                FG_GetAdaptor()->SendMsg(& Msg);
            }
			break;

		case ButtonPress:
			if (report.xbutton.button == 1)
			{
                FG_Message Msg(FG_MSG_MOUSE, FMS_LBUTTONDOWN);
                Msg.Point.x = (WORD)report.xbutton.x;
                Msg.Point.y = (WORD)report.xbutton.y;
                FG_GetAdaptor()->SendMsg(& Msg);
			}
			break;

		case ButtonRelease:
			if (report.xbutton.button == 1)
			{
                FG_Message Msg(FG_MSG_MOUSE, FMS_LBUTTONUP);
                Msg.Point.x = (WORD)report.xbutton.x;
                Msg.Point.y = (WORD)report.xbutton.y;
                FG_GetAdaptor()->SendMsg(& Msg);
			}
			break;

		default:
			break;
	}
}

