/*--------------------------------------------------------------------------

	FG_RadioButton.h - ��������ť���ͷ�ļ�

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
 *  \brief ��������ť���ͷ�ļ�
 */

#ifndef FG_RADIOBUTTON_H_HEADER_INCLUDED_C0A7BA3D
#define FG_RADIOBUTTON_H_HEADER_INCLUDED_C0A7BA3D

#include "FG_TextWidget.h"

//##ModelId=3F37D6D30247
/*! \brief ��������ť��
 *
 *  ��Բ��ѡ�����������ť��һ����������ťֻ��һ���ܱ�ѡ��
 */
class FG_RadioButton : public FG_TextWidget
{
public:
    //##ModelId=3F65E8E302DE
    /*! \brief ��������ť��Ĺ��캯��
     *
     *  \param Text ��������ť����ʾ���ı�
     *  \param Rect ��������ťռ�ݵľ�������
     *  \param pSameGroup ͬ�����������ť��ͨ�������һ����������ť��������
     *  \param wID ��������ť�ؼ���Ψһ��ʶ
     */
    FG_RadioButton(const char * Text, const FG_Rect & Rect, FG_RadioButton * const pSameGroup = NULL, const WORD wID = 0);

    //##ModelId=3F65E8E302FC
	/*! \brief ��������ť�Ƿ�ѡ��
	 *
	 *  \return true    ѡ��\n
     *          false   δѡ��
     */
	bool IsChecked() const { return m_bChecked; }

    //##ModelId=3F65E8E30306
	/*! \brief �ı���������ť��ѡ��״̬
	 *
     *  �ı�ѡ��״̬����Ҫ�ػ����ؼ�
	 *  \param bChecked ѡ�л�ȡ��ѡ��
	 *                  true    ѡ��\n
     *                  false   δѡ��
	 */
	void SetChecked(bool bChecked) { m_bChecked = bChecked; RequestDraw();}

protected:
    //##ModelId=3F65E8E3031A
    /*! \brief �ػ���Ϣ\ref FG_MSG_DRAW�Ĵ�����

     *  \param pAdaptor ָ�����ϵͳ��������ָ��
     */
	void OnDraw(FG_OSAdaptor * pAdaptor);

    //##ModelId=3F65E8E3032E
    /*! \brief ���̰�����Ϣ��\ref FG_MSG_KEY��\ref FKS_DOWN���Ĵ�����

     *  \param pMsg ָ�������Ϣ�ṹ��ָ��
     */
	bool OnKeyDown(FG_Message * pMsg);

    //##ModelId=3F65E8E30342
    /*! \brief ������������Ϣ��\ref FG_MSG_MOUSE��\ref FMS_LBUTTONDOWN���Ĵ�����

     *  \param pMsg ָ�������Ϣ�ṹ��ָ��
     */
	bool OnLButtonDown(FG_Message * pMsg);

    //##ModelId=3F65E8E302CA
    bool m_bChecked;                /*!< \brief ��������ť�Ƿ�ѡ�У�true����ѡ�У�false����δ��ѡ�� */

    //##ModelId=3F65EDEC0133
    FG_RadioButton * m_pNext;       /*!< \brief �����е���һ����������ť */

private:
    //##ModelId=3F65EDEC0183
    /*! \brief �ѱ����������������ťȡ��ѡ��
     *
     *  ȡ��ѡ��ʱ��Ҫ�ػ��ͷ���֪ͨ��Ϣ\ref FRN_UNCHECKED
     */
    void UncheckGroup(void);

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_RADIOBUTTON_H_HEADER_INCLUDED_C0A7BA3D */

/*! @} */

