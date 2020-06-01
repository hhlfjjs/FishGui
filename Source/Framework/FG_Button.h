/*--------------------------------------------------------------------------

	FG_Button.h - ��ť�ؼ����ͷ�ļ�

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
/*! \addtogroup Framework
 *  @{ 
 */

/*! \file
 *  \brief ��ť�ؼ����ͷ�ļ�
*/

#ifndef FG_BUTTON_H_HEADER_INCLUDED_C0A7A9C0
#define FG_BUTTON_H_HEADER_INCLUDED_C0A7A9C0

#include "FG_TextWidget.h"

//##ModelId=3F71AE3101D7
/*! \brief ��ť�ؼ���
 *
 *  ����Ķ�����ڴ�������Ϊ��ťʹ��
 */
class FG_Button : public FG_TextWidget
{
public:
    //##ModelId=3F71AE3103A5
    /*! \brief ��ť�ؼ��Ĺ��캯��
     *
     *  \param Text ��ť�ϵ��ı�����\ref NULL�������ַ���
     *  \param Rect ��ť�ؼ�ռ�ݵľ�������
     *  \param wID ��ť�ؼ���Ψһ��ʶ
     */
    FG_Button(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
        : FG_TextWidget(Text, Rect, wID, FS_RAISED)
    {}

protected:
    //##ModelId=3F71AE3103C2
    /*! \brief \ref FG_MSG_DRAW��Ϣ�Ĵ�����
     *
     *  \param pAdaptor ָ�����ϵͳ�������ӿڵ�ָ��
     */
    void OnDraw(FG_OSAdaptor * pAdaptor);

    //##ModelId=3F71AE3103D6
    /*! \brief ���̰�����Ϣ��\ref FG_MSG_KEY��\ref FKS_DOWN���Ĵ�����

     *  \param pMsg ָ�������Ϣ�ṹ��ָ��
     */
    bool OnKeyDown(FG_Message * pMsg);

    //##ModelId=3F71AE320002
    /*! \brief ���̵�����Ϣ��\ref FG_MSG_KEY��\ref FKS_UP���Ĵ�����

     *  \param pMsg ָ�������Ϣ�ṹ��ָ��
     */
    bool OnKeyUp(FG_Message * pMsg);

    //##ModelId=3F71AE320016
    /*! \brief ������������Ϣ��\ref FG_MSG_MOUSE��\ref FMS_LBUTTONDOWN���Ĵ�����

     *  \param pMsg ָ�������Ϣ�ṹ��ָ��
     */
    bool OnLButtonDown(FG_Message * pMsg);

    //##ModelId=3F71AE32002A
    /*! \brief ������������Ϣ��\ref FG_MSG_MOUSE��\ref FMS_LBUTTONUP���Ĵ�����

     *  \param pMsg ָ�������Ϣ�ṹ��ָ��
     */
    bool OnLButtonUp(FG_Message * pMsg);

    //##ModelId=3F71AE32003E
    /*! \brief ��֤��ť�ؼ����ܵ���Ķ�ʱ����Ϣ��\ref TIMERID_UP���Ĵ�����
     *
     *  - ���ð�ťΪ͹��״̬
     *  - Ҫ���ػ�
     *  - ɾ����ʱ��
     *  - ����֪ͨ��Ϣ
     */
    void OnTimerUp(void);

private:
    //##ModelId=3F71AE310372
    /*! \brief ��֤��ť�ؼ����ܵ���Ķ�ʱ��ID

     *  Ϊ�˷�ֹ���̻����ĵ�����Ϣ��ʧ��ɰ�ť�޷�������һ����ʱ��������������µ���ť
     */
    enum
    {
        TIMERID_UP = 0xff
    };

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_BUTTON_H_HEADER_INCLUDED_C0A7A9C0 */

/*! @} */

