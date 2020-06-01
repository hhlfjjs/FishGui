/*--------------------------------------------------------------------------

	FG_TextWidget.h - �ı��ؼ��������ͷ�ļ�

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
 *  \brief �ı��ؼ��������ͷ�ļ�
*/

#ifndef FG_TEXTWIDGET_H_HEADER_INCLUDED_C0A7F838
#define FG_TEXTWIDGET_H_HEADER_INCLUDED_C0A7F838

#include "../Utility/FG_Utility.h"
#include "FG_Widget.h"

//##ModelId=3F388AF702A9
/*! \brief �ı��ؼ��������ͷ�ļ�
 *
 *  �������������д����ı�������
*/
class FG_TextWidget : public FG_Widget
{
public:
    //##ModelId=3F5B47050056
    /*! \brief �ı��ؼ�������Ĺ��캯��
     *
     *  \param Text �ı��ؼ���������ı�
     *  \param Rect �ı��ؼ���������ռ�ݵ���Ļ����
     *  \param wID �ı��ؼ��������Ψһ��ʶ
     *  \param wStyle �ı��ؼ��������\ref Style
     */
    FG_TextWidget(const char * Text, const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE)
        : m_Text(Text), FG_Widget(Rect, wID, wStyle)
    {}

    //##ModelId=3F5B470500B0
    /*! \brief �õ��ÿؼ����ı�
     *
     *  \return �ÿؼ����ı�
     */
    char * GetText(void) const { return m_Text.DataGet(); }
    
    //##ModelId=3F5B470500C4
    /*! \brief ���øÿؼ����ı�
     *
     *  ��Ҫ�ػ��ÿؼ�
     *  \param Text Ҫ���õ��ı�
     */
    void SetText(char * const Text) { m_Text.DataSet(Text); RequestDraw(); }
    
    //##ModelId=3F6EAC8F01DC
    /*! \brief �õ��ÿؼ����ı��ĳ���
     *
     *  \return �ÿؼ����ı��ĳ���
     */
    WORD TextLength(void) const { return m_Text.Length(); }

    //##ModelId=3F6EAC8F01F0
    /*! \brief �����ı��Ľ����
     *
     *  \param pAdaptor ָ�����ϵͳ�����������ָ��
     *  \param x ���������ϽǺ�����
     *  \param y ���������Ͻ�������
     */
    void DrawTextFocus(FG_OSAdaptor * const pAdaptor, const WORD x, const WORD y);

protected:
    //##ModelId=409260D50150
    FG_String m_Text;           /*!< \brief �ÿؼ��б�����ı� */

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_TEXTWIDGET_H_HEADER_INCLUDED_C0A7F838 */

/*! @} */

