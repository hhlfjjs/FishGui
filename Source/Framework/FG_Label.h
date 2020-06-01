/*--------------------------------------------------------------------------

	FG_Label.h - ���ֱ�ǩ���ͷ�ļ�

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
 *  \brief ���ֱ�ǩ���ͷ�ļ�
 */

#ifndef FG_LABEL_H_HEADER_INCLUDED_C0A7989C
#define FG_LABEL_H_HEADER_INCLUDED_C0A7989C

#include "FG_TextWidget.h"

//##ModelId=3F37D70F0185
/*! \brief ���ֱ�ǩ��
 *
 *  �����ڴ�������ʾ��̬�ı�
 */
class FG_Label : public FG_TextWidget
{
public:
    //##ModelId=3F5EE86B009C
	/*! \brief ���ֱ�ǩ�Ĺ��캯��
	 *
     *  ���ֵĶ��뷽ʽȱʡΪ\ref TS_CENTER
	 *  \param Text ���ֱ�ǩ���ı�����\ref NULL�������ַ���
	 *  \param Rect ���ֱ�ǩռ�ݵľ�������
	 *  \param wID ���ֱ�ǩ��Ψһ��ʶ��ȱʡΪ0
	 *  \param wStyle ���ֱ�ǩ�ı߿���ȱʡΪ\ref FS_NONE|\ref GS_TRANSPARENT
	 *  \return  
	 */
	FG_Label(const char * Text, const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE|GS_TRANSPARENT)
		: FG_TextWidget(Text, Rect, wID, wStyle)
	{
		if (! (m_wStyle & TS_MASK))
			m_wStyle |= TS_CENTER;
	}

    //##ModelId=3F6EAC8F00A6
    /*! \brief ���ؿؼ��ܷ�õ�����ı�־
     *
     *  �ı���ǩ��Զ���ܵõ�����
     *  \return false   �ÿؼ����ܵõ�����
     */
    bool CanGetFocus(void) const { return false; }

protected:
    //##ModelId=3F5EE86B00C6
    /*! \brief �ػ���Ϣ\ref FG_MSG_DRAW�Ĵ�����
     *
     *  \param pAdaptor ָ�����ϵͳ��������ָ��
     */
	void OnDraw(FG_OSAdaptor * pAdaptor);

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_LABEL_H_HEADER_INCLUDED_C0A7989C */

/*! @} */

