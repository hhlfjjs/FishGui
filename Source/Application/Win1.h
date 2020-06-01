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
/*! \addtogroup Application
 *  @{ 
 */

/*! \file
 *  \brief �û�����Ĵ���1���ͷ�ļ�
 */

#ifndef WIN1_H_HEADER_INCLUDED_C0A87F67
#define WIN1_H_HEADER_INCLUDED_C0A87F67

#include "../Framework/FG_Framework.h"

//##ModelId=3F71AB020316
/*! \brief �û�����Ĵ���1��
 */
class Win1 : public FG_Window
{
public:
    //##ModelId=3F71AB040016
    /*! \brief ����1�ϵĿؼ�ID
     */
    enum
    {
        ID_BITMAP = 1,
        ID_START,
        ID_STOP,
        ID_OPEN,
        ID_CLOSE
    };

    //##ModelId=3F71AB0400CA
    /*! \brief ����1�Ĺ��캯��
     *  
     *  �������еĿؼ���ע���ݼ�
     *  \param wID ����1��Ψһ��ʶ��ȱʡΪ0
     */
    Win1(WORD wID = 0);

protected:
    //##ModelId=3F71AB040066
    /*! \brief ����1�ϵĶ���2�ؼ��Ķ�ʱ��ID
     */
    enum
    {
        ID_ANIMATION_TIMER = 1
    };

    //##ModelId=3F71AB0400DE
    /*! \brief ����������ť����֪ͨ��Ϣ��\ref FBN_PRESSED��\ref ID_START���Ĵ�����
     */
    void OnStart(void);

    //##ModelId=3F71AB0400E9
    /*! \brief ��ֹͣ����ť����֪ͨ��Ϣ��\ref FBN_PRESSED��\ref ID_STOP���Ĵ�����
     */
    void OnStop(void);

    //##ModelId=3F71AB0400FD
    /*! \brief ���򿪴���2����ť����֪ͨ��Ϣ��\ref FBN_PRESSED��\ref ID_OPEN���Ĵ�����
     */
    void OnOpen(void);

    //##ModelId=3F71AB040110
    /*! \brief ���رա���ť����֪ͨ��Ϣ��\ref FBN_PRESSED��\ref ID_CLOSE���Ĵ�����
     */
    void OnClose(void);

    //##ModelId=3F71AB040124
    /*! \brief ��ʱ����Ϣ��\ref ID_ANIMATION_TIMER���Ĵ�����
     *
     *  ��ʾ��һ֡λͼ
     */
    void OnTimer(void);

    //##ModelId=3F71AB0400A2
    int m_iBmpNum;              /*!< \brief ��ǰ��ʾ�Ķ���֡�� */
    //##ModelId=3F71AB0400B6
    bool m_bStart;              /*!< \brief �����Ƿ�������true��ʾ������false��ʾֹͣ */

    DECLARE_MESSAGE_MAP()
};

#endif /* WIN1_H_HEADER_INCLUDED_C0A87F67 */

/*! @} */

