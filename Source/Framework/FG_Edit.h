/*--------------------------------------------------------------------------

	FG_Edit.h - �༭�ؼ����ͷ�ļ�

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
 *  \brief �༭�ؼ����ͷ�ļ�
 */

#ifndef FG_EDIT_H_HEADER_INCLUDED_C0A79742
#define FG_EDIT_H_HEADER_INCLUDED_C0A79742

#include "FG_Label.h"

//##ModelId=3F37D6F50106
/*! \brief �༭�ؼ���
 *
 *  �ÿؼ����Է����ڴ����ϣ��û�ͨ���ÿؼ�������������
 */
class FG_Edit : public FG_Label
{
public:
    //##ModelId=3F65E8E20322
	/*! \brief �༭�ؼ��Ĺ��캯��
	 *
	 *  \param Text �༭�ؼ�����ʾ�ĳ�ʼ�ı�
	 *  \param Rect �༭�ؼ�ռ�ݵľ�������
	 *  \param wLimit �༭�ؼ��������������ַ���
	 *  \param wID �༭�ؼ���Ψһ��ʶ��ȱʡΪ0
	 *  \param wStyle �༭�ؼ���\ref Style��ȱʡΪ\ref TS_LEFT|\ref FS_RECESSED
	 */
	FG_Edit(const char * Text, const FG_Rect & Rect, const WORD wLimit, const WORD wID = 0, const WORD wStyle = TS_LEFT|FS_RECESSED);

    //##ModelId=3F6EAC8F0074
    /*! \brief ���ؿؼ��ܷ�õ�����ı�־
     *
     *  �༭�ؼ��ܵõ�����
     *  \return true   �ÿؼ��ܵõ�����
     */
    bool CanGetFocus() const { return true; }

protected:
    //##ModelId=3F65E8E20368
    /*! \brief �ػ���Ϣ\ref FG_MSG_DRAW�Ĵ�����
     *
     *  \param pAdaptor ָ�����ϵͳ��������ָ��
     */
	void OnDraw(FG_OSAdaptor * pAdaptor);

    //##ModelId=3F65E8E2037C
    /*! \brief ���̰�����Ϣ��\ref FG_MSG_KEY��\ref FKS_DOWN���Ĵ�����
     *
     *  ���⴦��\ref FVK_DELETE��\ref FVK_LEFT��\ref FVK_RIGHT�ȼ�����������0--9
     *  \param pMsg ָ�������Ϣ�ṹ��ָ��
     */
	bool OnKeyDown(FG_Message * pMsg);

    //##ModelId=3F65E8E2039A
    /*! \brief �����Ϣ��\ref FG_MSG_MOUSE���Ĵ�����
     *
     *  \param pMsg ָ�������Ϣ�ṹ��ָ��
     */
	bool OnMouse(FG_Message * pMsg);

    //##ModelId=3F65E8E203AF
    /*! \brief �����˸�Ķ�ʱ����Ϣ��\ref TIMERID_CURSOR���Ĵ�����
     *
     */
    void OnCursorTimer(void);

    //##ModelId=3F65E8E203B9
    /*! \brief �����л���Ϣ\ref FG_MSG_FOCUS�Ĵ�����
     *
     *  \param pMsg ָ�򽹵��л���Ϣ�ṹ��ָ��
     */
    void OnFocus(FG_Message * pMsg);

    //##ModelId=3F65E8E202C9
	WORD m_wLimit;                  /*!< \brief �༭�ؼ���������������ַ����� */
    //##ModelId=3F65E8E202E7
	WORD m_wCursorPos;              /*!< \brief ���ĵ�ǰλ�� */
    //##ModelId=3F65E8E20304
	bool m_bDrawCursor;             /*!< \brief ����Ƿ���ʾ��true��ʾ��ʾ��false��ʾ����ʾ */

private:
    //##ModelId=3F65E8E20296
    /*! \brief ���ƹ����˸�Ķ�ʱ��ID
     */
    enum
    {
        TIMERID_CURSOR = 0xff
    };

    //##ModelId=3F65E8E203D7
    /*! \brief �ڱ༭�ؼ��ĵ�ǰ���λ�ò���һ���ַ�
     *
     *  \param wKey Ҫ������ַ���\ref Virtual_Key
     */
    void InsertChar(WORD wKey);

    //##ModelId=3F65E8E30003
	/*! \brief ɾ����ǰ�����һ���ַ�
	 */
	void DeleteChar();

    //##ModelId=3F65E8E30017
	/*! \brief �ػ��ı���������꣩
	 *
	 *  �ѹ������Ϊ��ʾ��Ȼ��Ҫ���ػ�
	 */
	void DrawWithCursor();

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_EDIT_H_HEADER_INCLUDED_C0A79742 */

/*! @} */

