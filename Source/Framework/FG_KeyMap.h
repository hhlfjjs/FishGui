/*--------------------------------------------------------------------------

	FG_KeyMap.h - 键盘映射表类的头文件

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
 *  \brief 键盘映射表类的头文件
 */

#ifndef FG_KEYMAP_H_HEADER_INCLUDED_C0AD453B
#define FG_KEYMAP_H_HEADER_INCLUDED_C0AD453B

#include "../Utility/FG_Utility.h"
#include "FG_Widget.h"

//##ModelId=3FD884F5018C
/*! \brief 键盘映射表项结构
 *
 *  管理原始的\ref Virtual_Key、实际的\ref Virtual_Key以及目标控件的映射关系。\n
 *  三者之间的关系为：如果用户按键值为“原始的\ref Virtual_Key”的键盘消息，
 *  该键盘消息会发送给“目标控件”，实际发送的键值被转换成“实际的\ref Virtual_Key”
 */
struct FG_KeyMapItem
{
    //##ModelId=3FD884F602CE
    /*! \brief 键盘映射表项结构的构造函数
     *
     *  \param wOrgKey 原始的\ref Virtual_Key
     *  \param wActKey 实际的\ref Virtual_Key
     *  \param pTarget 目标控件
     */
    FG_KeyMapItem(const WORD wOrgKey, const WORD wActKey, FG_Widget * const pTarget) 
        : m_wOriginKey(wOrgKey), m_wActualKey(wActKey), m_pTarget(pTarget)
        {}

    //##ModelId=3FD884F60289
    WORD m_wOriginKey;  		/*!< \brief 原始的\ref Virtual_Key */
    //##ModelId=3FD884F6029D
    WORD m_wActualKey;  		/*!< \brief 实际的\ref Virtual_Key */
    //##ModelId=3FD884F602BB
    FG_Widget * m_pTarget;      /*!< \brief 目标控件 */
};

//##ModelId=3F5E6DF703C8
/*! \brief 键盘映射表管理器
 *
 *  保存和管理所有的\ref FG_KeyMapItem
 */
class FG_KeyMap
{
public:
    //##ModelId=40925CC102B6
    /*! \brief 键盘映射表管理器得析构函数
     */
    ~FG_KeyMap();

    //##ModelId=3F5E6DF802E2
	/*! \brief 注册快捷键
	 *
	 *  \param wOrgKey 原始的\ref Virtual_Key
	 *  \param wActKey 实际的\ref Virtual_Key
	 *  \param pTarget 目标控件
	 *  \return bool 注册操作是否成功
     *               true   成功
     *               false  失败
     */
	bool RegisterKey(WORD wOrgKey, WORD wActKey, FG_Widget * pTarget)
    {
        return m_KeyMapList.Add(new FG_KeyMapItem(wOrgKey, wActKey, pTarget));
    }

    //##ModelId=3F5EDD9E0335
    /*! \brief 处理快捷键
     *
     *  在单项链表容器中查找此快捷键，找到后进行转换，然后发送给目标控件，否则返回false
     *  \param pMsg 指向键盘消息的指针
     *  \return bool 该键盘消息是否被处理
     *               true   该键盘消息被处理
     *               false  该键盘消息未被处理
     */
    bool SendKey(FG_Message * pMsg);

private:
    //##ModelId=3F5E6DF80011
    typedef FG_SList<FG_KeyMapItem> FG_KEYMAPLIST;      /*!< \brief 保存键盘映射表项的单向链表容器类（\ref FG_SList） */

    //##ModelId=3F5E6DF802BB
    FG_KEYMAPLIST m_KeyMapList;                         /*!< \brief 保存键盘映射表项的单向链表容器对象 */
};

//##ModelId=3FD884F5000F
/*! \brief 按照\ref Virtual_Key查找键盘映射表项的检查类
 *
 *  用于算法函数按照\ref Virtual_Key查找键盘映射表项
 */
class FG_CheckOriginKey : public FG_ListCheck<FG_KeyMapItem>
{
public:
    //##ModelId=3FD884F6010B
    /*! \brief 构造函数
     *
     *  \param wKey 要查找的\ref Virtual_Key
     */
    FG_CheckOriginKey(const WORD wKey) : m_wKey(wKey) {}

    //##ModelId=3FD884F60115
    /*! \brief 检查键盘映射表项是否满足条件
     *
     *  通过比较键盘映射表项虚拟键码决定是否满足条件
     *  \param pObj 要检查的键盘映射表项对象指针
     *  \return 是否满足条件\n
     *          true    满足条件\n
     *          false   不满足条件
     */
    virtual bool FindIt(const FG_KeyMapItem * pObj)
    {
        return pObj->m_wOriginKey == m_wKey;
    }

private:
    //##ModelId=3FD884F600EE
    WORD m_wKey;        /*!< \brief 要查找的\ref Virtual_Key */
};

#endif /* FG_KEYMAP_H_HEADER_INCLUDED_C0AD453B */

/*! @} */

