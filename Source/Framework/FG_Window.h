/*--------------------------------------------------------------------------

	FG_Window.h - �������ͷ�ļ�

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
 *
*/

#ifndef FG_WINDOW_H_HEADER_INCLUDED_C0AD431E
#define FG_WINDOW_H_HEADER_INCLUDED_C0AD431E

#include "../Utility/FG_Utility.h"
#include "FG_Container.h"
#include "FG_Widget.h"
#include "FG_KeyMap.h"

//##ModelId=3F52B6BD00A5
/*! \brief ������
 *
 *  �������������Է�������Ļ����Ϊ���ڣ������п������ɸ��ֲ�ͬ�Ŀؼ�
 */
class FG_Window : public FG_Container
{
public:
    //##ModelId=3F5838220352
    /*! \brief ���캯��
     *
     *  ��ǰ�н���Ŀؼ�ָ��\ref m_pFocus������Ϊ\ref NULL
     *
     *  \param title ���ڱ��⣬��0�������ַ���
     *  \param wID ���ڵ�Ψһ��ʶ��ȱʡֵΪ0
     *  \param wStyle \ref Style
     */
    FG_Window(const char * title, const WORD wID = 0, const WORD wStyle = FS_NONE)
        : m_Title(title), m_pFocus(NULL), FG_Container(wID, wStyle)
        {}

    //##ModelId=3F58382201CB
    /*! \brief ���캯��
     *
     *  ��ǰ�н���Ŀؼ�ָ��\ref m_pFocus������Ϊ\ref NULL
     *
     *  \param title ���ڱ��⣬��0�������ַ���
     *  \param Rect ����ռ�ݵľ���Ԫ��
     *  \param wID ���ڵ�Ψһ��ʶ��ȱʡֵΪ0
     *  \param wStyle \ref Style
     */
    FG_Window(const char * title, const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE) 
        : m_Title(title), m_pFocus(NULL), FG_Container(Rect, wID, wStyle)
        {}

    //##ModelId=3F5B470501FA
    /*! \brief �ڴ��������һ���ؼ�
     *
     *  �ؼ�֮��һ�㲻���ص���������ص�������ӵĿؼ�������ǰ��ӵĿؼ������㱻�л�������ӵĿؼ�
     *
     *  \param pWidget Ҫ��ӵĿؼ�ָ��
     *  \return ��Ӳ����Ƿ�ɹ�\n
     *          true�� �ɹ�\n
     *          false��ʧ��
     */
    bool AddWidget(FG_Widget * const pWidget);

    //##ModelId=3F5B47050240
    /*! \brief �Ӵ�����ɾ��һ���ؼ�
     *
     *  ���ɾ�����ǵ�ǰ����ؼ����ѽ���ָ����Ϊ\ref NULL��֮���û���Ҫ�Լ���������
     *  \param pWidget Ҫɾ���Ŀؼ�ָ��
     *  \return ɾ�������Ƿ�ɹ�\n
     *          true�� �ɹ�\n
     *          false��ʧ��
     */
    bool RemoveWidget(FG_Widget * const pWidget);

    //##ModelId=3F6193A800D6
    /*! \brief ���ظô��ڵĿͻ�������
     *
     *  ���ǻ�����㷨�����ڵĿͻ���Ϊ��ȥ�߿�ͱ�������ľ���
     *  \param rect ���صĿͻ�������
     */
    void GetClientRect(FG_Rect & rect) const;

    //##ModelId=3F5EDD9E03DF
    /*! \brief ע���ݼ�
     *
     *  ��ݼ��ĺ���Ϊ����������Ϊ���㴰��ʱ������û�����ֵΪwOrgKey�ļ�����Ϣ��
     *  ֱ�ӰѸü�����Ϣ���͸���ʶΪwID�Ŀؼ������Ѽ�ֵת����wActKey
     *  \param wOrgKey ԭʼ��\ref Virtual_Key
     *  \param wActKey ���͵���Ӧ�Ŀؼ�ʱ��Ӧת���ɵ�ʵ��\ref Virtual_Key
     *  \param wID ע���ݼ��Ŀؼ�
     *  \return ɾ�������Ƿ�ɹ�\n
     *          true�� �ɹ�\n
     *          false��ʧ��
     */
	bool RegisterKey(const WORD wOrgKey, const WORD wActKey, const WORD wID);

    //##ModelId=3F6193A800F4
    /*! \brief �ı佹��ؼ�
     *
     *  ����ؼ�����ǰ�����뽹��Ŀؼ������ǿ�ݼ��ļ�����ϢӦ�÷��͸��ÿؼ�\n
     *  - �ı������
     *      - ��ʧȥ����Ŀؼ����ͽ���ʧȥ��Ϣ
     *      - ���õ�����Ŀؼ����ͽ���õ���Ϣ
     *
     *  \param pWidget Ҫ�õ����뽹��Ŀؼ�
     */
    void ChangeFocus(FG_Widget * const pWidget);

protected:
    //##ModelId=3F584C9403D0
    /*! \brief �ػ���Ϣ\ref FG_MSG_DRAW�Ĵ�����
     *
     *  ���ո���˳���\ref FG_MSG_DRAW��Ϣ���͸�ÿ���ӿؼ���Ҫ�������ػ��Լ�
     *  \param pAdaptor ָ�����ϵͳ��������ָ��
     */
    void OnDraw(FG_OSAdaptor * pAdaptor);

    //##ModelId=3F5C4AEB0321
    /*! \brief ������Ϣ\ref FG_MSG_KEY�Ĵ�����
     *
     *  - �����\ref FVK_TAB������˳���л�����
     *  - ���򣬷��͸���ݼ�����������
     *  - ������ǿ�ݼ�����ݼ�������δ���������͸���ǰ���㴰��
     *
     *  \param pMsg ָ�������Ϣ�ṹ��ָ��
     *  \return �ü�����Ϣ�Ƿ񱻴���
     *          true    �ü�����Ϣ�ѱ�����
     *          false   �ü�����Ϣδ������
     */
    bool OnKey(FG_Message * pMsg);

    //##ModelId=3F5C4AEB032B
    /*! \brief �����Ϣ\ref FG_MSG_MOUSE�Ĵ�����
     *
     *  �Ѹ���Ϣ���͸����ָ�����ڵĴ���Ԫ�أ�����ʹ�ô���Ԫ�صõ�����
     *  \param pMsg ָ�������Ϣ�ṹ��ָ��
     *  \return �������Ϣ�Ƿ񱻴���
     *          true    �������Ϣ�ѱ�����
     *          false   �������Ϣδ������
     */
    bool OnMouse(FG_Message * pMsg);

    //##ModelId=3F603B980398
    /*! \brief �ؼ����͵�Ҫ���ػ���Ϣ\ref FG_MSG_DRAW_REQUEST�Ĵ�����
     *
     *  - ���������Ϊ���㴰��
     *      - ֱ�ӷ���\ref FG_MSG_DRAW��Ϣ��Ҫ���ػ��ؼ���ʹ���ػ��Լ�
     *  - ����
     *      - ����Ļ������Ҫ���ػ���Ϣ\ref FG_MSG_DRAW_REQUEST
     *
     *  \param pMsg ָ��Ҫ���ػ���Ϣ�ṹ��ָ��
     */
    void OnDrawRequest(FG_Message * pMsg);

    //##ModelId=3F6193A80162
    /*! \brief �����л���Ϣ\ref FG_MSG_FOCUS�Ĵ�����
     *
     *  \param pMsg ָ�򽹵��л���Ϣ�ṹ��ָ��
     */
    void OnFocus(FG_Message * pMsg);

    //##ModelId=409260D5024A
    FG_String   m_Title;                    /*!< \brief ���ڱ��� */
    //##ModelId=3F6193A800B9
    FG_Widget * m_pFocus;                   /*!< \brief ��ǰ�н���Ŀؼ�ָ�� */

private:
    //##ModelId=3F5E6ECC03A6
    FG_KeyMap   m_KeyMap;                   /*!< \brief ����ӳ�������� */

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_WINDOW_H_HEADER_INCLUDED_C0AD431E */

/* @} */

