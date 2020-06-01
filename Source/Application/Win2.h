/*--------------------------------------------------------------------------

	Win2.h - �û�����Ĵ���2���ͷ�ļ�

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
 *  \brief �û�����Ĵ���2���ͷ�ļ�
 */

#ifndef WIN2_H_HEADER_INCLUDED_C0A87F67
#define WIN2_H_HEADER_INCLUDED_C0A87F67

#include "../Framework/FG_Framework.h"

//##ModelId=3F71AB020366
/*! \brief �û�����Ĵ���2��
 */
class Win2 : public FG_Window
{
public:
    //##ModelId=3F71AB040142
    /*! \brief ����2�ϵĿؼ�ID
     */
    enum
    {
        ID_RADIO1 = 1,
        ID_RADIO2,
        ID_RADIO3,
        ID_RADIO4,
        ID_RADIO5,
        ID_RADIO6,
        ID_OK,
        ID_CANCEL
    };

    //##ModelId=3F71AB0401CE
    /*! \brief ����2�Ĺ��캯��
     *  
     *  �������еĿؼ���ע���ݼ�
     *  \param wID ����2��Ψһ��ʶ��ȱʡΪ0
     */
    Win2(WORD wID = 0);

protected:
    //##ModelId=3F71AB0401D8
    /*! \brief ��ȷ������ť����֪ͨ��Ϣ��\ref FBN_PRESSED��\ref ID_OK���Ĵ�����
     */
    void OnOK(void);

    //##ModelId=3F71AB0401EC
    /*! \brief ��ȡ������ť����֪ͨ��Ϣ��\ref FBN_PRESSED��\ref ID_CANCEL���Ĵ�����
     */
    void OnCancel(void);

    DECLARE_MESSAGE_MAP()
};

#endif /* WIN2_H_HEADER_INCLUDED_C0A87F67 */

/*! @} */

