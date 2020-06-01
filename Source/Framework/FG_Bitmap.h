/*--------------------------------------------------------------------------

	FG_Bitmap.h - λͼ�ؼ����ͷ�ļ�

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
 *  \brief λͼ�ؼ����ͷ�ļ�
*/

#ifndef FG_BITMAP_H_HEADER_INCLUDED_C0A7F853
#define FG_BITMAP_H_HEADER_INCLUDED_C0A7F853

#include "FG_TextWidget.h"

//##ModelId=3F37D72700AE
/*! \brief λͼ�ؼ���
 *
 *  λͼ�ؼ����Է��ڴ����ϣ�������ʾ��̬��λͼ��\n
 *  ͨ����ʱ���ı䵱ǰ��ʾ��λͼ������ʵ�ֶ�������ʾ��
 */
class FG_Bitmap : public FG_TextWidget
{
public:
    //##ModelId=3F5DE0D00234
    /*! \brief ���캯��
     *
     *  \param Text Ҫ��ʾ��λͼ����
     *  \param Rect λͼ��ʾ�ľ���������û�вü���������£�Rect�����Ͻ�����Ϊλͼ��ʾ�����Ͻ����꣬
     *              Rect�����½����걻���ԣ�λͼ���ᱻ�ü���
     *  \param wID λͼ�ؼ���Ψһ��ʶ��ȱʡֵΪ0
     *��\param wStyle λͼ�ؼ��ı߿���ȱʡֵΪ\ref FS_NONE|\ref GS_TRANSPARENT
     */
	FG_Bitmap(const char * Text, const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE|GS_TRANSPARENT)
		: FG_TextWidget(Text, Rect, wID, wStyle) {}

    //##ModelId=3F71AB1E03A2
    /*! \brief ���ؿؼ��ܷ�õ�����ı�־
     *
     *  λͼ�ؼ���Զ���ܵõ�����
     *  \return false   �ÿؼ����ܵõ�����
     */
    bool CanGetFocus(void) const { return false; }

protected:
    //##ModelId=3F5DE0D00284
    /*! \brief \ref FG_MSG_DRAW��Ϣ�Ĵ�����
     *
     *  \param pAdaptor ָ�����ϵͳ�������ӿڵ�ָ��
     */
	void OnDraw(FG_OSAdaptor * pAdaptor);

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_BITMAP_H_HEADER_INCLUDED_C0A7F853 */

/*! @} */

