/*--------------------------------------------------------------------------

	FG_String.cpp - 字符串类的实现文件

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
 *  \brief 字符串类的实现文件
 */

/*! @} */

#include "FG_String.h"
#include "string.h"

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */
    
//##ModelId=40926077001E
FG_String::FG_String(const char * Text)
{
    m_wBufferLen = 0;
    if (Text)
    {
        if (* Text)
        {
            m_wStrLen = strlen(Text);
            m_wBufferLen = m_wStrLen + 16;        
            m_pText = new char[m_wBufferLen + 1];
            strcpy(m_pText, Text);
        }
        else
        {
            m_wStrLen = 0;
            m_pText = NULL;
        }
    }
    else
    {
        m_pText = NULL;
        m_wStrLen = 0;
    }
}

//##ModelId=409260770031
FG_String::~FG_String()
{
    if (m_pText)
    {
        delete [] m_pText;
    }    
}

//##ModelId=409260770033
void FG_String::DataSet(const char * Text)
{
    if (Text)
    {
        if (* Text)
        {
            m_wStrLen = strlen(Text);
            if (m_wStrLen > m_wBufferLen)
            {
                if (m_pText)
                {
                    delete [] m_pText;
                }
                m_wBufferLen = m_wStrLen + 32;
    
                m_pText = new char[m_wBufferLen + 1];
                strcpy(m_pText, Text);
            }
            else
            {
                strcpy(m_pText, Text);
            }
        }
    }
    else
    {
        if (m_pText)
        {
            delete [] m_pText;
        }
        m_pText = NULL;
        m_wStrLen = 0;
        m_wBufferLen = 0;
    }
}

