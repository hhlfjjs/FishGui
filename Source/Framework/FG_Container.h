/*--------------------------------------------------------------------------

	FG_Container.h - ����Ԫ���������ͷ�ļ�

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
 *  \brief ����Ԫ���������ͷ�ļ�
 *
*/

#ifndef FG_CONTAINER_H_HEADER_INCLUDED_C0AD6615
#define FG_CONTAINER_H_HEADER_INCLUDED_C0AD6615

#include "../Utility/FG_Utility.h"
#include "FG_Object.h"

//##ModelId=3F52B6A10055
/*! \brief ����Ԫ��������
 *
 *  �����������������������Ĵ���Ԫ�أ���Ļ�ʹ��ڶ��Ǹ���������ࡣ
 *  ͨ��\ref FG_BList���������Ĵ���Ԫ�أ�\ref FG_Object��ָ��
 */
class FG_Container : public FG_Object
{
public:
    //##ModelId=3F56008E01F9
    /*! \brief ������Ĺ��캯��
     *
     *  \param Rect ������ռ�ݵľ�������
     *  \param wID �������Ψһ��ʶ��ȱʡΪ0
     *  \param wStyle �������\ref Style��ȱʡΪ\ref FS_NONE
     */
    FG_Container(const FG_Rect & Rect, const WORD wID = 0, const WORD wStyle = FS_NONE)
        : FG_Object(Rect, wID, wStyle)
        {}

    //##ModelId=3F583820002D
    /*! \brief ������Ĺ��캯����������Ϊȱʡ���캯��ʹ��
     *
     *  \param wID �������Ψһ��ʶ��ȱʡΪ0
     *  \param wStyle �������\ref Style��ȱʡΪ\ref FS_NONE
     *  \return  
     */
    FG_Container(const WORD wID = 0, const WORD wStyle = FS_NONE) 
        : FG_Object(wID, wStyle) {}

    //##ModelId=40925CC101B2
    /*! \brief ���������������
     *
     *  ɾ�����е��Ӵ���Ԫ��
     */
    ~FG_Container() { RemoveAllChild(); }

    //##ModelId=3F6EAC8F0056
    /*! \brief �õ���ʶΪwID���Ӵ���Ԫ�ص�ָ��
     *
     *  \param wID Ҫ���ҵ��Ӵ���Ԫ�ص�Ψһ��ʶ
     *  \return �ҵ����Ӵ���Ԫ�ص�ָ�룬\ref NULL��ʾδ�ҵ�
     */
    FG_Object * GetChild(const WORD wID) const;

protected:
    //##ModelId=3F56008E020D
    /*! \brief ���һ���Ӵ���Ԫ��
     *
     *  �÷���Ϊ�����������ͻ�����ֱ�ӵ��ã���Ļ��ʹ������л���������µķ������ͻ�����ʹ�á�\n
     *  ����Ӵ���Ԫ����Ҫ����ָ�򸸴��ڵ�ָ��
     *  \param pChild Ҫ��ӵ��Ӵ���Ԫ�ص�ָ��
     *  \return bool ��Ӳ����Ƿ�ɹ�\n
     *               true   �ɹ�\n
     *               false  ʧ��
     */
    bool AddChild(FG_Object * const pChild);

    //##ModelId=3F56008E0235
    /*! \brief ɾ��һ���Ӵ���Ԫ��
     *
     *  \param pChild Ҫɾ�����Ӵ���Ԫ�ص�ָ��
     *  \return bool ɾ�������Ƿ�ɹ�\n
     *               true   �ɹ�\n
     *               false  ʧ��
     */
    bool RemoveChild(FG_Object * const pChild);

    //##ModelId=3F56008E025D
    /*! \brief ɾ�����е��Ӵ���Ԫ��
     */
    bool RemoveAllChild();

    //##ModelId=3F5DD96500A3
    typedef FG_BList<FG_Object> FG_OBJECTLIST;          /*!< \brief �����Ӵ���Ԫ�ص�˫�����������ࣨ\ref FG_BList�� */

    //##ModelId=3F5DD965025D
    FG_OBJECTLIST m_ObjectList;                         /*!< \brief �����Ӵ���Ԫ�ص�˫�������������� */

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_CONTAINER_H_HEADER_INCLUDED_C0AD6615 */

/* @} */

