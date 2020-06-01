/*--------------------------------------------------------------------------

	FG_Widget.h - �ؼ��������ͷ�ļ�

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
 *  \brief �ؼ��������ͷ�ļ�
 *
*/

#ifndef FG_WIDGET_H_HEADER_INCLUDED_C0A7936B
#define FG_WIDGET_H_HEADER_INCLUDED_C0A7936B

#include "FG_Object.h"

//##ModelId=3F37D6A30299
/*! \brief �ؼ�������
 *
 *  �������������Է����ڴ�������Ϊ�ؼ����ؼ����в�����������������Ԫ��
 */
class FG_Widget : public FG_Object
{
public:
    //##ModelId=3F5B47050100
    /*! \brief ���캯��
     *
     *  \param Rect �ÿؼ�ռ�ݵľ�������
     *  \param wID �ÿؼ���Ψһ��ʶ��ȱʡΪ0
     *  \param wStyle �ÿؼ��ı߿���ȱʡΪ\ref FS_NONE
     */
    FG_Widget(const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE)
        : m_bCanGetFocus(true), FG_Object(Rect, wID, wStyle)
    {}

    //##ModelId=3F6193A80071
    /*! \brief ���ؿؼ��ܷ�õ�����ı�־
     *
     *  \return �ؼ��ܷ�õ�����ı�־\n
     *          true    �ÿؼ��ܵõ�����\n
     *          false   �ÿؼ����ܵõ�����
     */
    virtual bool CanGetFocus(void) const { return m_bCanGetFocus; }

    //##ModelId=3F6193A8007C
    /*! \brief ���ÿؼ��ܷ�õ�����ı�־
     *
     *  \param flag �ؼ��ܷ�õ�����ı�־
     */
    void SetCanGetFocus(const bool flag) { m_bCanGetFocus = flag; }

protected:
    //##ModelId=3F6193A703AF
    /*! \brief �ÿؼ��Ƿ��ܵõ�����ı�־��
     *  
     *  ���˿�ݼ��Ŀؼ����ܵõ�����
     */
    bool m_bCanGetFocus;

    DECLARE_MESSAGE_MAP()
};

//##ModelId=3FD884F403BC
/*! \brief �ж�һ���ؼ��ܷ�õ�����ļ����
 *
 *  ���ڵ��������Ҵ������ܵõ�����ĵĿؼ�
 */
class FG_CheckCanGetFocus : public FG_ListCheck<FG_Object>
{
public:
    //##ModelId=3FD884F60089
    /*! \brief �������Ƿ���������
     *
     *  ͨ���ȽϿؼ��Ƿ��ܵõ��������жϿؼ��Ƿ���������
     *  \param pObj Ҫ���Ŀؼ�
     *  \return �Ƿ���������\n
     *          true    ��������\n
     *          false   ����������
     */
    virtual bool FindIt(const FG_Object * pObj)
    {
        return ((FG_Widget *)pObj)->CanGetFocus();
    }
};

#endif /* FG_WIDGET_H_HEADER_INCLUDED_C0A7936B */

/*! @} */

