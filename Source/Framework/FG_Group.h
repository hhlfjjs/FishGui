/*--------------------------------------------------------------------------

	FG_Group.h - ����ؼ����ͷ�ļ�

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
 *  \brief ����ؼ����ͷ�ļ�
 */

#ifndef FG_GROUP_H_HEADER_INCLUDED_C0A7D115
#define FG_GROUP_H_HEADER_INCLUDED_C0A7D115

#include "FG_TextWidget.h"

//##ModelId=3F584D87031B
/*! \brief ����ؼ���
 *
 *  �ÿؼ������ڴ����ϣ���ʾΪ��̬�ľ����������ڰѿؼ�����
 */
class FG_Group : public FG_TextWidget
{
public:
    //##ModelId=3F6193A70193
	/*! \brief ����ؼ��Ĺ��캯��
	 *
	 *  \param Text ����ؼ����Ͻ���ʾ�ı��⣬��\ref NULL�������ַ���
	 *  \param Rect ����ؼ�ռ�ݵľ�������
	 *  \param wID ����ؼ���Ψһ��ʶ��ȱʡΪ0
	 */
	FG_Group(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
        : FG_TextWidget(Text, Rect, wID, FS_NONE|GS_TRANSPARENT) {}

    //##ModelId=3F6EAC8F0088
    /*! \brief ���ؿؼ��ܷ�õ�����ı�־
     *
     *  ����ؼ���Զ���ܵõ�����
     *  \return false   �ÿؼ����ܵõ�����
     */
    bool CanGetFocus(void) const { return false; }

protected:
    //##ModelId=3F6193A701A6
    /*! \brief �ػ���Ϣ\ref FG_MSG_DRAW�Ĵ�����
     *
     *  \param pAdaptor ָ�����ϵͳ��������ָ��
     */
	void OnDraw(FG_OSAdaptor * pAdaptor);

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_GROUP_H_HEADER_INCLUDED_C0A7D115 */

/*! @} */

