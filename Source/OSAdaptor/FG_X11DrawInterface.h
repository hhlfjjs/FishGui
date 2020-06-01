/*--------------------------------------------------------------------------

	FG_X11DrawInterface.h - X11�Ļ�ͼ�ӿ����ͷ�ļ�

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
 *  \brief X11�Ļ�ͼ�ӿ����ͷ�ļ�
 */

#ifndef FG_X11DRAWINTERFACE_H_HEADER_INCLUDED_C0B152A0
#define FG_X11DRAWINTERFACE_H_HEADER_INCLUDED_C0B152A0

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "../Utility/FG_Utility.h"
#include "FG_OSDrawInterface.h"

//##ModelId=3F6EAFFE00BE
/*! \brief X11�Ļ�ͼ�ӿ���
 *  
 *  �����װX11�Ļ�ͼ����
 */
class FG_X11DrawInterface : public FG_OSDrawInterface
{
public:
    //##ModelId=3F6EB0010086
    /*! \brief X11�Ļ�ͼ�ӿ���Ĺ��캯�� */
    FG_X11DrawInterface(Window win, Display * display, int screen);

    //##ModelId=40925CB00334
    /*! \brief X11�Ļ�ͼ�ӿ������������ */
    ~FG_X11DrawInterface();

    //##ModelId=3F6EB0010090
    void BeginDraw(const FG_Rect & rect);

    //##ModelId=3F6EB0010092
    void EndDraw();
    
    //##ModelId=3F6EB001009A
    void FillRect(const FG_Rect & rect, const COLORVAL ForeColor, const COLORVAL background);

    //##ModelId=3F6EB00100A4
    void Line(const short x1, const short y1, const short x2, const short y2, const COLORVAL color);
    
    //##ModelId=3F6EB00100B1
    void DrawText(const char * Text, const short x, const short y, const COLORVAL color);
    
    //##ModelId=3F6EB00100C3
    WORD GetTextWidth(const char * Text);
    
    //##ModelId=3F6EB00100CC
    WORD GetTextHeight(const char * Text);
    
    //##ModelId=3F6EB00100CE
    void DrawBitmap(const char * pBmpName, const short x1, const short y1);
    
    //##ModelId=3F6EB00100D8
    void DrawPolyLine(const short n, const FG_Point * vert, const COLORVAL color);
    
    //##ModelId=3F6EB00100E3
    void DrawDotRect(const FG_Rect & rect, const COLORVAL color);

protected:
    //##ModelId=3F6EB0010040
    Window      m_Win;                  /*!< \brief X11���ڽṹ */

    //##ModelId=3F6EB0010041
    Display *   m_Display;              /*!< \brief X11��ʾ�豸 */
    
    //##ModelId=3F6EB001004A
    //Visual *    m_Visual;
    
    //##ModelId=3F6EB0010054
    int         m_Depth;                /*!< \brief ��ɫ��� */
    
    //##ModelId=3F6EB001005E
    GC          m_GC;                   /*!< \brief ��ͼ�豸 */
    
    //##ModelId=3F6EB0010068
    GC          m_CopyGC;               /*!< \brief ��������ͼ�豸 */
    
    //##ModelId=3F6EB0010072
    Pixmap      m_Buffer;               /*!< \brief ��������λͼ */
    
    //##ModelId=3F6EB001007C
    Colormap    m_CMap;                 /*!< \brief ��ɫ�� */
    
    //##ModelId=40925CB002DA
    XFontSet    m_FontSet;              /*!< \brief ������ */
};

#endif /* FG_X11DRAWINTERFACE_H_HEADER_INCLUDED_C0B152A0 */

/*! @} */

