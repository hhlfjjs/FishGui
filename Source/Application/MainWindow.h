/*--------------------------------------------------------------------------

	MainWindow.h - �û���������������ͷ�ļ�

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
/*! \addtogroup Application
 *  @{ 
 */

/*! \file
 *  \brief �û���������������ͷ�ļ�
 */

#ifndef MAINWINDOW_H_HEADER_INCLUDED_C0A87F67
#define MAINWINDOW_H_HEADER_INCLUDED_C0A87F67

#include "../Framework/FG_Framework.h"

//##ModelId=3F49CE36016D
/*! \brief �û��������������
 */
class MainWindow : public FG_Window
{
public:
    //##ModelId=3F6EAC940107
    /*! \brief �������ϵĿؼ�ID
     */
    enum 
    { 
        ID_RADIO1 = 1,
        ID_RADIO2,
        ID_RADIO3,
        ID_RADIO4,
        ID_RADIO5,
        ID_RADIO6,
        ID_EDIT1,
        ID_CHECK1,
        ID_CHECK2,
        ID_EDIT2,
        ID_OPEN,
        ID_FACTORY,
        ID_START,
        ID_STOP,
        ID_BITMAP
    };

    //##ModelId=3F57F6DE01EE
    /*! \brief �����ڵĹ��캯��
     *  
     *  �������еĿؼ���ע���ݼ�
     *  \param wID �����ڵ�Ψһ��ʶ��ȱʡΪ0
     */
    MainWindow(WORD wID = 0);

protected:
    //##ModelId=3F71AB03019B
    /*! \brief �������ϵĶ���1�ؼ��Ķ�ʱ��ID
     */
    enum
    {
        ID_ANIMATION_TIMER = 1
    };

    //##ModelId=3F6EAC940143
    /*! \brief ��������ťѡ��֪ͨ��Ϣ�Ĵ�����
     */
    void OnRadioChecked(FG_Message * pMsg);

    //##ModelId=3F6EAC940157
    /*! \brief ѡ��ťѡ�л�ȡ��ѡ��֪ͨ��Ϣ�Ĵ�����
     */
    void OnCheckChanged(FG_Message * pMsg);

    //##ModelId=3F71AB030245
    /*! \brief ����������ť֪ͨ��Ϣ�Ĵ�����
     */
    void OnStart(void);

    //##ModelId=3F71AB030277
    /*! \brief ��ֹͣ����ť֪ͨ��Ϣ�Ĵ�����
     */
    void OnStop(void);

    //##ModelId=3F71AB0302A9
    /*! \brief ���򿪴���1����ť֪ͨ��Ϣ�Ĵ�����
     */
    void OnOpen(void);

    //##ModelId=3F71AB0302DB
    /*! \brief ��Բ�ǰ�ť���͡����ǰ�ť���л���ť֪ͨ��Ϣ�Ĵ�����
     *
     *  �л���ǰʹ�õĹ�����
     */
    void OnFactory(void);
    
    //##ModelId=3F71AB03030D
    /*! \brief ��ʱ����\ref ID_ANIMATION_TIMER����Ϣ�Ĵ�����
     *
     *  ��ʾ��һ֡λͼ
     */
    void OnTimer(void);

    //##ModelId=3F71AB0301CD
    int m_iBmpNum;              /*!< \brief ��ǰ��ʾ�Ķ���֡�� */
    //##ModelId=3F71AB0301EB
    bool m_bStart;              /*!< \brief �����Ƿ�������true��ʾ������false��ʾֹͣ */
    //##ModelId=3F71AB03021D
    bool m_bNewFactory;         /*!< \brief ��ǰʹ�õĹ�����ı�־��true��ʾʹ���û�����Ĺ����࣬false��ʾʹ��ȱʡ������ */

    DECLARE_MESSAGE_MAP()
};

#endif /* MAINWINDOW_H_HEADER_INCLUDED_C0A87F67 */

/*! @} */

