/*--------------------------------------------------------------------------

	MyButton.h - �û������Բ�Ǿ��ΰ�ť���ͷ�ļ�

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
 *  \brief �û������Բ�Ǿ��ΰ�ť���ͷ�ļ�
 */

#ifndef MYBUTTON_H_HEADER_INCLUDED_C0A7A9C0
#define MYBUTTON_H_HEADER_INCLUDED_C0A7A9C0

#include "../Framework/FG_Framework.h"

//##ModelId=3F71AB0202D1
/*! \brief �û������Բ�Ǿ��ΰ�ť��
 */
class MyButton : public FG_Button
{
public:
    //##ModelId=3F71AB030371
    /*! \brief ���캯��
     *
     *  \param Text Բ�Ǿ��ΰ�ť�ؼ��ı���
     *  \param Rect Բ�Ǿ��ΰ�ť�ؼ�ռ�ݵľ�������
     *  \param wID Բ�Ǿ��ΰ�ť�ؼ���Ψһ��ʶ
     */
    MyButton(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
        : FG_Button(Text, Rect, wID)
    {}

protected:
    //##ModelId=3F71AB03038F
    /*! \brief �ػ���Ϣ\ref FG_MSG_DRAW�Ĵ�����

     *  \param pAdaptor ָ�����ϵͳ��������ָ��
     */
    void OnDraw(FG_OSAdaptor * pAdaptor);

    DECLARE_MESSAGE_MAP()
};

#endif /* MYBUTTON_H_HEADER_INCLUDED_C0A7A9C0 */

/*! @} */

