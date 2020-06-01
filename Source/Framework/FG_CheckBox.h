/*--------------------------------------------------------------------------

	FG_CheckBox.h - ѡ��ť���ͷ�ļ�

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
 *  \brief ѡ��ť��ť���ͷ�ļ�
 */

#ifndef FG_CHECKBOX_H_HEADER_INCLUDED_C0A79A58
#define FG_CHECKBOX_H_HEADER_INCLUDED_C0A79A58

#include "FG_TextWidget.h"

//##ModelId=3F37D6B702BF
/*! \brief ѡ��ť��
 *
 *  �ò�ѡ���ѡ��ť�������ѡ
 */
class FG_CheckBox : public FG_TextWidget
{
public:
    //##ModelId=3F65E8E201EC
	/*! \brief ѡ��ť�Ĺ��캯��
	 *
	 *  \param Text ѡ��ť��ʾ���ı�
	 *  \param Rect ѡ��ťռ�ݵľ�������
	 *  \param wID ѡ��ť��Ψһ��ʶ
	 */
	FG_CheckBox(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
		: m_bChecked(false), FG_TextWidget(Text, Rect, wID, FS_NONE) {}

    //##ModelId=3F65E8E2020A
	/*! \brief ѡ��ť�Ƿ�ѡ��
	 *
	 *  \return true    ѡ��\n
     *          false   δѡ��
     */
	bool IsChecked() const { return m_bChecked; }

    //##ModelId=3F65E8E20214
	/*! \brief �ı���������ť��ѡ��״̬
	 *
     *  �ı�ѡ��״̬����Ҫ�ػ����ؼ�
	 *  \param bChecked ѡ�л�ȡ��ѡ��
	 *                  true    ѡ��\n
     *                  false   δѡ��
	 */
	void SetChecked(bool bChecked) { m_bChecked = bChecked; RequestDraw(); }


protected:
    //##ModelId=3F65E8E20228
    /*! \brief �ػ���Ϣ\ref FG_MSG_DRAW�Ĵ�����

     *  \param pAdaptor ָ�����ϵͳ��������ָ��
     */
	void OnDraw(FG_OSAdaptor * pAdaptor);

    //##ModelId=3F65E8E2023C
    /*! \brief ���̰�����Ϣ��\ref FG_MSG_KEY��\ref FKS_DOWN���Ĵ�����

     *  \param pMsg ָ�������Ϣ�ṹ��ָ��
     */
	bool OnKeyDown(FG_Message * pMsg);

    //##ModelId=3F65E8E20247
    /*! \brief ������������Ϣ��\ref FG_MSG_MOUSE��\ref FMS_LBUTTONDOWN���Ĵ�����

     *  \param pMsg ָ�������Ϣ�ṹ��ָ��
     */
	bool OnLButtonDown(FG_Message * pMsg);

    //##ModelId=3F65E8E20161
    bool m_bChecked;                /*!< \brief ѡ��ť�Ƿ�ѡ�У�true����ѡ�У�false����δ��ѡ�� */

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_CHECKBOX_H_HEADER_INCLUDED_C0A79A58 */

/*! @} */

