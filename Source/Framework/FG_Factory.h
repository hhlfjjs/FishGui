/*--------------------------------------------------------------------------

	FG_Factory.h - �������ͷ�ļ�

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
 *  \brief �������ͷ�ļ�
 */

#ifndef FG_FACTORY_H_HEADER_INCLUDED_C0A7A9C0
#define FG_FACTORY_H_HEADER_INCLUDED_C0A7A9C0

#include "../Utility/FG_Utility.h"
#include "FG_Button.h"
#include "FG_Bitmap.h"
#include "FG_Label.h"
#include "FG_Group.h"
#include "FG_Edit.h"
#include "FG_CheckBox.h"
#include "FG_RadioButton.h"

//##ModelId=3F37D6AD0116
/*! \brief ������
 *
 *  �����װ���пؼ��Ĵ������̣��û��ɸ��Ǵ����еĽӿں�������Ϊ������ͬ�Ŀؼ�����
 */
class FG_Factory
{
public:
    //##ModelId=3F5B470401E5
    /*! \brief ���캯��
     */
    FG_Factory() {}

    //##ModelId=3F71ACAE0181
    /*! \brief ����������
     */
    virtual ~FG_Factory() {}

    //##ModelId=3F71ACAE0195
    /*! \brief ����λͼ�ؼ�
     *
     *  \param Text λͼ�ؼ��ı��⣬��\ref NULL�������ַ���
     *  \param Rect λͼ�ؼ����ڵľ�������
     *  \param wID λͼ�ؼ���Ψһ��ʶ
     *  \param wStyle λͼ�ؼ���\ref Style
     *  \return ��������λͼ�ؼ�
     */
    virtual FG_Bitmap * CreateBitmap(const char * Text, const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE|GS_TRANSPARENT)
    {
        return new FG_Bitmap(Text, Rect, wID, wStyle);
    }

    //##ModelId=3F71ACAE0221
    /*! \brief ������ť�ؼ�
     *
     *  \param Text ��ť�ؼ��ı��⣬��\ref NULL�������ַ���
     *  \param Rect ��ť���ڵľ�������
     *  \param wID ��ť��Ψһ��ʶ
     *  \return �������İ�ťָ��
     */
    virtual FG_Button * CreateButton(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
    {
        return new FG_Button(Text, Rect, wID);
    }

    //##ModelId=3F71ACAE02A3
    /*! \brief ����ѡ��ť�ؼ�
     *
     *  \param Text ѡ��ť�ؼ��ı��⣬��\ref NULL�������ַ���
     *  \param Rect ѡ��ť���ڵľ�������
     *  \param wID ѡ��ť��Ψһ��ʶ
     *  \return ��������ѡ��ťָ��
     */
    virtual FG_CheckBox * CreateCheckBox(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
    {
        return new FG_CheckBox(Text, Rect, wID);
    }

    //##ModelId=3F71ACAE032F
    /*! \brief �����༭�ؼ�
     *
     *  \param Text �༭�ؼ��ĳ�ʼ�ı�����\ref NULL�������ַ���
     *  \param Rect �༭�ؼ����ڵľ�������
     *  \param wLimit �༭�ؼ������ɵ�����ַ�����
     *  \param wID �༭�ؼ���Ψһ��ʶ
     *  \param wStyle �༭�ؼ���\ref Style
     *  \return �������ı༭�ؼ�ָ��
     */
    virtual FG_Edit * CreateEdit(const char * Text, const FG_Rect & Rect, const WORD wLimit, WORD wID = 0, const WORD wStyle = TS_LEFT|FS_RECESSED)
    {
        return new FG_Edit(Text, Rect, wLimit, wID, wStyle);
    }

    //##ModelId=3F71ACAF0038
    /*! \brief ��������ؼ�
     *
     *  \param Text ����ؼ��ı��⣬��\ref NULL�������ַ���
     *  \param Rect ����ؼ����ڵľ�������
     *  \param wID ����ؼ���Ψһ��ʶ
     *  \return �������ķ���ؼ�ָ��
     */
    virtual FG_Group * CreateGroup(const char * Text, const FG_Rect & Rect, const WORD wID = 0)
    {
        return new FG_Group(Text, Rect, wID);
    }

    //##ModelId=3F71ACAF00E2
    /*! \brief �������ֱ�ǩ
     *
     *  \param Text ���ֱ�ǩ�ı��⣬��\ref NULL�������ַ���
     *  \param Rect ���ֱ�ǩ���ڵľ�������
     *  \param wID ���ֱ�ǩ��Ψһ��ʶ
     *  \param wStyle ���ֱ�ǩ��\ref Style
     *  \return �����������ֱ�ǩָ��
     */
    virtual FG_Label * CreateLabel(const char * Text, const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE|GS_TRANSPARENT)
    {
        return new FG_Label(Text, Rect, wID, wStyle);
    }

    //##ModelId=3F71ACAF01BE
    /*! \brief ������������ť�ؼ�
     *
     *  \param Text ��������ť�ؼ��ı��⣬��\ref NULL�������ַ���
     *  \param Rect ��������ť���ڵľ�������
     *  \param pSameGroup ͬ�����������ť��ͨ�������һ����������ť��������
     *  \param wID ��������ť��Ψһ��ʶ
     *  \return ����������������ťָ��
     */
    virtual FG_RadioButton * CreateRadioButton(const char * Text, const FG_Rect & Rect, FG_RadioButton * const pSameGroup = NULL, const WORD wID = 0)
    {
        return new FG_RadioButton(Text, Rect, pSameGroup, wID);
    }
};

#endif /* FG_FACTORY_H_HEADER_INCLUDED_C0A7A9C0 */

/*! @} */

