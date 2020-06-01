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
/*! \addtogroup MVC_Application
 *  @{ 
 */

/*! \file
 *  \brief �û���������������ͷ�ļ�
 */

#ifndef MAINWINDOW_H_HEADER_INCLUDED_C0A87F67
#define MAINWINDOW_H_HEADER_INCLUDED_C0A87F67

#include "../../Source/Framework/FG_Framework.h"

/*! \brief �û��������������
 */
class MainWindow : public FG_Window
{
public:
    /*! \brief �������ϵĿؼ�ID
     */
    enum 
    { 
        ID_DISPLAY1 = 1,
        ID_DISPLAY2,
        ID_DISPLAY3,
        ID_DISPLAY4
    };

    /*! \brief �����ڵĹ��캯��
     *  
     *  �������еĿؼ���ע���ݼ�
     *  \param wID �����ڵ�Ψһ��ʶ��ȱʡΪ0
     */
    MainWindow(WORD wID = 0);

protected:
    /*! \brief ��ͼ����֪ͨ��Ϣ�Ĵ�����
     */
    void OnViewUpdate(void);

    DECLARE_MESSAGE_MAP()
};

#endif /* MAINWINDOW_H_HEADER_INCLUDED_C0A87F67 */

/*! @} */

