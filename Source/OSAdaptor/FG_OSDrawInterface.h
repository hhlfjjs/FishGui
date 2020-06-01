/*--------------------------------------------------------------------------

	FG_OSDrawInterface.h - ����ϵͳ��ͼ�ӿ����ͷ�ļ�

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
 *  \brief ����ϵͳ��ͼ�ӿ����ͷ�ļ�
 */

#ifndef FG_OSDRAWINTERFACE_H_HEADER_INCLUDED_C0B113C4
#define FG_OSDRAWINTERFACE_H_HEADER_INCLUDED_C0B113C4

#include "../Utility/FG_Utility.h"

//##ModelId=3F49CF2F0067
/*! \brief ����ϵͳ��ͼ�ӿ���
 *
 *  ������������װ����Ĳ���ϵͳ�Ļ�ͼ�ӿڣ�����ܲ��ṩһ��ͳһ�Ľӿ�
 */
class FG_OSDrawInterface
{
public:
    //##ModelId=3F6EAC810381
    /*! \brief ȱʡ���캯��
     */
    FG_OSDrawInterface() : m_iDrawCount(0) {}

    //##ModelId=3F6EAC81038B
    /*! \brief ��������
     */
    virtual ~FG_OSDrawInterface() {}

    //##ModelId=3F4EBF2C01D4
    /*! \brief ��ʼ�ػ�
     *  
     *  �ú���ִ��֮�����еĻ�ͼ��������һ���������Ͻ��У�ֱ����Ӧ��\ref FG_OSDrawInterface::EndDraw���òŰѻ���������ˢ�µ���Ļ��
     *  \param rect ��Ҫ�ػ�����Ч����
     */
    virtual void BeginDraw(const FG_Rect & rect) = 0;

    //##ModelId=3F4EBF2C0293
    /*! \brief �����ػ�
     *  
     *  �ú����ѻ���������ˢ�µ���Ļ��
     */
    virtual void EndDraw() = 0;

    //##ModelId=3F4EBF2C02ED
    /*! \brief ������
     *  
     *  \param rect Ҫ���ľ���
     *  \param ForeColor ǰ��ɫ
     *  \param background ����ɫ
     */
    virtual void FillRect(const FG_Rect & rect, const COLORVAL ForeColor, const COLORVAL background) = 0;

    //##ModelId=3F4EBF2D0081
    /*! \brief ����
     *  
     *  \param x1 ��һ��ĺ�����
     *  \param y1 ��һ��ĺ�����
     *  \param x2 �ڶ���ĺ�����
     *  \param y2 �ڶ���ĺ�����
     *  \param color �ߵ���ɫ
     */
    virtual void Line(const short x1, const short y1, const short x2, const short y2, const COLORVAL color) = 0;

    //##ModelId=3F4EBF2D02B2
    /*! \brief �����ı�
     *
     *  \param Text Ҫ���Ƶ��ַ�������\ref NULL����
     *  \param x �ı����Ͻǵĺ�����
     *  \param y �ı����Ͻǵ�������
     *  \param color �ı�����ɫ
     */
    virtual void DrawText(const char * Text, const short x, const short y, const COLORVAL color) = 0;

    //##ModelId=3F4EBF2E00BF
    /*! \brief �õ��ı��Ŀ��
     *
     *  \param Text Ҫ�����ȵ��ַ�������\ref NULL����
     *  \return �ı��Ŀ�ȵ�������
     */
    virtual WORD GetTextWidth(const char * Text) = 0;

    //##ModelId=3F4EBF2E0191
    /*! \brief �õ��ı��ĸ߶�
     *
     *  \param Text Ҫ����߶ȵ��ַ�������\ref NULL����
     *  \return �ı��ĸ߶ȵ�������
     */
    virtual WORD GetTextHeight(const char * Text) = 0;

    //##ModelId=3F4EBF2E026D
    /*! \brief ����λͼ
     *
     *  \param pBmpName Ҫ���Ƶ�λͼ��
     *  \param x1 λͼ���Ͻǵĺ�����
     *  \param y1 λͼ���Ͻǵ�������
     */
    virtual void DrawBitmap(const char * pBmpName, const short x1, const short y1) = 0;

    //##ModelId=3F6193B20152
    /*! \brief ��������
     *
     *  \param n �����߰����ĵ���
     *  \param vert ���е������
     *  \param color ���ߵ���ɫ
     */
    virtual void DrawPolyLine(const short n, const FG_Point * vert, const COLORVAL color) = 0;

    //##ModelId=3F6EAC810395
    /*! \brief ���Ƶ㻮�߾���
     *
     *  \param rect Ҫ���Ƶľ���
     *  \param color ���ε���ɫ
     */
    virtual void DrawDotRect(const FG_Rect & rect, const COLORVAL color) = 0;

protected:
    //##ModelId=3F6EAC810350
    /*! \brief ��ǰ����Ҫ�ػ�����Ч����
     *
     *  ����\ref FG_OSDrawInterface::BeginDraw�Ĳ���rect����Ͻ�����Ч�����С�\n
     *  ����\ref FG_OSDrawInterface::EndDrawʱ������Ч������ա�
     */
    FG_Rect     m_Invalid;

    //##ModelId=3F6EAC810363
    /*! \brief \ref FG_OSDrawInterface::BeginDraw�����õĴ���
     *
     *  \ref FG_OSDrawInterface::BeginDraw������ʱ����ֵ��1��\n
     *  \ref FG_OSDrawInterface::EndDraw������ʱ����ֵ��1��
     */
    int         m_iDrawCount;
};

#endif /* FG_OSDRAWINTERFACE_H_HEADER_INCLUDED_C0B113C4 */

/*! @} */

