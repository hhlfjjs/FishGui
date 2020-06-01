/*--------------------------------------------------------------------------

	FG_KeyMap.cpp - 键盘映射表类的实现文件

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
 *  \brief 键盘映射表类的实现文件
 */

/*! @} */

#include "FG_KeyMap.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
//##ModelId=40925CC102B6
FG_KeyMap::~FG_KeyMap()
{
    FG_KEYMAPLIST::iterator i;
    for (i = m_KeyMapList.First(); ! i.IsDone(); ++ i)
        delete i;
    m_KeyMapList.RemoveAll();
}

//##ModelId=3F5EDD9E0335
bool FG_KeyMap::SendKey(FG_Message * pMsg)
{
    FG_KEYMAPLIST::iterator i = m_KeyMapList.First();
    FG_CheckOriginKey check((WORD)pMsg->lData);
    
    if (FG_ListFind_If(i, check))
    {	
        // 有控件注册了该快捷键
        FG_Message Msg = *pMsg;
        Msg.lData = i->m_wActualKey;			// 提供键值的转换功能
        return i->m_pTarget->Message(& Msg);	// 发送键盘消息
    }
    return false;
}

