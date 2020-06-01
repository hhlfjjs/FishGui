/*--------------------------------------------------------------------------

	FG_list.h - ����˫������������������ͷ�ļ�

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
/*! \addtogroup Utility
 *  @{ 
 */

/*! \file
 *  \brief ����˫������������������ͷ�ļ�
 *
*/

#ifndef _FG_LIST_H_
#define _FG_LIST_H_

//##ModelId=3FD88507008D
/*! \brief ��������Ľڵ�ṹ
 *
 *  \param ITEM �ڵ��б���Ķ������ͣ��ýڵ���ֻ����ITEM�����ָ�룬���Ҳ�����ö�����ͷ�
 */
template <class ITEM>
struct FG_SList_Node
{
    //##ModelId=3FD8850802FC
    /*! \brief ȱʡ���캯��
     *
     *  \ref FG_SList_Node::m_pItem��\ref FG_SList_Node::m_pNext��������Ϊ\ref NULL
     */
    FG_SList_Node() : m_pItem(NULL), m_pNext(NULL) {}
    
    //##ModelId=40925B4D03DE
    /*! \brief ת�����캯��
     *
     *  \ref FG_SList_Node::m_pNext������Ϊ\ref NULL
     *  \param pItem ��ת���Ķ���ָ��
     */
    FG_SList_Node(ITEM * const pItem) : m_pItem(pItem), m_pNext(NULL) {}
    
    //##ModelId=3FD8850802CA
    ITEM          * m_pItem;            /*!< ָ��ý�㱣��Ķ���\ref FG_SList_Node�಻����ö�����ͷ� */
    //##ModelId=3FD8850802E1
    FG_SList_Node * m_pNext;            /*!< ָ��ֱ�Ӻ�̽���ָ�� */
};

//##ModelId=3FD885060262
/*! \brief ˫������Ľڵ�ṹ
 *
 *  \param ITEM �ڵ��б���Ķ������ͣ��ýڵ���ֻ����ITEM�����ָ�룬���Ҳ�����ö�����ͷ�
 */
template <class ITEM>
struct FG_BList_Node
{
    //##ModelId=3FD8850701E2
    /*! \brief ȱʡ���캯��
     *
     *  \ref FG_BList_Node::m_pItem��\ref FG_BList_Node::m_pPrev��\ref FG_BList_Node::m_pNext��������Ϊ\ref NULL
     */
    FG_BList_Node() : m_pItem(NULL), m_pPrev(NULL), m_pNext(NULL) {}

    //##ModelId=40925B4C02E2
    /*! \brief ת�����캯��
     *
     *  \ref FG_BList_Node::m_pPrev��\ref FG_BList_Node::m_pNext������Ϊ\ref NULL
     *  \param pItem ��ת���Ķ���ָ��
     */
    FG_BList_Node(ITEM * const pItem) : m_pItem(pItem), m_pPrev(NULL), m_pNext(NULL) {}
    
    //##ModelId=3FD88507018A
    ITEM          * m_pItem;            /*!< ָ��ý�㱣��Ķ���\ref FG_SList_Node�಻����ö�����ͷ� */
    //##ModelId=3FD8850701A7
    FG_BList_Node * m_pPrev;            /*!< ָ��ֱ��ǰ������ָ�� */
    //##ModelId=3FD8850701C7
    FG_BList_Node * m_pNext;            /*!< ָ��ֱ�Ӻ�̽���ָ�� */
};

//##ModelId=3FD8850602EF
/*! \brief �����������
 *
 *  \param NODE �ڵ�����
 *  \param ITEM �ڵ��б���Ķ�������
 */
template <class NODE, class ITEM>
class FG_ForwardIterator
{
public:
    //##ModelId=3FD8850702DC
    /*! \brief ������������ȱʡ���캯�� */
    FG_ForwardIterator() : m_pNode(NULL) {}
    
    //##ModelId=3FD8850702E6
    /*! \brief ������������ת�����캯��
     *
     *  �ѽڵ���ָ��ת�������������
     */
    FG_ForwardIterator(NODE * const pNode) : m_pNode(pNode) {}

    //##ModelId=3FD8850702F0
    /*! \brief ����*���������
     *
     *  �����������ת������ָ��Ķ��������
     *  \return ���������ת������ָ��Ķ��������
     */
    ITEM & operator*() const { return * (m_pNode->m_pItem); }

    //##ModelId=3FD8850702FA
    /*! \brief ����->���������
     *
     *  �����������ת������ָ��Ķ����ָ��
     *  \return ���������ת������ָ��Ķ����ָ��
     */
    ITEM * operator->() const { return m_pNode->m_pItem; }

    //##ModelId=3FD885070304
    /*! \brief ����ת�����������
     *
     *  �����������ת������ָ��Ķ����ָ��
     *  \return ���������ת������ָ��Ķ����ָ��
     */
    operator ITEM *() const { return m_pNode->m_pItem; }

    //##ModelId=3FD885070305
    /*! \brief �Ƿ��������
     *
     *  \return true    �Ѿ���������
     *          false   ��δ��������
     */
    bool IsDone() const { return ! m_pNode; }

    //##ModelId=3FD88507030E
    /*! \brief ����ǰ��++���������
     *
     *  ���������ָ����һ������
     *  \return �ı������������
     */
    FG_ForwardIterator & operator++()
    {
        if (m_pNode)
            m_pNode = m_pNode->m_pNext;
        return * this;
    }

    //##ModelId=3FD885070318
    /*! \brief ���غ���++���������
     *
     *  ���������ָ����һ������
     *  \return �ı�ǰ�����������
     */
    const FG_ForwardIterator operator++(int)
    {
        FG_ForwardIterator tmp = * this;
        if (m_pNode) m_pNode = m_pNode->m_pNext;
        return tmp;
    }

    //##ModelId=3FD885070323
    /*! \brief ����==���������
     *
     *  �Ƚ���������������Ƿ�ָ��ͬһ������
     *  \return true    ָ��ͬһ������
     *          false   ָ��ͬ�Ķ���
     */
    bool operator==(const FG_ForwardIterator & i) const { return m_pNode == i.m_pNode; }

    //##ModelId=3FD885070336
    /*! \brief ����!=���������
     *
     *  �Ƚ���������������Ƿ�ָ��ͬ�Ķ���
     *  \return true    ָ��ͬ�Ķ���
     *          false   ָ��ͬһ������
     */
    bool operator!=(const FG_ForwardIterator & i) const { return m_pNode != i.m_pNode; }

    //##ModelId=3FD88507034A
    /*! \brief ����==���������
     *
     *  �Ƚ�����������Ƿ�ָ��ĳ���ض��Ķ���
     *  \return true    ָ��ö���
     *          false   ����ָ��ö���
     */
    bool operator==(ITEM * const p) const { return m_pNode->m_pItem == p; }

    //##ModelId=3FD88507035E
    /*! \brief ����!=���������
     *
     *  �Ƚ�����������Ƿ�ָ��ĳ���ض��Ķ���
     *  \return true    ����ָ��ö���
     *          false   ָ��ö���
     */
    bool operator!=(ITEM * const p) const { return m_pNode->m_pItem != p; }

protected:
    //##ModelId=3FD8850702C9
    NODE * m_pNode;                 /*!< \brief �����������ǰָ��Ľڵ� */
};

//##ModelId=3FD88506029F
/*! \brief �����������
 *
 *  \param ITEM �ڵ��б���Ķ�������
 */
template <class ITEM>
class FG_BackIterator
{
public:
    //##ModelId=3FD8850602D2
    /*! \brief �����������ʹ�õ�˫������ڵ����� */
    typedef FG_BList_Node<ITEM> node;

    //##ModelId=3FD885070228
    /*! \brief ������������ȱʡ���캯�� */
    FG_BackIterator() : m_pNode(NULL) {}

    //##ModelId=3FD885070232
    /*! \brief ������������ת�����캯��
     *
     *  �ѽڵ���ָ��ת���ɷ��������
     */
    FG_BackIterator(node * const pNode) : m_pNode(pNode) {}

    //##ModelId=3FD88507023C
    /*! \brief ����*���������
     *
     *  �ѷ��������ת������ָ��Ķ��������
     *  \return ���������ת������ָ��Ķ��������
     */
    ITEM & operator*() const { return * (m_pNode->m_pItem); }

    //##ModelId=3FD885070246
    /*! \brief ����->���������
     *
     *  �ѷ��������ת������ָ��Ķ����ָ��
     *  \return ���������ת������ָ��Ķ����ָ��
     */
    ITEM * operator->() const { return m_pNode->m_pItem; }

    //##ModelId=3FD885070250
    /*! \brief ����ת�����������
     *
     *  �ѷ��������ת������ָ��Ķ����ָ��
     *  \return ���������ת������ָ��Ķ����ָ��
     */
    operator ITEM *() const { return m_pNode->m_pItem; }

    //##ModelId=3FD885070251
    /*! \brief �Ƿ��������
     *
     *  \return true    �Ѿ���������
     *          false   ��δ��������
     */
    bool IsDone() const { return ! m_pNode; }

    //##ModelId=3FD88507025A
    /*! \brief ����ǰ��++���������
     *
     *  ���������ָ��ǰһ������
     *  \return �ı��ķ��������
     */
    FG_BackIterator & operator++()
    {
        if (m_pNode)
            m_pNode = m_pNode->m_pPrev;
        return * this;
    }

    //##ModelId=3FD885070264
    /*! \brief ���غ���++���������
     *
     *  ���������ָ��ǰһ������
     *  \return �ı�ǰ�ķ��������
     */
    const FG_BackIterator operator++(int)
    {
        FG_BackIterator tmp = * this;
        if (m_pNode) m_pNode = m_pNode->m_pPrev;
        return tmp;
    }

    //##ModelId=3FD88507026F
    /*! \brief ����==���������
     *
     *  �Ƚ���������������Ƿ�ָ��ͬһ������
     *  \return true    ָ��ͬһ������
     *          false   ָ��ͬ�Ķ���
     */
    bool operator==(const FG_BackIterator & i) const { return m_pNode == i.m_pNode; }

    //##ModelId=3FD885070282
    /*! \brief ����!=���������
     *
     *  �Ƚ���������������Ƿ�ָ��ͬ�Ķ���
     *  \return true    ָ��ͬ�Ķ���
     *          false   ָ��ͬһ������
     */
    bool operator!=(const FG_BackIterator & i) const { return m_pNode != i.m_pNode; }

    //##ModelId=3FD885070296
    /*! \brief ����==���������
     *
     *  �ȽϷ���������Ƿ�ָ��ĳ���ض��Ķ���
     *  \return true    ָ��ö���
     *          false   ����ָ��ö���
     */
    bool operator==(ITEM * const p) const { return m_pNode->m_pItem == p; }

    //##ModelId=3FD8850702A1
    /*! \brief ����!=���������
     *
     *  �ȽϷ���������Ƿ�ָ��ĳ���ض��Ķ���
     *  \return true    ����ָ��ö���
     *          false   ָ��ö���
     */
    bool operator!=(ITEM * const p) const { return m_pNode->m_pItem != p; }

private:
    //##ModelId=3FD885070215
    node * m_pNode;                 /*!< \brief �����������ǰָ��Ľڵ� */
};

//##ModelId=3FD885060385
/*! \brief ѭ����������
 *
 *  ѭ������������ʼ����ָ�뿪ʼ������ֱ�������е����һ������
 *  Ȼ���ٴ������еĵ�һ��Ԫ�ؿ�ʼ������ֱ����ʼ���󣨲�������ʼ����
 *  \param ITEM �ڵ��б���Ķ�������
 */
template <class ITEM>
class FG_LoopIterator
{
public:
    //##ModelId=3FD88508011B
    /*! \brief ѭ���������Ĺ��캯��
     *
     *  \param pFirst ָ�������еĵ�һ�������ָ��
     *  \param pStart ָ��ѭ����������ʼ�����ָ��
     */
    FG_LoopIterator(FG_BList_Node<ITEM> * const pFirst, ITEM * const pStart)
        : m_pFirst(pFirst), m_pStart(pStart), m_IsDone(false)
    {
        m_pNode = m_pFirst;
        while (m_pNode && m_pNode->m_pItem != m_pStart) m_pNode = m_pNode->m_pNext;
        if (! m_pNode)
            m_IsDone = true;
        else
        {
            m_pNode = m_pNode->m_pNext;
            if (! m_pNode)
                m_pNode = m_pFirst;
        }
    }

    //##ModelId=3FD88508012F
    /*! \brief ����*���������
     *
     *  ��ѭ��������ת������ָ��Ķ��������
     *  \return ѭ��������ת������ָ��Ķ��������
     */
    ITEM & operator*() const { return * (m_pNode->m_pItem); }
    
    //##ModelId=3FD885080139
    /*! \brief ����->���������
     *
     *  ��ѭ��������ת������ָ��Ķ����ָ��
     *  \return ѭ���������ת������ָ��Ķ����ָ��
     */
    ITEM * operator->() const { return m_pNode->m_pItem; }

    //##ModelId=3FD885080143
    /*! \brief ����ת�����������
     *
     *  ��ѭ��������ת������ָ��Ķ����ָ��
     *  \return ѭ��������ת������ָ��Ķ����ָ��
     */
    operator ITEM *() const { return m_pNode->m_pItem; }

    //##ModelId=3FD88508014D
    /*! \brief �Ƿ������������ѭ�������������е����ж���
     *
     *  \return true    �Ѿ���������
     *          false   ��δ��������
     */
    bool IsDone() const { return m_IsDone; }

    //##ModelId=3FD88508014E
    /*! \brief ����ǰ��++���������
     *
     *  ѭ��������ָ����һ������
     *  \return �ı���ѭ��������
     */
    FG_LoopIterator & operator++()
    {
        if (! m_IsDone)
        {
            m_pNode = m_pNode->m_pNext;
            if (! m_pNode)
                m_pNode = m_pFirst;
            if ((m_pNode->m_pNext && m_pNode->m_pNext->m_pItem == m_pStart) ||
                (! m_pNode->m_pNext && m_pFirst->m_pItem == m_pStart))
                m_IsDone = true;
        }
        return * this;
    }

    //##ModelId=3FD885080157
    /*! \brief ���غ���++���������
     *
     *  ѭ��������ָ����һ������
     *  \return �ı�ǰ��ѭ��������
     */
    const FG_LoopIterator operator++(int)
    {
        FG_LoopIterator tmp = * this;
        if (! m_IsDone)
        {
            m_pNode = m_pNode->m_pNext;
            if (! m_pNode)
                m_pNode = m_pFirst;
            if ((m_pNode->m_pNext && m_pNode->m_pNext->m_pItem == m_pStart) ||
                (! m_pNode->m_pNext && m_pFirst->m_pItem == m_pStart))
                m_IsDone = true;
        }
        return tmp;
    }

    //##ModelId=3FD88508016B
    /*! \brief ����==���������
     *
     *  �Ƚ�����ѭ���������Ƿ�ָ��ͬһ������
     *  \return true    ָ��ͬһ������
     *          false   ָ��ͬ�Ķ���
     */
    bool operator==(const FG_LoopIterator & i) const { return m_pNode == i.m_pNode; }

    //##ModelId=3FD88508017F
    /*! \brief ����!=���������
     *
     *  �Ƚ�����ѭ���������Ƿ�ָ��ͬ�Ķ���
     *  \return true    ָ��ͬ�Ķ���
     *          false   ָ��ͬһ������
     */
    bool operator!=(const FG_LoopIterator & i) const { return m_pNode != i.m_pNode; }

    //##ModelId=3FD885080193
    /*! \brief ����==���������
     *
     *  �Ƚ�ѭ���������Ƿ�ָ��ĳ���ض��Ķ���
     *  \return true    ָ��ö���
     *          false   ����ָ��ö���
     */
    bool operator==(ITEM * const p) const { return m_pNode->m_pItem == p; }

    //##ModelId=3FD8850801A7
    /*! \brief ����!=���������
     *
     *  �Ƚ�ѭ���������Ƿ�ָ��ĳ���ض��Ķ���
     *  \return true    ����ָ��ö���
     *          false   ָ��ö���
     */
    bool operator!=(ITEM * const p) const { return m_pNode->m_pItem != p; }

protected:
    //##ModelId=409265B703D8
    FG_BList_Node<ITEM> * m_pFirst;     /*!< \brief ָ������������еĵ�һ�������ָ�� */
    
    //##ModelId=409265B80069
    FG_BList_Node<ITEM> * m_pNode;      /*!< \brief ѭ����������ǰָ��Ľڵ� */
    
    //##ModelId=3FD885080072
    ITEM                * m_pStart;     /*!< \brief ָ��ʼѭ�������ĵ�һ�������ָ�� */
    
    //##ModelId=3FD885080085
    /*!< \brief �Ƿ��Ѿ����������ı�־
     * 
     * true     ����
     * false    δ����
     */
    bool                  m_IsDone;
};

//##ModelId=3FD885070015
/*! \brief ��������������
 *
 *  \param ITEM ���б���Ķ������ͣ������б���ָ��ITEM�����ָ�룬���Ҳ����������ͷ�
 */
template <class ITEM>
class FG_SList
{
public:
    //##ModelId=3FD885070047
    /*! \brief ���������������еĽڵ����� */
    typedef FG_SList_Node<ITEM>                     node;
    
    //##ModelId=3FD88507005B
    /*! \brief ���������������еĽڵ��б���Ķ�������� */
    typedef ITEM                                    item;
    
    //##ModelId=3FD88507006F
    /*! \brief ����������������ʹ�õ�������������� */
    typedef FG_ForwardIterator<FG_SList_Node<ITEM>, ITEM> iterator;

    //##ModelId=3FD885080265
    /*! \brief ���������������ȱʡ���캯�� */
    FG_SList() : m_First(NULL) {}
    
    //##ModelId=3FD88508026F
    /*! \brief �����������������������
     * 
     *  ɾ�����еĽڵ���󣬵��ǲ�����ɾ���ڵ��б����ITEM����
     */
    virtual ~FG_SList()
    {
        RemoveAll();
    }

    //##ModelId=3FD885080271
    /*! \brief ����ָ���һ����������������
     * 
     *  \return ָ���һ����������������
     */
    iterator First() const { return m_First.m_pNext; }

    //##ModelId=3FD885080279
    /*! \brief ɾ��һ������
     * 
     *  \param i ָ��Ҫɾ���Ķ���ĵ�����
     *  \return ɾ�������Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    bool Remove(const iterator i) { return Remove((item *)i); }
    
    //##ModelId=3FD88508028D
    /*! \brief ���һ������
     * 
     *  \param pItem ָ��Ҫ��ӵĶ���
     *  \return ��Ӳ����Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    bool Add(item * const pItem)
    {
        node * pNode = & m_First;
        while (pNode->m_pNext) pNode = pNode->m_pNext;

        pNode->m_pNext = new node(pItem);
        return true;
    }
    
    //##ModelId=3FD885080298
    /*! \brief ɾ��һ������
     * 
     *  Ҫ��������Ѱ�Ҹö���
     *  \param pItem ָ��Ҫɾ���Ķ���
     *  \return ɾ�������Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    bool Remove(item * const pItem)
    {
        node * pNode = & m_First;
        while (pNode->m_pNext)
        {
            if (pNode->m_pNext->m_pItem == pItem)
            {
                node * pRemove = pNode->m_pNext;
                pNode->m_pNext = pRemove->m_pNext;
                delete pRemove;
                return true;
            }
            pNode = pNode->m_pNext;
        }
        return false;
    }

    //##ModelId=3FD8850802AB
    /*! \brief ɾ�������е����ж���
     * 
     *  \return ɾ�������Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    bool RemoveAll()
    {
        node * pNode = m_First.m_pNext;
        while (pNode)
        {
            node * pRemove = pNode;
            pNode = pRemove->m_pNext;
            delete pRemove;
        }
        m_First.m_pNext = NULL;
        return true;
    }

protected:
    //##ModelId=3FD885080252
    /*! \brief ָ���������еĵ�һ������
     *
     *  \ref FG_SList_Node::m_pNextָ���������еĵ�һ�����󣬲���node *���Լ���Ӻ�ɾ������
     */
    node m_First;
};

//##ModelId=3FD8850601C2
/*! \brief ˫������������
 *
 *  \param ITEM ���б���Ķ������ͣ������б���ָ��ITEM�����ָ�룬���Ҳ����������ͷ�
 */
template <class ITEM>
class FG_BList
{
public:
    //##ModelId=3FD8850601EB
    /*! \brief ˫�������������еĽڵ����� */
    typedef FG_BList_Node<ITEM>                             node;

    //##ModelId=3FD8850601FF
    /*! \brief ˫�������������еĽڵ��б���Ķ�������� */
    typedef ITEM                                            item;

    //##ModelId=3FD885060213
    /*! \brief ˫��������������ʹ�õ�������������� */
    typedef FG_ForwardIterator<FG_BList_Node<ITEM>, ITEM>   forward_iterator;

    //##ModelId=3FD885060227
    /*! \brief ˫��������������ʹ�õķ������������ */
    typedef FG_BackIterator<ITEM>                           back_iterator;

    //##ModelId=3FD88506023A
    /*! \brief ˫��������������ʹ�õ�ѭ������������ */
    typedef FG_LoopIterator<ITEM>                           loop_iterator;

    //##ModelId=3FD885070123
    /*! \brief ˫�������������ȱʡ���캯��
     * 
     *  ��ʼ��ǰ���ͺ��ָ��
     */
    FG_BList() : m_pFirst(NULL), m_pLast(NULL) {}

    //##ModelId=3FD885070124
    /*! \brief ˫���������������������
     * 
     *  ɾ�����еĽڵ���󣬵��ǲ�����ɾ���ڵ��б����ITEM����
     */
    virtual ~FG_BList()
    {
        RemoveAll();
    }

    //##ModelId=3FD88507012D
    /*! \brief ����ѭ��������
     * 
     *  ѭ������������ʼ����ָ�뿪ʼ������ֱ�������е����һ������
     *  Ȼ���ٴ������еĵ�һ��Ԫ�ؿ�ʼ������ֱ����ʼ���󣨰�����ʼ����
     *  \param pItem ָ��ѭ����������ʼ�����ָ��
     *  \return ѭ��������
     */
    loop_iterator Loop(item * const pItem) const
    {
        return loop_iterator(m_pFirst, pItem);
    }

    //##ModelId=3FD885070141
    /*! \brief ����ָ���һ����������������
     * 
     *  \return ָ���һ����������������
     */
    forward_iterator First() const { return m_pFirst; }
    
    //##ModelId=3FD885070142
    /*! \brief ����ָ�����һ������ķ��������
     * 
     *  \return ָ�����һ������ķ��������
     */
    back_iterator Last()     const { return m_pLast; }

    /*! \brief ɾ��һ������
     * 
     *  \param i ָ��Ҫɾ���Ķ���ĵ�����
     *  \return ɾ�������Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    template <class ITERATOR>
    bool Remove(const ITERATOR i) { return Remove((item *)i); }

    //##ModelId=3FD88507014B
    /*! \brief ���һ������
     * 
     *  \param pItem ָ��Ҫ��ӵĶ���
     *  \return ��Ӳ����Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    bool Add(item * const pItem)
    {
        if (! m_pFirst && ! m_pLast)
        {
            // ����Ϊ��
            m_pFirst = m_pLast = new node(pItem);
        }
        else if (m_pFirst && m_pLast)
        {
            // ������Ϊ�գ���������ָ��
            node * pNode = new node(pItem);
            pNode->m_pPrev = m_pLast;
            m_pLast->m_pNext = pNode;
            m_pLast = pNode;
        }
        else
        {
            // �����ܷ��������
            return false;
        }
        return true;
    }

    //##ModelId=3FD885070160
    /*! \brief ɾ��һ������
     * 
     *  Ҫ��������Ѱ�Ҹö���
     *  \param pItem ָ��Ҫɾ���Ķ���
     *  \return ɾ�������Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    bool Remove(item * const pItem)
    {
        node * pNode = m_pLast;

        while (pNode)
        {
            if (pNode->m_pItem == pItem)
            {
                // ��������ָ��
                node * pPrev = pNode->m_pPrev;
                node * pNext = pNode->m_pNext;

                if (pPrev)
                    pPrev->m_pNext = pNext;
                else
                    m_pFirst = pNext;

                if (pNext)
                    pNext->m_pPrev = pPrev;
                else
                    m_pLast = pPrev;

                delete pNode;
                return true;
            }
            else
            {
                pNode = pNode->m_pPrev;
            }
        }
        return false;
    }

    //##ModelId=3FD885070174
    /*! \brief ɾ�������е����ж���
     * 
     *  \return ɾ�������Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    bool RemoveAll()
    {
        node * pNext, * pNode = m_pFirst;

        while (pNode)
        {
            pNext = pNode->m_pNext;
            delete pNode;
            pNode = pNext;
        }
        m_pFirst = m_pLast = NULL;
        return true;
    }


private:
    //##ModelId=3FD8850700F2
    node * m_pFirst;    /*!< \brief ָ��˫�������еĵ�һ���ڵ��ָ�� */
    //##ModelId=3FD885070106
    node * m_pLast;     /*!< \brief ָ��˫�������е����һ���ڵ��ָ�� */
};

/*! \brief ����������Ѱ����Ҫ��Ķ�����㷨
 *
 *  \param i ���������øõ�����������Ѱ
 *  \param pItem Ҫ��Ѱ�Ķ���ָ��
 *  \return �Ƿ��ҵ��ö���\n
 *          true    �ҵ��ö��󣬵�����iָ������Ѱ���Ķ���\n
 *          false   �ö��󲻴���
 */
template <class ITERATOR, class ITEM>
bool FG_ListFind(ITERATOR & i, const ITEM * pItem)
{
    for (; ! i.IsDone(); ++ i)
    {
        if (i == pItem)
            return true;
    }
    return false;
}

//##ModelId=3FD88506033F
/*! \brief ����\ref FG_ListFind_If�㷨�ļ��ӿ���
 *
 *  ���ݶ���ָ����Ѱ����
 *  �����������ʵ��\ref FG_ListCheck::FindIt����������ļ����������������������C�����еĻص�����
 *  \param ITEM ��������Ķ�������
 */
template <class ITEM>
class FG_ListCheck
{
public:
    //##ModelId=3FD885070372
    /*! \brief �������Ƿ���������
     *
     *  ���麯������\ref FG_ListFind_If�㷨���ã�������������ʵ�־���ļ�����
     *  \param pItem Ҫ���Ķ���ָ��
     *  \return �Ƿ���������\n
     *          true    ��������\n
     *          false   ����������
     */
    virtual bool FindIt(const ITEM * pItem) = 0;
};

/*! \brief ����������Ѱ����Ҫ��Ķ�����㷨
 *
 *  ����check�����CheckIt���������������Ƿ���������
 *  \param i ���������øõ�����������Ѱ
 *  \param check ����ļ�������
 *  \return �Ƿ��ҵ��ö���\n
 *          true    �ҵ��ö��󣬵�����iָ������Ѱ���Ķ���\n
 *          false   �ö��󲻴���
 */
template <class ITERATOR, class ITEM>
bool FG_ListFind_If(ITERATOR & i, FG_ListCheck<ITEM> & check)
{
    for (; ! i.IsDone(); ++ i)
    {
        if (check.FindIt(i))
            return true;
    }
    return false;
}

#endif  /* _FG_LIST_H_ */

/*! @} */

