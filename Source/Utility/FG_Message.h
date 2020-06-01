/*--------------------------------------------------------------------------

	FG_Message.h -  消息类型定义头文件

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
 *  \brief 消息类型定义头文件
 *
 *  该文件中定义FishGUI框架系统中用到的所有的消息类型和消息结构
 */

#ifndef FG_MESSAGE_H_HEADER_INCLUDED_C0B10BA4
#define FG_MESSAGE_H_HEADER_INCLUDED_C0B10BA4

#include "FG_Point.h"

//##ModelId=40BB6FFD03A9
/*! \brief 消息类型的枚举类型
 *
 *  实际的存储类型为\ref WORD
 */
enum FG_MSG_TYPE
{
    FG_MSG_STARTUP,         /*!< \brief 系统启动消息 */
    FG_MSG_HALT,            /*!< \brief 系统停止消息 */
    FG_MSG_DRAW,            /*!< \brief 屏幕刷新或窗口元素重画消息 */
    FG_MSG_KEY,             /*!< \brief 键盘消息 */ 
    FG_MSG_MOUSE,           /*!< \brief 鼠标消息 */
    FG_MSG_TIMER,           /*!< \brief 定时器消息 */
                            // 以上为所有的系统消息
    /*! \brief 系统内部使用，不是一个消息类型，表示最大的系统消息个数，
     *  之前为所有的系统消息，之后为内部消息 */
    FG_MAX_SYS_MSG,

    /*! \brief 请求重画消息，控件需要重画时向窗口发送此消息，窗口需要重画时向屏幕发送此消息，
     *  由屏幕根据该窗口是否是焦点窗口来决定如何重画 */
    FG_MSG_DRAW_REQUEST,

    FG_MSG_FOCUS,           /*!< \brief 焦点切换消息 */
    FG_MSG_NOTIFY,          /*!< \brief 通知消息 */
    FG_MSG_UPDATE_VIEW      /*!< \brief MVC模式的视图更新消息 */
};

/*! \brief 键盘状态
 *
 *  对于键盘类型的消息有效，实际的存储类型为\ref WORD，放入\ref FG_Message::wData中，0为保留值
 */
//##ModelId=40BB6FFD0308
enum FG_KEY_STATUS
{
    FKS_NONE = 0,           /*!< \brief 保留状态 */
    FKS_DOWN,               /*!< \brief 键盘按下状态 */
    FKS_UP                  /*!< \brief 键盘弹起状态 */
};

/*! \addtogroup Virtual_Key 虚拟键码
 *  @{ 
 */
const WORD FVK_0        = 0x30;           /*!< \brief '0' */
const WORD FVK_1        = 0x31;           /*!< \brief '1' */
const WORD FVK_2        = 0x32;           /*!< \brief '2' */
const WORD FVK_3        = 0x33;           /*!< \brief '3' */
const WORD FVK_4        = 0x34;           /*!< \brief '4' */
const WORD FVK_5        = 0x35;           /*!< \brief '5' */
const WORD FVK_6        = 0x36;           /*!< \brief '6' */
const WORD FVK_7        = 0x37;           /*!< \brief '7' */
const WORD FVK_8        = 0x38;           /*!< \brief '8' */
const WORD FVK_9        = 0x39;           /*!< \brief '9' */
const WORD FVK_A        = 0x41;           /*!< \brief 'A' */
// B.C.D......
const WORD FVK_Z        = 0x5a;           /*!< \brief 'Z' */

const WORD FVK_ENTER    = 0x8000;         /*!< \brief ENTER */
const WORD FVK_DELETE   = 0x8001;         /*!< \brief DELETE */
const WORD FVK_LEFT     = 0x8002;         /*!< \brief LEFT */
const WORD FVK_RIGHT    = 0x8003;         /*!< \brief RIGHT */
const WORD FVK_TAB      = 0x8004;         /*!< \brief TAB */
/* @} */

/*! \brief 鼠标状态
 *
 *  对于鼠标类型的消息有效，实际的存储类型为\ref WORD，放入\ref FG_Message::wData中，0为保留值
 */
//##ModelId=40BB6FFD0363
enum FG_MOUSE_STATUS
{
    FMS_NONE = 0,           /*!< \brief 保留状态 */
    FMS_LBUTTONDOWN,        /*!< \brief 鼠标左键按下状态 */
    FMS_LBUTTONUP           /*!< \brief 鼠标左键弹起状态 */
};

/*! \brief 焦点状态
 *
 *  对于焦点类型的消息有效，实际的存储类型为\ref WORD，放入\ref FG_Message::wData中，0为保留值
 */
//##ModelId=40BB6FFD02B8
enum FG_FOCUS_STATUS
{
    FFS_NONE = 0,           /*!< \brief 保留状态 */
    FFS_GET,                /*!< \brief 得到焦点状态 */
    FFS_LOSE                /*!< \brief 失去焦点状态 */
};

/*! \brief 通知消息ID
 *
 *  对于通知消息有效，实际的存储类型为\ref WORD，放入\ref FG_Message::wData中，0为保留值
 */
//##ModelId=40BB6FFE0007
enum FG_NOTIFY_ID
{
    FN_NONE = 0,           /*!< \brief 保留状态 */
    // CheckBox通知消息
    FBN_PRESSED,           /*!< \brief 按钮控件按下状态 */
    
    // CheckBox通知消息
    FCN_CHECKED,           /*!< \brief 选择按钮控件被选中状态 */
    FCN_UNCHECKED,         /*!< \brief 选择按钮控件被取消选中状态 */
    
    // RadioButton通知消息
    FRN_CHECKED,           /*!< \brief 收音机按钮控件被选中状态 */
    FRN_UNCHECKED          /*!< \brief 收音机按钮控件被取消选中状态 */
};

//##ModelId=3F603B29014A
/*! \brief 消息结构
 *
 *  该结构封装系统中传递的所有消息
 */
struct FG_Message
{
    //##ModelId=3F603B2902C9
    /*! \brief 缺省构造函数 */
    FG_Message() 
        : wType(0), wData(0), wID(0), lData(0) {}

    //##ModelId=3F603B2902D0
    /*! \brief 构造函数
     *
     *  \param type 消息类型
     */
    FG_Message(WORD type) 
        : wType(type), wData(0), wID(0), lData(0) {}

    //##ModelId=3F6167C1034C
    /*! \brief 构造函数
     *
     *  \param type 消息类型
     *  \param data 消息带的WORD型数据
     */
    FG_Message(WORD type, WORD data) 
        : wType(type), wData(data), wID(0), lData(0) {}

    //##ModelId=3F6167C1036A
    /*! \brief 构造函数
     *
     *  \param type 消息类型
     *  \param data 消息带的WORD型数据
     *  \param id 通知消息的发送者ID
     */
    FG_Message(WORD type, WORD data, WORD id) 
        : wType(type), wData(data), wID(id), lData(0) {}

    //##ModelId=3F6167C10325
    WORD wType;                   /*!< \brief 消息类型 */
    //##ModelId=3F603B2902C0
    WORD wData;                   /*!< \brief WORD型的数据，保存键盘消息状态、鼠标消息状态或通知消息 */
    //##ModelId=3F6167C10339
    WORD wID;                     /*!< \brief 通知消息的发送者ID */
    union
    {
        void *      pData;        /*!< \brief 用户数据指针 */
        DWORD       lData;        /*!< \brief DWORD型用户数据 */
        FG_Point    Point;        /*!< \brief 鼠标位置，只对鼠标消息有效 */
    };
};

#endif /* FG_MESSAGE_H_HEADER_INCLUDED_C0B10BA4 */

/*! @} */

