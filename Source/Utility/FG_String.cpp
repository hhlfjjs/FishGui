/*--------------------------------------------------------------------------

	FG_String.cpp - �ַ������ʵ���ļ�

	��������FishGUI�����һ����

	��Ȩ���� (C) 2003,2004 ��ӽ��
	http://www.contextfree.net/wangyw/

----------------------------------------------------------------------------

	���߶� FishGUI �����������Դ������Ȩ���£�

	�����κθ��ˡ���֯����������ҵ�޳���á��޸ġ�ʹ�á����·��� FishGUI ��
	������Դ���룬�����г������޳��ķ�ʽ���л��� FishGUI Դ�����ȫ����
	�����ݿ����������Ʒ����������ʹ����Ȩ��ʱ������������Լ����

	1�����·��� FishGUI �������Դ����ʱ��������ȥ�������Դ������ԭ�еİ�
	   Ȩ��Ϣ�Ϳ����߱�ʶ��

	2�����л��� FishGUI Դ�����ȫ���򲿷����ݿ����������Ʒʱ�������ڲ�Ʒ
	   ������λ�ñ�������������

	   ������Ʒ��һ���ֹ����ǻ�����ӽ���� FishGUI ����еĹ�����ɵġ�

	3������ʽ������������ FishGUI ���ĵ���Դ�����ע�����ݵģ�Ӧע�������
	   ԭ����Ϊ��ӽ�䡣

--------------------------------------------------------------------------*/
/*! \addtogroup Utility
 *  @{ 
 */

/*! \file 
 *  \brief �ַ������ʵ���ļ�
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

