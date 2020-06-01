/*--------------------------------------------------------------------------

	FG_OSAdaptor.cpp - ����ϵͳ�������������ʵ���ļ�

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
/*! \addtogroup OSAdaptor
 *  @{ 
 */

/*! \file
 *  \brief ����ϵͳ�������������ʵ���ļ�
*/

/*! @} */

#include "../Utility/FG_Common.h"
#include "FG_OSAdaptor.h"

#if defined(WIN32)
    #define FG_OS_WIN32
    #include "FG_Win32Adaptor.h"
#elif defined(HAVE_LIBX11) 
    #define FG_OS_X11
    #include "FG_X11Adaptor.h"
#endif /* WIN32 */

#if defined(WIN32) && defined(_DEBUG)
    /* Trace memory allocation in windows debug version */
    #include <crtdbg.h>
    static char THIS_FILE[] = __FILE__;
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  /* _DEBUG */

// Remove the MACRO of windows
#undef DrawText    

FG_OSAdaptor * FG_GetAdaptor()
{ 
    return FG_OSAdaptor::GetAdaptor();
}

FG_OSAdaptor * FG_OSAdaptor::m_pAdaptor = NULL;
FG_OSDrawInterface * FG_OSAdaptor::m_pDraw = NULL;

FG_OSAdaptor::FG_OSAdaptor()
{
    for (int i = 0; i < FG_MAX_SYS_MSG; i ++)
        m_ppObserver[i] = NULL;
}

//##ModelId=3F4E1615027D
FG_OSAdaptor * FG_OSAdaptor::GetAdaptor()
{
    if (! m_pAdaptor)
    {
        #if defined(FG_OS_WIN32)
            m_pAdaptor = new FG_Win32Adaptor();
        #elif defined(FG_OS_X11) 
            m_pAdaptor = new FG_X11Adaptor();
        #endif /* FG_OS_WIN32 */
    }
    return m_pAdaptor;
}

//##ModelId=40925CAF0329
void FG_OSAdaptor::Run(void)
{
    InitInstance();
    Execute();
    ExitInstance();
}

//##ModelId=3F4A19760260
FG_OSMsgObserver * FG_OSAdaptor::SetMsgObserver(const WORD type, FG_OSMsgObserver * const pObserver)
{
    FG_OSMsgObserver * tmp = m_ppObserver[type];
    m_ppObserver[type] = pObserver;
    return tmp;
}

//##ModelId=3F521F6D00A8
void FG_OSAdaptor::SendMsg(FG_Message * pMsg)
{
    if (pMsg->wType < FG_MAX_SYS_MSG && m_ppObserver[pMsg->wType])
        m_ppObserver[pMsg->wType]->OSMessage(pMsg);
}

//##ModelId=3FD88515012E
void FG_OSAdaptor::BeginDraw(const FG_Rect & rect)
{
    if (m_pDraw)
        m_pDraw->BeginDraw(rect);
}

//##ModelId=3FD885150188
void FG_OSAdaptor::EndDraw()
{
    if (m_pDraw)
        m_pDraw->EndDraw();
}

//##ModelId=3FD8851501A6
void FG_OSAdaptor::FillRect(const FG_Rect & rect, const COLORVAL ForeColor, COLORVAL const background)
{
    if (m_pDraw)
        m_pDraw->FillRect(rect, ForeColor, background);
}

//##ModelId=3FD885150278
void FG_OSAdaptor::Line(const short x1, const short y1, const short x2, const short y2, const COLORVAL color)
{
    if (m_pDraw)
        m_pDraw->Line(x1, y1, x2, y2, color);
}

//##ModelId=3FD8851503CD
void FG_OSAdaptor::DrawText(const char * Text, const short x, const short y, const COLORVAL color)
{
    if (m_pDraw)
        m_pDraw->DrawText(Text, x, y, color);
}

//##ModelId=3FD885160111
WORD FG_OSAdaptor::GetTextWidth(const char * Text)
{
    if (m_pDraw)
        return m_pDraw->GetTextWidth(Text);
    else
        return 0;
}

//##ModelId=3FD88516017F
WORD FG_OSAdaptor::GetTextHeight(const char * Text)
{
    if (m_pDraw)
        return m_pDraw->GetTextHeight(Text);
    else
        return 0;
}

//##ModelId=3FD8851601ED
void FG_OSAdaptor::DrawBitmap(const char * pBmpName, const short x1, const short y1)
{
    if (m_pDraw)
        m_pDraw->DrawBitmap(pBmpName, x1, y1);
}

//##ModelId=3FD8851602F2
void FG_OSAdaptor::DrawPolyLine(const short n, const FG_Point * vert, const COLORVAL color)
{
    if (m_pDraw)
        m_pDraw->DrawPolyLine(n, vert, color);
}

//##ModelId=3FD885170018
void FG_OSAdaptor::DrawDotRect(const FG_Rect & rect, const COLORVAL color)
{
    if (m_pDraw)
        m_pDraw->DrawDotRect(rect, color);
}

