/*--------------------------------------------------------------------------

	FG_Common.h - FishGUI公共类型定义头文件

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
/*! \addtogroup Utility
 *  @{ 
 */

/*! \file 
 *  \brief FishGUI公共类型定义头文件
 *
 *  该文件定义了FIshGUI系统的公共类型和常量，
 *  其中部分类型和常量值与操作系统相关，移植时要改变其中的某些定义。
 */

#ifndef FISHGUI_H_HEADER_INCLUDED_C0B126F2
#define FISHGUI_H_HEADER_INCLUDED_C0B126F2

#ifndef NULL
    /*! \brief 空指针的定义 */
    #define NULL               0
#endif /* NULL */

//##ModelId=3F4F05EF033B
/*! \brief 无符号字符 */
typedef unsigned char	        BYTE;

//##ModelId=3F4F05EF036D
/*! \brief 无符号短整形 */
typedef unsigned short	        WORD;

//##ModelId=3F4F05EF034F
/*! \brief 无符号长整形 */
typedef unsigned long	        DWORD;

const WORD SCREEN_WIDTH         = 800;      /*!< \brief 屏幕宽度 */
const WORD SCREEN_HEIGHT        = 600;      /*!< \brief 屏幕高度 */

/*! \defgroup Color 颜色 */
/*! @{ */
#if defined(WIN32)
    //##ModelId=3F4F05EF0345
    /*! \brief 颜色值的类型
     *
     *  移植时要根据屏幕的颜色深度改变该类型的定义\n
     */
    typedef unsigned long           COLORVAL;

    // color define
    const COLORVAL COLOR_BLACK      = 0x000000;         /*!< \brief黑色 */
    const COLORVAL COLOR_GRAY       = 0xc0c0c0;         /*!< \brief灰色 */
    const COLORVAL COLOR_WHITE      = 0xffffff;         /*!< \brief白色 */
    const COLORVAL COLOR_DARKGRAY   = 0x808080;         /*!< \brief深灰色 */
    const COLORVAL COLOR_BLUE       = 0xbf0000;         /*!< \brief浅蓝色 */
    const COLORVAL COLOR_BLUE1      = 0xff0000;         /*!< \brief蓝色 */
    const COLORVAL COLOR_RED        = 0x0000ff;         /*!< \brief红色 */
#elif defined(HAVE_LIBX11)
    typedef unsigned long           COLORVAL;

    // color define, set later
    extern COLORVAL COLOR_BLACK;
    extern COLORVAL COLOR_GRAY;
    extern COLORVAL COLOR_WHITE;
    extern COLORVAL COLOR_DARKGRAY;
    extern COLORVAL COLOR_BLUE;
    extern COLORVAL COLOR_BLUE1;
    extern COLORVAL COLOR_RED;
#endif /* WIN32 */
/*! @} */

const WORD TITLE_HEIGHT         = 20;       /*!< \brief 窗口标题的高度 */

const WORD BUTTON_UP_INTERVAL   = 1000;     /*!< \brief 按钮控件弹出的时间间隔 */
const WORD EDIT_CURSOR_INTERVAL = 500;      /*!< \brief 编辑控件光标闪烁的时间间隔 */
const WORD SCREEN_DRAW_INTERVAL = 50;       /*!< \brief 屏幕刷新的时间间隔 */

/*! \defgroup Style 风格 */
/*! @{ */

    /*! \defgroup General_Style 通用风格 */
    /*! @{ */
const WORD GS_TRANSPARENT       = 0x8000;       /*!< \brief该位设置表示为透明窗口元素 */
const WORD GS_FOCUS             = 0x4000;       /*!< \brief该位设置表示为焦点窗口元素\n该位为系统内部使用，用户不能自行设置 */
    /*! @} */

    /*! \defgroup Frame_Style 边框风格 */
    /*! @{ */
const WORD FS_NONE              = 0x0001;       /*!< \brief无任何边框 */
const WORD FS_THIN              = 0x0002;       /*!< \brief细边框 */
const WORD FS_RAISED            = 0x0004;       /*!< \brief凸起边框 */
const WORD FS_RECESSED          = 0x0008;       /*!< \brief下沉边框 */
const WORD FS_MASK              = 0x000f;       /*!< \brief边框风格的掩码 */
    /*! @} */

    /*! \defgroup Text_Justification_Style 文本对齐风格 */
    /*! @{ */
const WORD TS_RIGHT             = 0x0010;       /*!< \brief右对齐 */
const WORD TS_LEFT              = 0x0020;       /*!< \brief左对齐 */
const WORD TS_CENTER            = 0x0040;       /*!< \brief居中对齐 */
const WORD TS_MASK              = 0x0070;       /*!< \brief文本对齐风格的掩码 */
    /*! @} */

/*! @} */

#endif /* FISHGUI_H_HEADER_INCLUDED_C0B126F2 */

/*! @} */

