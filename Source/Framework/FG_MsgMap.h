/*--------------------------------------------------------------------------

	FG_MsgMap.h - 消息映射表结构以及宏定义的头文件

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
 *  \brief 消息映射表结构以及宏定义的头文件
*/

#ifndef FG_MSGMAP_H_HEADER_INCLUDED_C0AD453B
#define FG_MSGMAP_H_HEADER_INCLUDED_C0AD453B

#include "../Utility/FG_Utility.h"
#include "../OSAdaptor/FG_OSAdaptor.h"

/*! \defgroup MsgMap_Define 消息映射表定义宏 */
/*! @{ */

/*! \brief 定义消息映射表的宏 */
#define DECLARE_MESSAGE_MAP()                                                           \
private:                                                                                \
    static const FG_MSGMAP_ENTRY m_MsgEntries[];                                        \
protected:                                                                              \
    static const FG_MSGMAP m_MsgMap;                                                    \
    virtual const FG_MSGMAP * GetMessageMap() const;                                    \

/*! \brief 为消息映射表赋初值的宏 */
#define BEGIN_MESSAGE_MAP(theClass, baseClass)                                          \
    const FG_MSGMAP * theClass::GetMessageMap() const                                   \
        { return & theClass::m_MsgMap; }                                                \
    const FG_MSGMAP theClass::m_MsgMap =                                                \
        { & baseClass::m_MsgMap, & theClass::m_MsgEntries[0] };                         \
    const FG_MSGMAP_ENTRY theClass::m_MsgEntries[] =                                    \
    {                                                                                   \

/*! \brief 定义\ref FG_MSG_DRAW消息和处理函数的对应关系的宏 */
#define ON_DRAW(msgCallback)                                                            \
        { FG_MSG_DRAW, 0, 0, (FG_PMSG_vv)(FG_PMSG_vd)& msgCallback },                   \

/*! \brief 定义\ref FG_MSG_DRAW_REQUEST消息和处理函数的对应关系的宏 */
#define ON_DRAWREQUEST(msgCallback)                                                     \
        { FG_MSG_DRAW_REQUEST, 0, 0, (FG_PMSG_vv)(FG_PMSG_vm)& msgCallback },           \

/*! \brief 定义\ref FG_MSG_KEY消息和处理函数的对应关系的宏 */
#define ON_KEY(msgCallback)                                                             \
        { FG_MSG_KEY, 0, 0, (FG_PMSG_vv)(FG_PMSG_bm)& msgCallback },                    \

/*! \brief 定义\ref FG_MSG_KEY, \ref FKS_DOWN消息和处理函数的对应关系的宏 */
#define ON_KEYDOWN(msgCallback)                                                         \
        { FG_MSG_KEY, FKS_DOWN, 0, (FG_PMSG_vv)(FG_PMSG_bm)& msgCallback },             \

/*! \brief 定义\ref FG_MSG_KEY, \ref FKS_UP消息和处理函数的对应关系的宏 */
#define ON_KEYUP(msgCallback)                                                           \
        { FG_MSG_KEY, FKS_UP, 0, (FG_PMSG_vv)(FG_PMSG_bm)& msgCallback },               \

/*! \brief 定义\ref FG_MSG_MOUSE消息和处理函数的对应关系的宏 */
#define ON_MOUSE(msgCallback)                                                           \
        { FG_MSG_MOUSE, 0, 0, (FG_PMSG_vv)(FG_PMSG_bm)& msgCallback },                  \

/*! \brief 定义\ref FG_MSG_MOUSE, \ref FMS_LBUTTONDOWN消息和处理函数的对应关系的宏 */
#define ON_LBUTTONDOWN(msgCallback)                                                     \
        { FG_MSG_MOUSE, FMS_LBUTTONDOWN, 0, (FG_PMSG_vv)(FG_PMSG_bm)& msgCallback },    \

/*! \brief 定义\ref FG_MSG_MOUSE, \ref FMS_LBUTTONUP消息和处理函数的对应关系的宏 */
#define ON_LBUTTONUP(msgCallback)                                                       \
        { FG_MSG_MOUSE, FMS_LBUTTONUP, 0, (FG_PMSG_vv)(FG_PMSG_bm)& msgCallback },      \

/*! \brief 定义\ref FG_MSG_TIMER, timerID消息和处理函数的对应关系的宏
 * 
 *  即标识为timerID的通知消息
 */
#define ON_TIMER(timerID, msgCallback)                                                  \
        { FG_MSG_TIMER, timerID, 0, (FG_PMSG_vv)& msgCallback },                        \

/*! \brief 定义\ref FG_MSG_FOCUS消息和处理函数的对应关系的宏 */
#define ON_FOCUS(msgCallback)                                                           \
        { FG_MSG_FOCUS, 0, 0, (FG_PMSG_vv)(FG_PMSG_vm)& msgCallback },                  \

/*! \brief 定义\ref FG_MSG_NOTIFY, \ref FG_NOTIFY_ID消息和处理函数的对应关系的宏
 * 
 *  即ID为\ref FG_NOTIFY_ID的通知消息
 */
#define ON_NOTIFY(notifyID, msgCallback)                                                \
        { FG_MSG_NOTIFY, notifyID, 0, (FG_PMSG_vv)(FG_PMSG_vm)& msgCallback },          \

/*! \brief 定义\ref FG_MSG_NOTIFY, \ref FG_NOTIFY_ID, id消息和处理函数的对应关系的宏
 * 
 *  即ID为\ref FG_NOTIFY_ID的通知消息，发送通知消息的控件的唯一标识为为id
 */
#define ON_ID_NOTIFY(notifyID, id, msgCallback)                                         \
        { FG_MSG_NOTIFY, notifyID, id, (FG_PMSG_vv)& msgCallback },                     \

/*! \brief 定义\ref FG_MSG_UPDATE_VIEW消息和处理函数的对应关系的宏 */
#define ON_UPDATE_VIEW(msgCallback)                                                     \
        { FG_MSG_UPDATE_VIEW, 0, 0, (FG_PMSG_vv)& msgCallback },                        \

/*! \brief 消息映射表结束项 */
#define END_MESSAGE_MAP()                                                               \
        { 0, 0, 0, (FG_PMSG_vv)NULL }                                                   \
    };                                                                                  \

/*! @} */

class FG_Object;
struct FG_Message;

/*! \defgroup MsgHandler_Type 消息处理函数类型 */
/*! @{ */

//##ModelId=3F58381F03A7
/*! \brief 参数为void，返回值为void的消息处理函数。\n
 *  
 *  用于以下消息：
 *      - \ref FG_MSG_TIMER
 *      - \ref FG_MSG_NOTIFY, \ref FG_NOTIFY_ID, id
 *      - \ref FG_MSG_UPDATE_VIEW
 */
typedef void (FG_Object::* FG_PMSG_vv)(void);

//##ModelId=3F6193A7005C
/*! \brief 参数为\ref FG_OSAdaptor *，返回值为void的消息处理函数。\n
 *  
 *  用于以下消息：
 *      - \ref FG_MSG_DRAW
 */
typedef void (FG_Object::* FG_PMSG_vd)(FG_OSAdaptor * pAdaptor);

//##ModelId=3F5B47040163
/*! \brief 参数为\ref FG_OSAdaptor *，返回值为void的消息处理函数。\n
 *  
 *  用于以下消息：
 *      - \ref FG_MSG_DRAW_REQUEST
 *      - \ref FG_MSG_FOCUS
 *      - \ref FG_MSG_NOTIFY, notifyID
 */
typedef void (FG_Object::* FG_PMSG_vm)(FG_Message * pMsg);

//##ModelId=3F6167B501F0
/*! \brief 参数为\ref FG_OSAdaptor *，返回值为void的消息处理函数。\n
 *  
 *  用于以下消息：
 *      - \ref FG_MSG_KEY
 *      - \ref FG_MSG_KEY, \ref FKS_DOWN
 *      - \ref FG_MSG_KEY, \ref FKS_UP
 *      - \ref FG_MSG_MOUSE
 *      - \ref FG_MSG_MOUSE, \ref FMS_LBUTTONDOWN
 *      - \ref FG_MSG_MOUSE, \ref FMS_LBUTTONUP
 */
typedef bool (FG_Object::* FG_PMSG_bm)(FG_Message * pMsg);

/*! @} */

//##ModelId=3F58381F0375
/*! \brief 消息映射表项结构
 *
 *  定义消息映射表中的每一个表项
 */
struct FG_MSGMAP_ENTRY
{
    //##ModelId=3F6167B60012
    WORD        m_MsgType;              /*!< \brief 消息类型\ref FG_MSG_TYPE */

    //##ModelId=3F5B584A00E0
    /*! \brief \ref WORD类型的数据
     *
     *  保存键盘状态\ref FG_KEY_STATUS、鼠标状态\ref FG_MOUSE_STATUS、定时器ID、通知消息ID
     */
    WORD        m_wData;
    
    //##ModelId=3F6167B60026
    WORD        m_wID;                  /*!< \brief 发送通知消息的控件ID */
    
    //##ModelId=3F5838210044
    FG_PMSG_vv  m_Callback;             /*!< \brief 该消息对应的消息处理函数 */
};

//##ModelId=3F58381F0326
/*! \brief 消息映射表结构
 *
 *  包含消息映射表项的数组以及指向基类的消息映射表的指针
 */
struct FG_MSGMAP
{
    //##ModelId=3F583820024A
    const FG_MSGMAP * m_pBaseMsgMap;    /*!< \brief 指向基类的消息映射表的指针 */
    //##ModelId=3F583820027C
    const FG_MSGMAP_ENTRY * m_pEntry;   /*!< \brief 本类的消息映射表的指针 */

    //##ModelId=3F584C9400FF
    /*! \brief 在本类的消息映射表中查找消息
     *
     *  为0的参数表示该项不须查找
     *  \param type 要查找的消息类型\ref FG_MSG_TYPE
     *  \param data 要查找的消息的消息的\ref WORD型数据
     *  \param id 发送通知消息的控件ID
     *  \return FG_MSGMAP_ENTRY* 查找到的消息映射表项，\ref NULL表示没有找到
     */
    const FG_MSGMAP_ENTRY * FindMsgCallback(const WORD type, const WORD data, const WORD id) const;
};

#endif /* FG_KEYMAP_H_HEADER_INCLUDED_C0AD453B */

/*! @} */

