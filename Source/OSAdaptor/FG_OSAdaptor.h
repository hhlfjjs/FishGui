/*--------------------------------------------------------------------------

	FG_OSAdaptor.h - ����ϵͳ�������������ͷ�ļ�

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
 *  \brief ����ϵͳ�������������ͷ�ļ�
*/

#ifndef FG_OSADAPTOR_H_HEADER_INCLUDED_C0B1A949
#define FG_OSADAPTOR_H_HEADER_INCLUDED_C0B1A949

#include "../Utility/FG_Utility.h"
#include "FG_OSDrawInterface.h"

//##ModelId=3F49CBEF015B
/*! \brief ����ϵͳ������������
 *  
 *  ����Ϊ�����࣬����ʵ�����������������Ϊ����Ĳ���ϵͳ����������Ϊ�����ࡣ
 *  ������Ϊ��Щ�������ṩͳһ�ķ��ʵ㣬����Ϊ����ϵͳ������ṩͳһ�Ľӿ�  
*/
class FG_OSAdaptor
{
public:
    //##ModelId=3F4E1615027D
    /*! \brief ����Ĳ���ϵͳ�����������ȫ�ַ��ʵ㺯��
     *  
     *  - ���\ref FG_OSAdaptor::m_pAdaptorΪ\ref NULL
     *      - �����Win32ϵͳ
     *          - ����\ref FG_Win32Adaptor��Ψһʵ������
     *      - �����X11ϵͳ
     *          - ����\ref FG_X11Adaptor��Ψһʵ������
     *      - ��\ref FG_OSAdaptor::m_pAdaptorָ�򴴽��Ķ���
     *  - ����\ref FG_OSAdaptor::m_pAdaptor
     */
    static FG_OSAdaptor * GetAdaptor();

    //##ModelId=40925CAF0329
    /*! \brief ϵͳ����
     *  
     *  ���ε���\ref FG_OSAdaptor::InitInstance��\ref FG_OSAdaptor::Execute��\ref FG_OSAdaptor::ExitInstance
     */
    void Run(void);

    //##ModelId=3F4A19760260
    /*! \brief ע��ϵͳ��Ϣ�Ĺ۲���
     *  
     *  ÿ��ϵͳ��Ϣֻ����һ���۲��ߣ�����Ϣ�����ߣ�\ref FG_OSMsgObserver�����ࣩ
     *  \param type ϵͳ��Ϣ����
     *  \param pObserver ע���ϵͳ��Ϣ�Ĺ۲���ָ��
     *  \return ����Ϣ��ǰ���õĹ۲���ָ��
     */
    FG_OSMsgObserver * SetMsgObserver(const WORD type, FG_OSMsgObserver * const pObserver);

    //##ModelId=3F521F6D00A8
    /*! \brief ����ϵͳ��Ϣ��ע��Ĺ۲���
     *  
     *  \param pMsg ָ��Ҫ���͵�ϵͳ��Ϣ��������ͬ����Ϣ�������߱��븺�������ͷŸ���Ϣ
     */
    void SendMsg(FG_Message * pMsg);

    //##ModelId=3FD88515012E
    /*! \brief ��ʼ�ػ�
     *  
     *  �������\ref FG_OSDrawInterface::BeginDraw\n
     *  �ú���ִ��֮�����еĻ�ͼ��������һ���������Ͻ��У�ֱ����Ӧ��\ref FG_OSAdaptor::EndDraw���òŰѻ���������ˢ�µ���Ļ��
     *  \param rect ��Ҫ�ػ�����Ч����
     */
    virtual void BeginDraw(const FG_Rect & rect);

    //##ModelId=3FD885150188
    /*! \brief �����ػ�
     *  
     *  �������\ref FG_OSDrawInterface::EndDraw���ú����ѻ���������ˢ�µ���Ļ��
     */
    virtual void EndDraw();

    //##ModelId=3FD8851501A6
    /*! \brief ������
     *  
     *  �������\ref FG_OSDrawInterface::FillRect
     *  \param rect Ҫ���ľ���
     *  \param ForeColor ǰ��ɫ
     *  \param background ����ɫ
     */
    virtual void FillRect(const FG_Rect & rect, const COLORVAL ForeColor, const COLORVAL background);

    //##ModelId=3FD885150278
    /*! \brief ����
     *  
     *  �������\ref FG_OSDrawInterface::Line
     *  \param x1 ��һ��ĺ�����
     *  \param y1 ��һ��ĺ�����
     *  \param x2 �ڶ���ĺ�����
     *  \param y2 �ڶ���ĺ�����
     *  \param color �ߵ���ɫ
     */
    virtual void Line(const short x1, const short y1, const short x2, const short y2, const COLORVAL color);

    //##ModelId=3FD8851503CD
    /*! \brief �����ı�
     *
     *  �������\ref FG_OSDrawInterface::DrawText
     *  \param Text Ҫ���Ƶ��ַ�������\ref NULL����
     *  \param x �ı����Ͻǵĺ�����
     *  \param y �ı����Ͻǵ�������
     *  \param color �ı�����ɫ
     */
    virtual void DrawText(const char * Text, const short x, const short y, const COLORVAL color);

    //##ModelId=3FD885160111
    /*! \brief �õ��ı��Ŀ��
     *
     *  �������\ref FG_OSDrawInterface::GetTextWidth
     *  \param Text Ҫ�����ȵ��ַ�������\ref NULL����
     *  \return �ı��Ŀ�ȵ�������
     */
    virtual WORD GetTextWidth(const char * Text);

    //##ModelId=3FD88516017F
    /*! \brief �õ��ı��ĸ߶�
     *
     *  �������\ref FG_OSDrawInterface::GetTextHeight
     *  \param Text Ҫ����߶ȵ��ַ�������\ref NULL����
     *  \return �ı��ĸ߶ȵ�������
     */
    virtual WORD GetTextHeight(const char * Text);

    //##ModelId=3FD8851601ED
    /*! \brief ����λͼ
     *
     *  �������\ref FG_OSDrawInterface::DrawBitmap
     *  \param pBmpName Ҫ���Ƶ�λͼ��
     *  \param x1 λͼ���Ͻǵĺ�����
     *  \param y1 λͼ���Ͻǵ�������
     */
    virtual void DrawBitmap(const char * pBmpName, const short x1, const short y1);

    //##ModelId=3FD8851602F2
    /*! \brief ��������
     *
     *  �������\ref FG_OSDrawInterface::DrawPolyLine
     *  \param n �����߰����ĵ���
     *  \param vert ���е������
     *  \param color ���ߵ���ɫ
     */
    virtual void DrawPolyLine(const short n, const FG_Point * vert, const COLORVAL color);

    //##ModelId=3FD885170018
    /*! \brief ���Ƶ㻮�߾���
     *
     *  �������\ref FG_OSDrawInterface::DrawDotRect
     *  \param rect Ҫ���Ƶľ���
     *  \param color ���ε���ɫ
     */
    virtual void DrawDotRect(const FG_Rect & rect, const COLORVAL color);

protected:
    //##ModelId=3F4E0F5B028B
    /*! \brief ���캯�����û�����ֱ�ӵ���
     */
    FG_OSAdaptor();

    //##ModelId=3F4E03420206
    /*! \brief �����ʼ��
     *
     *  �ú���Ϊģ�巽������������ʵ��
     *  \return ��ʼ���Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    virtual bool InitInstance() = 0;

    //##ModelId=3F4E03DC0013
    /*! \brief �����˳�
     *
     *  �ú���Ϊģ�巽������������ʵ��
     *  \return �˳��Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    virtual bool ExitInstance() = 0;

    //##ModelId=3F4E03ED0194
    /*! \brief �������й��̣�ִ����Ϣѭ��
     *
     *  �ú���Ϊģ�巽������������ʵ��
     *  \return �˳��Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    virtual bool Execute() = 0;

    //##ModelId=409260AC00B1
    FG_OSMsgObserver * m_ppObserver[FG_MAX_SYS_MSG];    /*!< \brief ��¼���е�ϵͳ��Ϣ�Ĺ۲��ߵ����� */

    //##ModelId=3F4EFF4B0278
    static FG_OSDrawInterface * m_pDraw;                /*!< \brief ָ��Ψһ�Ļ�ͼ�ӿ����ָ�� */
    //##ModelId=3F4EFD94015F
    static FG_OSAdaptor * m_pAdaptor;                   /*!< \brief ָ��Ψһ�Ĳ���ϵͳ��������ָ�룬����ʵ�ֵ����� */
};

/*! \brief ��װ����ϵͳ��������ȫ�ַ��ʵ�\ref FG_OSAdaptor::GetAdaptor��ȫ�ֺ���
 *
 *  \return ָ��Ψһ�Ĳ���ϵͳ��������ָ��
 */
FG_OSAdaptor * FG_GetAdaptor();

#endif /* FG_OSADAPTOR_H_HEADER_INCLUDED_C0B1A949 */

/*! @} */

