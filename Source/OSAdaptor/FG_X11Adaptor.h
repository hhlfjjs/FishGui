/*--------------------------------------------------------------------------

	FG_X11Adaptor.h - X11的适配器类的头文件

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
 *  \brief X11的适配器类的头文件
 */

#ifndef FG_X11ADAPTOR_H_HEADER_INCLUDED_C0B1A8C3
#define FG_X11ADAPTOR_H_HEADER_INCLUDED_C0B1A8C3

#include <sys/param.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "FG_OSAdaptor.h"

class FG_X11DrawInterface;

//##ModelId=3F6EAFFE00A0
/*! \brief X11的适配器类
 *
 *  该类封装X11操作系统的程序启动和运行过程
 */
class FG_X11Adaptor : public FG_OSAdaptor
{
public:
    //##ModelId=3F6EB00003E2
    /*! \brief 程序初始化
     *
     *  调用X11函数打开X11显示设备，创建窗口\n
     *  发送\ref FG_MSG_STARTUP消息
     *  \return 初始化是否成功\n
     *          true    成功\n
     *          false   失败
     */
    bool InitInstance();

    //##ModelId=3F6EB00003E3
    /*! \brief 程序退出
     *
     *  关闭X11显示设备，释放对象
     *  \return 退出是否成功\n
     *          true    成功\n
     *          false   失败
     */
    bool ExitInstance();

    //##ModelId=3F6EB00003E4
    /*! \brief 程序运行过程，执行消息循环
     *
     *  执行X11的消息循环
     *  \return 退出是否成功\n
     *          true    成功\n
     *          false   失败
     */
    bool Execute();
    
    //##ModelId=40925CB001FE
    /*! \brief 设置位图文件所在目录的绝对路径
     *
     *  两种方法得到FishGUI主目录的绝对路径
     *      - 从环境变量HOME_FISHGUI中得到
     *      - 从程序运行时argv[0]所带的运行程序路径和当前路径组合得到\n
     *
     *  第二种方法在不同的环境中不能保证一定能得到位图文件所在目录的绝对路径，
     *  这种情况下用户必须设置环境变量HOME_FISHGUI
     *  
     *  \param pPath argv[0]所带的运行程序路径
     */
    void SetXpmPath(const char * pPath);
    
    //##ModelId=40925CB00226
    /*! \brief 绘制位图
     *
     *  X11适配器类覆盖该函数，把位图名组合成位图文件的绝对路径名，然后代理调用\ref FG_OSDrawInterface::DrawBitmap
     *  \param pBmpName 要绘制的位图名
     *  \param x1 位图左上角的横坐标
     *  \param y1 位图左上角的纵坐标
     */
    virtual void DrawBitmap(const char * pBmpName, const short x1, const short y1);
    
protected:
    friend class FG_OSAdaptor;

    //##ModelId=3F6EB0010004
    /*! \brief X11适配器类的缺省构造函数 */
    FG_X11Adaptor() {}

private:
    //##ModelId=3F6EB0010005
    /*! \brief X11事件处理函数
     *
     *  该函数接收系统消息，然后通过观查者模式发送给框架层
     *  \param report 接收到的事件
     */
    void process_event(XEvent report);

    //##ModelId=3F6EB00003C5
    Display * display;                      /*!< \brief X11显示设备 */

    //##ModelId=3F6EB00003CE
    int screen;                             /*!< \brief X11缺省屏幕号 */
    
    //##ModelId=3F6EB00003D8
    Window win;                             /*!< \brief X11窗口结构 */
    
    //##ModelId=40925CB001CC
    char XpmPath[MAXPATHLEN + 1];           /*!< \brief 位图文件所在目录的绝对路径 */
};

#endif /* FG_X11ADAPTOR_H_HEADER_INCLUDED_C0B1A8C3 */

/*! @} */

