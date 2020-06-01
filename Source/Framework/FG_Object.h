/*--------------------------------------------------------------------------

	FG_Object.h - 窗口元素类的头文件

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
 *  \brief 窗口元素类的头文件
 *
*/

#ifndef FG_OBJECT_H_HEADER_INCLUDED_C0AD453B
#define FG_OBJECT_H_HEADER_INCLUDED_C0AD453B

#include "../Utility/FG_Utility.h"
#include "FG_MsgMap.h"
#include "FG_TimerManager.h"

//##ModelId=3F52B635008C
/*! \brief 窗口元素类
 *
 *  窗口元素类是所有可以在屏幕上显示的窗口、空间等类的基类
 */
class FG_Object
{
public:
    //##ModelId=3F58382100BB
    /*! \brief 构造函数，可以作为缺省构造函数使用
     *
     *  前景色和背景色缺省为黑色（\ref COLOR_BLACK）和灰色（\ref COLOR_GRAY）
     *  父窗口指针缺省为\ref NULL
     *  \param wID 该窗口元素的唯一标识，缺省值0（0为无效标识）
     *  \param wStyle 该窗口元素的边框风格，缺省值为\ref FS_NONE
     */
    FG_Object(const WORD wID = 0, const WORD wStyle = FS_NONE)
        : m_ForeColor(COLOR_BLACK), m_Background(COLOR_GRAY), m_wStyle(wStyle), m_wID(wID), m_pParent(NULL)
        {}

    //##ModelId=3F52BE4E0368
    /*! \brief 构造函数
     *
     *  前景色和背景色缺省为黑色（\ref COLOR_BLACK）和灰色（\ref COLOR_GRAY）
     *  父窗口指针缺省为\ref NULL
     *
     *  \param Rect 该窗口元素的边框矩形
     *  \param wID 该窗口元素的唯一标识，缺省值0（0为无效标识）
     *  \param wStyle 该窗口元素的边框风格，缺省值
     */
    FG_Object(const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE)
        : m_ForeColor(COLOR_BLACK), m_Background(COLOR_GRAY),
          m_Rect(Rect), m_wStyle(wStyle), m_wID(wID), m_pParent(NULL)
        {}

    //##ModelId=3F52BE4F01BB
    /*! \brief 析构函数
     *
     *  必须为虚函数，删除该窗口元素申请的所有定时器
     */
    virtual ~FG_Object() { FG_GetTimerManager()->KillObjectTimer(this); }
    
    //##ModelId=3F52BE4F0251
    /*! \brief 得到该窗口元素的客户区矩形
     *
     *  根据边框风格除去不同的边框大小，客户区矩形可能小于边框矩形，
     *  某一个具体的窗口元素可以覆盖此函数,以确定自己的客户区矩形
     *  \param rect 返回该窗口元素的客户区矩形
     */
    virtual void GetClientRect(FG_Rect & rect) const;

    //##ModelId=3F52BE4F02E7
    /*! \brief 判断某一个像素点是否在本窗口元素中
     *
     *  \param Test 被测试的像素点
     *  \return true 表示像素点在本窗口元素中
     *          false 表示像素点不在本窗口元素中
     */
    bool IsContains(const FG_Point Test) const { return m_Rect.Contains(Test); }
    
    //##ModelId=3F52BE4F0391
    /*! \brief 设置窗口元素的前景色
     *
     *  \param color 前景色
     */
    void ForeColor(const COLORVAL color) { m_ForeColor = color; }

    //##ModelId=3F52BE50003F
    /*! \brief 得到窗口元素的前景色
     *
     *  \return 本窗口元素的前景色
     */
    COLORVAL ForeColor(void) const { return m_ForeColor; }
    
    //##ModelId=3F52BE5000AE
    /*! \brief 设置窗口元素的背景色
     *
     *  \param color 背景色
     */
    void BGColor(const COLORVAL color) { m_Background = color; }

    //##ModelId=3F52BE500144
    /*! \brief 得到窗口元素的背景色
     *
     *  \return 本窗口元素的背景色
     */
    COLORVAL BGColor(void) const { return m_Background; }

    //##ModelId=3F52BE500252
    /*! \brief 设置窗口元素的唯一标识值
     *
     *  \param wID 唯一标识值
     */
    void ID(const WORD wID) { m_wID = wID;}

    //##ModelId=3F52BE5001C6
    /*! \brief 得到窗口元素的唯一标识值
     *
     *  \return 本窗口元素的唯一标识值
     */
    WORD ID(void) const { return m_wID;}

    //##ModelId=3F52BE500375
    /*! \brief 设置指向父窗口元素的指针
     *
     *  \param object 指向父窗口元素的指针
     */
    void Parent(FG_Object * const object) { m_pParent = object; }

    //##ModelId=3F52BE5002E8
    /*! \brief 返回指向父窗口元素的指针
     *
     *  \return 指向父窗口元素的指针
     */
    FG_Object * Parent(void) const { return m_pParent; }

    //##ModelId=3F52BE51018B
    /*! \brief 设置窗口元素的边框风格
     *
     *  \param wStyle 边框风格
     */
    void FrameStyle(WORD wStyle)
    {
        wStyle &= FS_MASK;
        m_wStyle &= ~FS_MASK;
        m_wStyle |= wStyle;
    }

    //##ModelId=3F52BE510236
    /*! \brief 得到窗口元素的边框风格
     *
     *  \return 本窗口元素的边框风格
     */
    WORD FrameStyle(void) const { return (m_wStyle & FS_MASK); }

    //##ModelId=3F52BE51036C
    /*! \brief 设置窗口元素的风格
     *
     *  \param wStyle \ref Style
     */
    void Style(const WORD wStyle) { m_wStyle = wStyle; }

    //##ModelId=3F52BE5102CC
    /*! \brief 得到窗口元素的风格
     *
     *  \return 本窗口元素的\ref Style
     */
    WORD Style(void) const { return m_wStyle; }

    //##ModelId=3F6EAC8F00F6
    /*! \brief 设置窗口元素的风格中的焦点位，即把该窗口元素设置为焦点窗口或焦点控件
     *
     *  焦点位\ref GS_FOCUS为1，表示该窗口元素为焦点窗口或焦点控件，即可以得到当前的键盘输入
     *  否则该窗口元素不是输入焦点
     */
    void SetFocus(void) { m_wStyle |= GS_FOCUS; }

    //##ModelId=3F6EAC8F0100
    /*! \brief 清除窗口元素的风格中的焦点位，即把该窗口元素设置为非焦点窗口或非焦点控件
     *
     *  焦点位为1，表示该窗口元素为焦点窗口或焦点控件，即可以得到当前的键盘输入
     *  否则该窗口元素不是输入焦点
     */
    void ResetFocus(void) { m_wStyle &= ~GS_FOCUS; }

    //##ModelId=3F6EAC8F0114
    /*! \brief 该窗口元素是否为当前焦点窗口元素
     *
     *  - 对于窗口，焦点窗口指最上面的窗口
     *  - 对于控件，焦点控件指当前接受输入的控件
     */
    bool IsFocus(void) const { return (m_wStyle & GS_FOCUS) != 0; }

    //##ModelId=3F58382102A6
    /*! \brief 消息分发函数
     *
     *  首先得到消息映射表的指针，从本类直到基类的消息映射表中寻找该消息，
     *  然后，根据消息类型分发消息
     *  \param pMsg 要分发的消息指针
     *  \return 该消息是否已被处理
     *          true    该消息已被处理
     *          false   该消息未被处理
     */
    bool Message(FG_Message * pMsg);

protected:
    //##ModelId=3F5DAA1402B2
    /*! \brief 为当前窗口元素启动一个定时器
     *
     *  \param timerID 定时器的唯一标识（对于当前窗口元素唯一）
     *  \param dwInterval 定时器的到期时间
     *  \return 定时器是否成功启动
     *          true    成功
     *          false   失败
     */
    bool StartTimer(const BYTE timerID, const WORD dwInterval)
    {
        return FG_GetTimerManager()->StartTimer(this, timerID, dwInterval);
    }
    
    //##ModelId=3F5DAA140320
    /*! \brief 删除当前窗口元素的定时器
     *
     *  \param timerID 定时器的唯一标识（对于当前窗口元素唯一）
     *  \return 定时器是否成功删除
     *          true    成功
     *          false   失败
     */
    bool KillTimer(const BYTE timerID)
    {
        return FG_GetTimerManager()->KillTimer(this, timerID);
    }

    //##ModelId=3F52BE520038
    /*! \brief 绘制窗口元素的边框
     *
     *  \param pAdaptor 指向操作系统适配器的指针
     */
    void DrawBorder(FG_OSAdaptor * pAdaptor);

    //##ModelId=3F603B980280
    /*! \brief 发送通知消息给该窗口元素的父窗口
     *
     *  \param wNotification 通知消息的类型
     */
    void NotifyParent(const WORD wNotification);

    //##ModelId=3F603B9802BC
    /*! \brief 发送要求重画消息给该窗口元素的父窗口
     *
     */
    void RequestDraw();

protected:
    //##ModelId=3F52BE4E01E1
    COLORVAL    m_ForeColor;        /*!< \brief 前景色 */
    //##ModelId=3F52BE4E02BF
    COLORVAL    m_Background;       /*!< \brief 背景色 */
    //##ModelId=3F52BE4E02DD
    FG_Rect     m_Rect;             /*!< \brief 本窗口元素占据的矩形区域 */

    //##ModelId=3F52BE4E02F1
    WORD        m_wStyle;           /*!< \brief 本窗口元素的边框风格 */

    //##ModelId=3F52BE4E0305
    WORD        m_wID;              /*!< \brief 本窗口元素的唯一标识 */

    //##ModelId=3F52BE4E034D
    FG_Object * m_pParent;          /*!< \brief 指向本窗口元素的父窗口的指针 */

//    DECLARE_MESSAGE_MAP()
private:
    //##ModelId=3F5C4D41037C
    static const FG_MSGMAP_ENTRY    m_MsgEntries[];     /*!< \brief 消息映射表项数组 */

protected:
    //##ModelId=3F5C4D4103CC
    static const FG_MSGMAP          m_MsgMap;           /*!< \brief 本类的消息映射表 */

    //##ModelId=3F5C4D42001F
    /*! \brief 得到本类的消息映射表指针
     *
     *  虚函数，派生类覆盖该函数，来返回自己的消息映射表指针，通过宏\ref BEGIN_MESSAGE_MAP生成
     *  \return 本类的消息映射表指针
     */
    virtual const FG_MSGMAP * GetMessageMap() const;

protected:
    //##ModelId=3F52BE4F01E3
    /*! \brief 重画消息\ref FG_MSG_DRAW的处理函数
     *
     *  按照窗口元素的边框风格绘制边框
     *  \param pAdaptor 指向操作系统适配器的指针
     */
    void OnDraw(FG_OSAdaptor * pAdaptor)
    {
        DrawBorder(pAdaptor);
    }

    //##ModelId=3F6EAC8F0128
    /*! \brief 焦点切换消息\ref FG_MSG_FOCUS的处理函数
     *
     *  \param pMsg 指向焦点切换消息结构的指针
     */
    void OnFocus(FG_Message * pMsg);
};

//##ModelId=3FD884F403D9
/*! \brief 按照标识查找窗口元素的检查类
 *
 *  用于算法函数按照标识查找窗口元素
 */
class FG_CheckObjectID : public FG_ListCheck<FG_Object>
{
public:
    //##ModelId=3FD884F600C5
    /*! \brief 构造函数
     *
     *  \param wID 要查找的窗口元素的唯一标识
     */
    FG_CheckObjectID(const WORD wID) : m_wID(wID) {}

    //##ModelId=3FD884F600CF
    /*! \brief 检查对象是否满足条件
     *
     *  通过比较窗口元素的ID来决定该窗口元素是否满足条件
     *  \param pObj 要检查的窗口元素指针
     *  \return 是否满足条件\n
     *          true    满足条件\n
     *          false   不满足条件
     */
    virtual bool FindIt(const FG_Object * pObj)
    {
        return pObj->ID() == m_wID;
    }

private:
    //##ModelId=3FD884F600A8
    WORD m_wID;                 /*!< \brief 保存要查找的窗口元素的唯一标识 */
};

#endif /* FG_OBJECT_H_HEADER_INCLUDED_C0AD453B */

/*! @} */

