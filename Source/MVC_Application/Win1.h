/*--------------------------------------------------------------------------

	Win1.h - �û�����Ĵ���1���ͷ�ļ�

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
/*! \addtogroup MVC_Application
 *  @{ 
 */

/*! \file
 *  \brief �û�����Ĵ���1���ͷ�ļ�
 */

#ifndef WIN1_H_HEADER_INCLUDED_C0A87F67
#define WIN1_H_HEADER_INCLUDED_C0A87F67

#include "../../Source/Framework/FG_Framework.h"
#include "MyModel.h"

/*! \brief �û�����Ĵ���1��
 */
class Win1 : public FG_Window
{
public:
    /*! \brief ����1�ϵĿؼ�ID
     */
    enum
    {
        ID_DISPLAY1 = 1,
        ID_DISPLAY2,
        ID_CHECK1,
        ID_CHECK2,
        ID_BUTTON
    };

    /*! \brief ����1�Ĺ��캯��
     *  
     *  �������еĿؼ���ע���ݼ�
     *  \param wID ����1��Ψһ��ʶ��ȱʡΪ0
     */
    Win1(WORD wID = 0);

protected:
    /*! \brief ����1�ϵĶ�ʱ��ID
     */
    enum
    { 
        ID_TIMER = 1
    };

    /*! \brief ֪ͨ��Ϣ�Ĵ����� */
    void OnCheck1Checked(void) { m_bData1 = true; }

    /*! \brief ֪ͨ��Ϣ�Ĵ����� */
    void OnCheck2Checked(void) { m_bData2 = true; }

    /*! \brief ֪ͨ��Ϣ�Ĵ����� */
    void OnCheck1Unchecked(void) { m_bData1 = false; }

    /*! \brief ֪ͨ��Ϣ�Ĵ����� */
    void OnCheck2Unchecked(void) { m_bData2 = false; }

    /*! \brief ֪ͨ��Ϣ�Ĵ����� */
    void OnButtonPressed(void) { GetMyModel()->AdjustData(); }

    /*! \brief ��ʱ����Ϣ�Ĵ����� */
    void OnTimer(void);

    /*! \brief ��ͼ֪ͨ��Ϣ�Ĵ����� */
    void OnViewUpdate(void);

private:
    bool m_bData1;      /*!< \brief �Ƿ���Ҫ��������1 */
    bool m_bData2;      /*!< \brief �Ƿ���Ҫ��������2 */

    DECLARE_MESSAGE_MAP()
};

#endif /* WIN1_H_HEADER_INCLUDED_C0A87F67 */

/*! @} */

