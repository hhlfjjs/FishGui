/*--------------------------------------------------------------------------

	FG_Win32DrawInterface.h - Win32�Ļ�ͼ�ӿ����ͷ�ļ�

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
 *  \brief Win32�Ļ�ͼ�ӿ����ͷ�ļ�
 */

#ifndef FG_WIN32DRAWINTERFACE_H_HEADER_INCLUDED_C0B152A0
#define FG_WIN32DRAWINTERFACE_H_HEADER_INCLUDED_C0B152A0

#include "FG_OSDrawInterface.h"

//##ModelId=3F49D01202C6
/*! \brief Win32�Ļ�ͼ�ӿ���
 *  
 *  �����װWin32�Ļ�ͼ����
 */
class FG_Win32DrawInterface : public FG_OSDrawInterface
{
public:
    //##ModelId=3F4EDED00308
    /*! \brief Win32�Ļ�ͼ�ӿ���Ĺ��캯�� */
    FG_Win32DrawInterface() : m_hMemDC(0) {}

    //##ModelId=3F71AB2E0279
    /*! \brief Win32�Ļ�ͼ�ӿ������������ */
    ~FG_Win32DrawInterface();

    //##ModelId=3F6EAFFF0390
    /*! \brief ����Win32�Ļ�ͼ�豸���
     *
     *  \param hdc Ҫ���õĻ�ͼ�豸���
     */
    void SetHDC(const HDC hdc) { m_hDC = hdc; }

    //##ModelId=3F4EDED00326
    void BeginDraw(const FG_Rect & rect);

    //##ModelId=3F4EDED003A8
    void EndDraw();
    
    //##ModelId=3F4EDED003E4
    void FillRect(const FG_Rect & rect, const COLORVAL ForeColor, const COLORVAL background);

    //##ModelId=3F4EDED10133
    void Line(const short x1, const short y1, const short x2, const short y2, const COLORVAL color);

    //##ModelId=3F4EDED1031E
    void DrawText(const char * Text, const short x, const short y, const COLORVAL color);

    //##ModelId=3F4EDED200DA
    WORD GetTextWidth(const char * Text);

    //##ModelId=3F4EDED20184
    WORD GetTextHeight(const char * Text);

    //##ModelId=3F4EDED20239
    void DrawBitmap(const char * pBmpName, const short x1, const short y1);

    //##ModelId=3F6193B201F2
    void DrawPolyLine(const short n, const FG_Point * vert, const COLORVAL color);

    //##ModelId=3F6EAC820075
    void DrawDotRect(const FG_Rect & rect, const COLORVAL color);

protected:
    //##ModelId=3F6EAFFF012D
    HDC         m_hDC;          /*!< \brief Win32��ͼ�豸��� */

    //##ModelId=3F6EAFFF017D
    HDC         m_hMemDC;       /*!< \brief ���ݵ��ڴ��ͼ�豸�����������ͼ������ */

    //##ModelId=3F6EAFFF01CD
    HBITMAP     m_hBitmap;      /*!< \brief �ڴ滺�������õ�λͼ��� */

    //##ModelId=3F6EAFFF021E
    HFONT       m_hFont;        /*!< \brief ������ */
};

#endif /* FG_WIN32DRAWINTERFACE_H_HEADER_INCLUDED_C0B152A0 */

/*! @} */

