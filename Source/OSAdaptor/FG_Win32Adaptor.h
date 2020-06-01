/*--------------------------------------------------------------------------

	FG_Win32Adaptor.h - Win32的适配器类的头文件

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
 *  \brief Win32的适配器类的头文件
 */

#ifndef FG_WIN32ADAPTOR_H_HEADER_INCLUDED_C0B1A8C2
#define FG_WIN32ADAPTOR_H_HEADER_INCLUDED_C0B1A8C2

#include "windows.h"
#include "FG_OSAdaptor.h"
class FG_Win32DrawInterface;

//##ModelId=3F49CC120210
/*! \brief Win32的适配器类
 *
 *  该类封装Win32操作系统的程序启动和运行过程
 */
class FG_Win32Adaptor : public FG_OSAdaptor
{
public:
    //##ModelId=3F4E099D01F1
    /*! \brief 程序初始化
     *
     *  调用Win32函数注册窗口类，创建窗口，刷新窗口\n
     *  发送\ref FG_MSG_STARTUP消息
     *  \return 初始化是否成功\n
     *          true    成功\n
     *          false   失败
     */
    bool InitInstance();

    //##ModelId=3F4E09F802BB
    /*! \brief 程序退出
     *
     *  发送\ref FG_MSG_HALT消息，释放对象
     *  \return 退出是否成功\n
     *          true    成功\n
     *          false   失败
     */
    bool ExitInstance();

    //##ModelId=3F4E09F8031F
    /*! \brief 程序运行过程，执行消息循环
     *
     *  执行Win32的消息循环
     *  \return 退出是否成功\n
     *          true    成功\n
     *          false   失败
     */
    bool Execute();

    //##ModelId=3F6EAFFE01EA
    /*! \brief 设置当前应用程序的实例句柄
     *
     *  \param hInst 当前应用程序的实例句柄
     */
    void SetInst(HINSTANCE hInst) { m_hInst = hInst; }

    //##ModelId=3F6EAFFE024E
    /*! \brief 设置前一个应用程序的实例句柄
     *
     *  \param hPrevInst 前一个应用程序的实例句柄
     */
    void SetPrevInst(HINSTANCE hPrevInst) { m_hPrevInst = hPrevInst; }

    //##ModelId=3F6EAFFE02B2
    /*! \brief 设置窗口的显示方式
     *
     *  \param nCmdShow 窗口的显示方式
     */
    void SetCmdShow(int nCmdShow) { m_nCmdShow = nCmdShow; }

    //##ModelId=40925CB0009F
    /*! \brief 设置位图文件所在目录的绝对路径
     *
     *  \param pPath FishGUI主目录的绝对路径，通过GetModuleFileName函数调用得到
     *  \param len 字符串pPath的长度，字符串不保证有0结束符
     */
    void SetBmpPath(char * pPath, int len);

    //##ModelId=40925CB000E5
    /*! \brief 绘制位图
     *
     *  Win32适配器类覆盖该函数，把位图名组合成位图文件的绝对路径名，然后代理调用\ref FG_OSDrawInterface::DrawBitmap
     *  \param pBmpName 要绘制的位图名
     *  \param x1 位图左上角的横坐标
     *  \param y1 位图左上角的纵坐标
     */
    virtual void DrawBitmap(const char * pBmpName, const short x1, const short y1);

protected:
    friend class FG_OSAdaptor;

    //##ModelId=3F4EB7140009
    /*! \brief Win32适配器类的缺省构造函数 */
    FG_Win32Adaptor() : m_hInst(0), m_hPrevInst(0), m_nCmdShow() {}

    //##ModelId=3F6EAFFE00F0
                                            /*!< \brief 当前应用程序的实例句柄 */
    HINSTANCE m_hInst, m_hPrevInst;         /*!< \brief 前一个应用程序的实例句柄 */

    //##ModelId=3F6EAFFE0172
    int m_nCmdShow;                         /*!< \brief 窗口的显示方式 */

    //##ModelId=40925CAF03E7
    char m_BmpPath[MAX_PATH + 1];           /*!< \brief 位图文件所在目录的绝对路径 */

    //##ModelId=3F6EAFFE0335
    /*! \brief Win32窗口函数
     *
     *  必须静态函数，该函数接收系统消息，然后通过观查者模式发送给框架层
     *  \param hWnd 窗口句柄
     *  \param uMessage 消息类型
     *  \param wParam 消息参数
     *  \param lParam 消息参数
     *  \return long 消息处理结果
     */
    static long FAR WINAPI WndProc(HWND hWnd, UINT uMessage, UINT wParam, LONG lParam);
};

#endif /* FG_WIN32ADAPTOR_H_HEADER_INCLUDED_C0B1A8C2 */

/*! @} */

