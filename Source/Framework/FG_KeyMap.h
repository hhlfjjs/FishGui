/*--------------------------------------------------------------------------

	FG_KeyMap.h - ����ӳ������ͷ�ļ�

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
 *  \brief ����ӳ������ͷ�ļ�
 */

#ifndef FG_KEYMAP_H_HEADER_INCLUDED_C0AD453B
#define FG_KEYMAP_H_HEADER_INCLUDED_C0AD453B

#include "../Utility/FG_Utility.h"
#include "FG_Widget.h"

//##ModelId=3FD884F5018C
/*! \brief ����ӳ�����ṹ
 *
 *  ����ԭʼ��\ref Virtual_Key��ʵ�ʵ�\ref Virtual_Key�Լ�Ŀ��ؼ���ӳ���ϵ��\n
 *  ����֮��Ĺ�ϵΪ������û�����ֵΪ��ԭʼ��\ref Virtual_Key���ļ�����Ϣ��
 *  �ü�����Ϣ�ᷢ�͸���Ŀ��ؼ�����ʵ�ʷ��͵ļ�ֵ��ת���ɡ�ʵ�ʵ�\ref Virtual_Key��
 */
struct FG_KeyMapItem
{
    //##ModelId=3FD884F602CE
    /*! \brief ����ӳ�����ṹ�Ĺ��캯��
     *
     *  \param wOrgKey ԭʼ��\ref Virtual_Key
     *  \param wActKey ʵ�ʵ�\ref Virtual_Key
     *  \param pTarget Ŀ��ؼ�
     */
    FG_KeyMapItem(const WORD wOrgKey, const WORD wActKey, FG_Widget * const pTarget) 
        : m_wOriginKey(wOrgKey), m_wActualKey(wActKey), m_pTarget(pTarget)
        {}

    //##ModelId=3FD884F60289
    WORD m_wOriginKey;  		/*!< \brief ԭʼ��\ref Virtual_Key */
    //##ModelId=3FD884F6029D
    WORD m_wActualKey;  		/*!< \brief ʵ�ʵ�\ref Virtual_Key */
    //##ModelId=3FD884F602BB
    FG_Widget * m_pTarget;      /*!< \brief Ŀ��ؼ� */
};

//##ModelId=3F5E6DF703C8
/*! \brief ����ӳ��������
 *
 *  ����͹������е�\ref FG_KeyMapItem
 */
class FG_KeyMap
{
public:
    //##ModelId=40925CC102B6
    /*! \brief ����ӳ������������������
     */
    ~FG_KeyMap();

    //##ModelId=3F5E6DF802E2
	/*! \brief ע���ݼ�
	 *
	 *  \param wOrgKey ԭʼ��\ref Virtual_Key
	 *  \param wActKey ʵ�ʵ�\ref Virtual_Key
	 *  \param pTarget Ŀ��ؼ�
	 *  \return bool ע������Ƿ�ɹ�
     *               true   �ɹ�
     *               false  ʧ��
     */
	bool RegisterKey(WORD wOrgKey, WORD wActKey, FG_Widget * pTarget)
    {
        return m_KeyMapList.Add(new FG_KeyMapItem(wOrgKey, wActKey, pTarget));
    }

    //##ModelId=3F5EDD9E0335
    /*! \brief �����ݼ�
     *
     *  �ڵ������������в��Ҵ˿�ݼ����ҵ������ת����Ȼ���͸�Ŀ��ؼ������򷵻�false
     *  \param pMsg ָ�������Ϣ��ָ��
     *  \return bool �ü�����Ϣ�Ƿ񱻴���
     *               true   �ü�����Ϣ������
     *               false  �ü�����Ϣδ������
     */
    bool SendKey(FG_Message * pMsg);

private:
    //##ModelId=3F5E6DF80011
    typedef FG_SList<FG_KeyMapItem> FG_KEYMAPLIST;      /*!< \brief �������ӳ�����ĵ������������ࣨ\ref FG_SList�� */

    //##ModelId=3F5E6DF802BB
    FG_KEYMAPLIST m_KeyMapList;                         /*!< \brief �������ӳ�����ĵ��������������� */
};

//##ModelId=3FD884F5000F
/*! \brief ����\ref Virtual_Key���Ҽ���ӳ�����ļ����
 *
 *  �����㷨��������\ref Virtual_Key���Ҽ���ӳ�����
 */
class FG_CheckOriginKey : public FG_ListCheck<FG_KeyMapItem>
{
public:
    //##ModelId=3FD884F6010B
    /*! \brief ���캯��
     *
     *  \param wKey Ҫ���ҵ�\ref Virtual_Key
     */
    FG_CheckOriginKey(const WORD wKey) : m_wKey(wKey) {}

    //##ModelId=3FD884F60115
    /*! \brief ������ӳ������Ƿ���������
     *
     *  ͨ���Ƚϼ���ӳ����������������Ƿ���������
     *  \param pObj Ҫ���ļ���ӳ��������ָ��
     *  \return �Ƿ���������\n
     *          true    ��������\n
     *          false   ����������
     */
    virtual bool FindIt(const FG_KeyMapItem * pObj)
    {
        return pObj->m_wOriginKey == m_wKey;
    }

private:
    //##ModelId=3FD884F600EE
    WORD m_wKey;        /*!< \brief Ҫ���ҵ�\ref Virtual_Key */
};

#endif /* FG_KEYMAP_H_HEADER_INCLUDED_C0AD453B */

/*! @} */

