/*--------------------------------------------------------------------------

	FG_list.h - 单、双向链表容器及迭代器头文件

	本程序是FishGUI软件的一部分

	版权所有 (C) 2003,2004 王咏武
	http://www.contextfree.net/wangyw/

----------------------------------------------------------------------------

	作者对 FishGUI 软件及其所有源代码授权如下：

	允许任何个人、组织、机构、企业无偿获得、修改、使用、重新发布 FishGUI 软
	件及其源代码，或按照有偿或者无偿的方式发行基于 FishGUI 源代码的全部或部
	分内容开发的软件产品，——但行使以上权利时，须遵守以下约定：

	1、重新发布 FishGUI 软件及其源代码时，不得隐去软件及其源代码中原有的版
	   权信息和开发者标识。

	2、发行基于 FishGUI 源代码的全部或部分内容开发的软件产品时，必须在产品
	   的显著位置标明以下字样：

	   【本产品的一部分功能是基于王咏武在 FishGUI 软件中的工作完成的】

	3、在正式出版物中引用 FishGUI 的文档、源代码或注释内容的，应注明软件的
	   原作者为王咏武。

--------------------------------------------------------------------------*/
/*! \addtogroup Utility
 *  @{ 
 */

/*! \file
 *  \brief 单、双向链表容器及迭代器头文件
 *
*/

#ifndef _FG_LIST_H_
#define _FG_LIST_H_

//##ModelId=3FD88507008D
/*! \brief 单向链表的节点结构
 *
 *  \param ITEM 节点中保存的对象类型，该节点中只保存ITEM对象的指针，并且不负责该对象的释放
 */
template <class ITEM>
struct FG_SList_Node
{
    //##ModelId=3FD8850802FC
    /*! \brief 缺省构造函数
     *
     *  \ref FG_SList_Node::m_pItem和\ref FG_SList_Node::m_pNext都被设置为\ref NULL
     */
    FG_SList_Node() : m_pItem(NULL), m_pNext(NULL) {}
    
    //##ModelId=40925B4D03DE
    /*! \brief 转换构造函数
     *
     *  \ref FG_SList_Node::m_pNext被设置为\ref NULL
     *  \param pItem 需转换的对象指针
     */
    FG_SList_Node(ITEM * const pItem) : m_pItem(pItem), m_pNext(NULL) {}
    
    //##ModelId=3FD8850802CA
    ITEM          * m_pItem;            /*!< 指向该结点保存的对象，\ref FG_SList_Node类不负责该对象的释放 */
    //##ModelId=3FD8850802E1
    FG_SList_Node * m_pNext;            /*!< 指向直接后继结点的指针 */
};

//##ModelId=3FD885060262
/*! \brief 双向链表的节点结构
 *
 *  \param ITEM 节点中保存的对象类型，该节点中只保存ITEM对象的指针，并且不负责该对象的释放
 */
template <class ITEM>
struct FG_BList_Node
{
    //##ModelId=3FD8850701E2
    /*! \brief 缺省构造函数
     *
     *  \ref FG_BList_Node::m_pItem、\ref FG_BList_Node::m_pPrev和\ref FG_BList_Node::m_pNext都被设置为\ref NULL
     */
    FG_BList_Node() : m_pItem(NULL), m_pPrev(NULL), m_pNext(NULL) {}

    //##ModelId=40925B4C02E2
    /*! \brief 转换构造函数
     *
     *  \ref FG_BList_Node::m_pPrev和\ref FG_BList_Node::m_pNext被设置为\ref NULL
     *  \param pItem 需转换的对象指针
     */
    FG_BList_Node(ITEM * const pItem) : m_pItem(pItem), m_pPrev(NULL), m_pNext(NULL) {}
    
    //##ModelId=3FD88507018A
    ITEM          * m_pItem;            /*!< 指向该结点保存的对象，\ref FG_SList_Node类不负责该对象的释放 */
    //##ModelId=3FD8850701A7
    FG_BList_Node * m_pPrev;            /*!< 指向直接前趋结点的指针 */
    //##ModelId=3FD8850701C7
    FG_BList_Node * m_pNext;            /*!< 指向直接后继结点的指针 */
};

//##ModelId=3FD8850602EF
/*! \brief 正向迭代器类
 *
 *  \param NODE 节点类型
 *  \param ITEM 节点中保存的对象类型
 */
template <class NODE, class ITEM>
class FG_ForwardIterator
{
public:
    //##ModelId=3FD8850702DC
    /*! \brief 正向迭代器类的缺省构造函数 */
    FG_ForwardIterator() : m_pNode(NULL) {}
    
    //##ModelId=3FD8850702E6
    /*! \brief 正向迭代器类的转换构造函数
     *
     *  把节点类指针转换成正向迭代器
     */
    FG_ForwardIterator(NODE * const pNode) : m_pNode(pNode) {}

    //##ModelId=3FD8850702F0
    /*! \brief 重载*运算符函数
     *
     *  把正向迭代器转换成其指向的对象的引用
     *  \return 正向迭代器转换成其指向的对象的引用
     */
    ITEM & operator*() const { return * (m_pNode->m_pItem); }

    //##ModelId=3FD8850702FA
    /*! \brief 重载->运算符函数
     *
     *  把正向迭代器转换成其指向的对象的指针
     *  \return 正向迭代器转换成其指向的对象的指针
     */
    ITEM * operator->() const { return m_pNode->m_pItem; }

    //##ModelId=3FD885070304
    /*! \brief 重载转换运算符函数
     *
     *  把正向迭代器转换成其指向的对象的指针
     *  \return 正向迭代器转换成其指向的对象的指针
     */
    operator ITEM *() const { return m_pNode->m_pItem; }

    //##ModelId=3FD885070305
    /*! \brief 是否遍历结束
     *
     *  \return true    已经遍历结束
     *          false   还未遍历结束
     */
    bool IsDone() const { return ! m_pNode; }

    //##ModelId=3FD88507030E
    /*! \brief 重载前置++运算符函数
     *
     *  正向迭代器指向下一个对象
     *  \return 改变后的正向迭代器
     */
    FG_ForwardIterator & operator++()
    {
        if (m_pNode)
            m_pNode = m_pNode->m_pNext;
        return * this;
    }

    //##ModelId=3FD885070318
    /*! \brief 重载后置++运算符函数
     *
     *  正向迭代器指向下一个对象
     *  \return 改变前的正向迭代器
     */
    const FG_ForwardIterator operator++(int)
    {
        FG_ForwardIterator tmp = * this;
        if (m_pNode) m_pNode = m_pNode->m_pNext;
        return tmp;
    }

    //##ModelId=3FD885070323
    /*! \brief 重载==运算符函数
     *
     *  比较两个正向迭代器是否指向同一个对象
     *  \return true    指向同一个对象
     *          false   指向不同的对象
     */
    bool operator==(const FG_ForwardIterator & i) const { return m_pNode == i.m_pNode; }

    //##ModelId=3FD885070336
    /*! \brief 重载!=运算符函数
     *
     *  比较两个正向迭代器是否指向不同的对象
     *  \return true    指向不同的对象
     *          false   指向同一个对象
     */
    bool operator!=(const FG_ForwardIterator & i) const { return m_pNode != i.m_pNode; }

    //##ModelId=3FD88507034A
    /*! \brief 重载==运算符函数
     *
     *  比较正向迭代器是否指向某个特定的对象
     *  \return true    指向该对象
     *          false   不是指向该对象
     */
    bool operator==(ITEM * const p) const { return m_pNode->m_pItem == p; }

    //##ModelId=3FD88507035E
    /*! \brief 重载!=运算符函数
     *
     *  比较正向迭代器是否不指向某个特定的对象
     *  \return true    不是指向该对象
     *          false   指向该对象
     */
    bool operator!=(ITEM * const p) const { return m_pNode->m_pItem != p; }

protected:
    //##ModelId=3FD8850702C9
    NODE * m_pNode;                 /*!< \brief 正向迭代器当前指向的节点 */
};

//##ModelId=3FD88506029F
/*! \brief 反向迭代器类
 *
 *  \param ITEM 节点中保存的对象类型
 */
template <class ITEM>
class FG_BackIterator
{
public:
    //##ModelId=3FD8850602D2
    /*! \brief 反向迭代器能使用的双向链表节点类型 */
    typedef FG_BList_Node<ITEM> node;

    //##ModelId=3FD885070228
    /*! \brief 反向迭代器类的缺省构造函数 */
    FG_BackIterator() : m_pNode(NULL) {}

    //##ModelId=3FD885070232
    /*! \brief 反向迭代器类的转换构造函数
     *
     *  把节点类指针转换成反向迭代器
     */
    FG_BackIterator(node * const pNode) : m_pNode(pNode) {}

    //##ModelId=3FD88507023C
    /*! \brief 重载*运算符函数
     *
     *  把反向迭代器转换成其指向的对象的引用
     *  \return 反向迭代器转换成其指向的对象的引用
     */
    ITEM & operator*() const { return * (m_pNode->m_pItem); }

    //##ModelId=3FD885070246
    /*! \brief 重载->运算符函数
     *
     *  把反向迭代器转换成其指向的对象的指针
     *  \return 反向迭代器转换成其指向的对象的指针
     */
    ITEM * operator->() const { return m_pNode->m_pItem; }

    //##ModelId=3FD885070250
    /*! \brief 重载转换运算符函数
     *
     *  把反向迭代器转换成其指向的对象的指针
     *  \return 反向迭代器转换成其指向的对象的指针
     */
    operator ITEM *() const { return m_pNode->m_pItem; }

    //##ModelId=3FD885070251
    /*! \brief 是否遍历结束
     *
     *  \return true    已经遍历结束
     *          false   还未遍历结束
     */
    bool IsDone() const { return ! m_pNode; }

    //##ModelId=3FD88507025A
    /*! \brief 重载前置++运算符函数
     *
     *  反向迭代器指向前一个对象
     *  \return 改变后的反向迭代器
     */
    FG_BackIterator & operator++()
    {
        if (m_pNode)
            m_pNode = m_pNode->m_pPrev;
        return * this;
    }

    //##ModelId=3FD885070264
    /*! \brief 重载后置++运算符函数
     *
     *  反向迭代器指向前一个对象
     *  \return 改变前的反向迭代器
     */
    const FG_BackIterator operator++(int)
    {
        FG_BackIterator tmp = * this;
        if (m_pNode) m_pNode = m_pNode->m_pPrev;
        return tmp;
    }

    //##ModelId=3FD88507026F
    /*! \brief 重载==运算符函数
     *
     *  比较两个反向迭代器是否指向同一个对象
     *  \return true    指向同一个对象
     *          false   指向不同的对象
     */
    bool operator==(const FG_BackIterator & i) const { return m_pNode == i.m_pNode; }

    //##ModelId=3FD885070282
    /*! \brief 重载!=运算符函数
     *
     *  比较两个反向迭代器是否指向不同的对象
     *  \return true    指向不同的对象
     *          false   指向同一个对象
     */
    bool operator!=(const FG_BackIterator & i) const { return m_pNode != i.m_pNode; }

    //##ModelId=3FD885070296
    /*! \brief 重载==运算符函数
     *
     *  比较反向迭代器是否指向某个特定的对象
     *  \return true    指向该对象
     *          false   不是指向该对象
     */
    bool operator==(ITEM * const p) const { return m_pNode->m_pItem == p; }

    //##ModelId=3FD8850702A1
    /*! \brief 重载!=运算符函数
     *
     *  比较反向迭代器是否不指向某个特定的对象
     *  \return true    不是指向该对象
     *          false   指向该对象
     */
    bool operator!=(ITEM * const p) const { return m_pNode->m_pItem != p; }

private:
    //##ModelId=3FD885070215
    node * m_pNode;                 /*!< \brief 反向迭代器当前指向的节点 */
};

//##ModelId=3FD885060385
/*! \brief 循环迭代器类
 *
 *  循环迭代器从起始对象指针开始遍历，直到容器中的最后一个对象，
 *  然后再从容器中的第一个元素开始遍历，直到起始对象（不包括起始对象）
 *  \param ITEM 节点中保存的对象类型
 */
template <class ITEM>
class FG_LoopIterator
{
public:
    //##ModelId=3FD88508011B
    /*! \brief 循环迭代器的构造函数
     *
     *  \param pFirst 指向容器中的第一个对象的指针
     *  \param pStart 指向循环遍历的起始对象的指针
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
    /*! \brief 重载*运算符函数
     *
     *  把循环迭代器转换成其指向的对象的引用
     *  \return 循环迭代器转换成其指向的对象的引用
     */
    ITEM & operator*() const { return * (m_pNode->m_pItem); }
    
    //##ModelId=3FD885080139
    /*! \brief 重载->运算符函数
     *
     *  把循环迭代器转换成其指向的对象的指针
     *  \return 循环向迭代器转换成其指向的对象的指针
     */
    ITEM * operator->() const { return m_pNode->m_pItem; }

    //##ModelId=3FD885080143
    /*! \brief 重载转换运算符函数
     *
     *  把循环迭代器转换成其指向的对象的指针
     *  \return 循环迭代器转换成其指向的对象的指针
     */
    operator ITEM *() const { return m_pNode->m_pItem; }

    //##ModelId=3FD88508014D
    /*! \brief 是否遍历结束，即循环遍历完容器中的所有对象
     *
     *  \return true    已经遍历结束
     *          false   还未遍历结束
     */
    bool IsDone() const { return m_IsDone; }

    //##ModelId=3FD88508014E
    /*! \brief 重载前置++运算符函数
     *
     *  循环迭代器指向下一个对象
     *  \return 改变后的循环迭代器
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
    /*! \brief 重载后置++运算符函数
     *
     *  循环迭代器指向下一个对象
     *  \return 改变前的循环迭代器
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
    /*! \brief 重载==运算符函数
     *
     *  比较两个循环迭代器是否指向同一个对象
     *  \return true    指向同一个对象
     *          false   指向不同的对象
     */
    bool operator==(const FG_LoopIterator & i) const { return m_pNode == i.m_pNode; }

    //##ModelId=3FD88508017F
    /*! \brief 重载!=运算符函数
     *
     *  比较两个循环迭代器是否指向不同的对象
     *  \return true    指向不同的对象
     *          false   指向同一个对象
     */
    bool operator!=(const FG_LoopIterator & i) const { return m_pNode != i.m_pNode; }

    //##ModelId=3FD885080193
    /*! \brief 重载==运算符函数
     *
     *  比较循环迭代器是否指向某个特定的对象
     *  \return true    指向该对象
     *          false   不是指向该对象
     */
    bool operator==(ITEM * const p) const { return m_pNode->m_pItem == p; }

    //##ModelId=3FD8850801A7
    /*! \brief 重载!=运算符函数
     *
     *  比较循环迭代器是否不指向某个特定的对象
     *  \return true    不是指向该对象
     *          false   指向该对象
     */
    bool operator!=(ITEM * const p) const { return m_pNode->m_pItem != p; }

protected:
    //##ModelId=409265B703D8
    FG_BList_Node<ITEM> * m_pFirst;     /*!< \brief 指向遍历的容器中的第一个对象的指针 */
    
    //##ModelId=409265B80069
    FG_BList_Node<ITEM> * m_pNode;      /*!< \brief 循环迭代器当前指向的节点 */
    
    //##ModelId=3FD885080072
    ITEM                * m_pStart;     /*!< \brief 指向开始循环遍历的第一个对象的指针 */
    
    //##ModelId=3FD885080085
    /*!< \brief 是否已经遍历结束的标志
     * 
     * true     结束
     * false    未结束
     */
    bool                  m_IsDone;
};

//##ModelId=3FD885070015
/*! \brief 单向链表容器类
 *
 *  \param ITEM 其中保存的对象类型，容器中保存指向ITEM对象的指针，并且不负责对象的释放
 */
template <class ITEM>
class FG_SList
{
public:
    //##ModelId=3FD885070047
    /*! \brief 单向链表容器类中的节点类型 */
    typedef FG_SList_Node<ITEM>                     node;
    
    //##ModelId=3FD88507005B
    /*! \brief 单向链表容器类中的节点中保存的对象的类型 */
    typedef ITEM                                    item;
    
    //##ModelId=3FD88507006F
    /*! \brief 单向链表容器类中使用的正向迭代器类型 */
    typedef FG_ForwardIterator<FG_SList_Node<ITEM>, ITEM> iterator;

    //##ModelId=3FD885080265
    /*! \brief 单向链表容器类的缺省构造函数 */
    FG_SList() : m_First(NULL) {}
    
    //##ModelId=3FD88508026F
    /*! \brief 单向链表容器类的析构函数
     * 
     *  删除所有的节点对象，但是不负责删除节点中保存的ITEM对象
     */
    virtual ~FG_SList()
    {
        RemoveAll();
    }

    //##ModelId=3FD885080271
    /*! \brief 返回指向第一个对象的正向迭代器
     * 
     *  \return 指向第一个对象的正向迭代器
     */
    iterator First() const { return m_First.m_pNext; }

    //##ModelId=3FD885080279
    /*! \brief 删除一个对象
     * 
     *  \param i 指向要删除的对象的迭代器
     *  \return 删除操作是否成功\n
     *          true    成功\n
     *          false   失败
     */
    bool Remove(const iterator i) { return Remove((item *)i); }
    
    //##ModelId=3FD88508028D
    /*! \brief 添加一个对象
     * 
     *  \param pItem 指向要添加的对象
     *  \return 添加操作是否成功\n
     *          true    成功\n
     *          false   失败
     */
    bool Add(item * const pItem)
    {
        node * pNode = & m_First;
        while (pNode->m_pNext) pNode = pNode->m_pNext;

        pNode->m_pNext = new node(pItem);
        return true;
    }
    
    //##ModelId=3FD885080298
    /*! \brief 删除一个对象
     * 
     *  要在容器中寻找该对象
     *  \param pItem 指向要删除的对象
     *  \return 删除操作是否成功\n
     *          true    成功\n
     *          false   失败
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
    /*! \brief 删除容器中的所有对象
     * 
     *  \return 删除操作是否成功\n
     *          true    成功\n
     *          false   失败
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
    /*! \brief 指向单向链表中的第一个对象
     *
     *  \ref FG_SList_Node::m_pNext指向单向链表中的第一个对象，不用node *可以简化添加和删除操作
     */
    node m_First;
};

//##ModelId=3FD8850601C2
/*! \brief 双向链表容器类
 *
 *  \param ITEM 其中保存的对象类型，容器中保存指向ITEM对象的指针，并且不负责对象的释放
 */
template <class ITEM>
class FG_BList
{
public:
    //##ModelId=3FD8850601EB
    /*! \brief 双向链表容器类中的节点类型 */
    typedef FG_BList_Node<ITEM>                             node;

    //##ModelId=3FD8850601FF
    /*! \brief 双向链表容器类中的节点中保存的对象的类型 */
    typedef ITEM                                            item;

    //##ModelId=3FD885060213
    /*! \brief 双向链表容器类中使用的正向迭代器类型 */
    typedef FG_ForwardIterator<FG_BList_Node<ITEM>, ITEM>   forward_iterator;

    //##ModelId=3FD885060227
    /*! \brief 双向链表容器类中使用的反向迭代器类型 */
    typedef FG_BackIterator<ITEM>                           back_iterator;

    //##ModelId=3FD88506023A
    /*! \brief 双向链表容器类中使用的循环迭代器类型 */
    typedef FG_LoopIterator<ITEM>                           loop_iterator;

    //##ModelId=3FD885070123
    /*! \brief 双向链表容器类的缺省构造函数
     * 
     *  初始化前驱和后继指针
     */
    FG_BList() : m_pFirst(NULL), m_pLast(NULL) {}

    //##ModelId=3FD885070124
    /*! \brief 双向链表容器类的析构函数
     * 
     *  删除所有的节点对象，但是不负责删除节点中保存的ITEM对象
     */
    virtual ~FG_BList()
    {
        RemoveAll();
    }

    //##ModelId=3FD88507012D
    /*! \brief 返回循环迭代器
     * 
     *  循环迭代器从起始对象指针开始遍历，直到容器中的最后一个对象，
     *  然后再从容器中的第一个元素开始遍历，直到起始对象（包括起始对象）
     *  \param pItem 指向循环遍历的起始对象的指针
     *  \return 循环迭代器
     */
    loop_iterator Loop(item * const pItem) const
    {
        return loop_iterator(m_pFirst, pItem);
    }

    //##ModelId=3FD885070141
    /*! \brief 返回指向第一个对象的正向迭代器
     * 
     *  \return 指向第一个对象的正向迭代器
     */
    forward_iterator First() const { return m_pFirst; }
    
    //##ModelId=3FD885070142
    /*! \brief 返回指向最后一个对象的反向迭代器
     * 
     *  \return 指向最后一个对象的反向迭代器
     */
    back_iterator Last()     const { return m_pLast; }

    /*! \brief 删除一个对象
     * 
     *  \param i 指向要删除的对象的迭代器
     *  \return 删除操作是否成功\n
     *          true    成功\n
     *          false   失败
     */
    template <class ITERATOR>
    bool Remove(const ITERATOR i) { return Remove((item *)i); }

    //##ModelId=3FD88507014B
    /*! \brief 添加一个对象
     * 
     *  \param pItem 指向要添加的对象
     *  \return 添加操作是否成功\n
     *          true    成功\n
     *          false   失败
     */
    bool Add(item * const pItem)
    {
        if (! m_pFirst && ! m_pLast)
        {
            // 容器为空
            m_pFirst = m_pLast = new node(pItem);
        }
        else if (m_pFirst && m_pLast)
        {
            // 容器不为空，调整链表指针
            node * pNode = new node(pItem);
            pNode->m_pPrev = m_pLast;
            m_pLast->m_pNext = pNode;
            m_pLast = pNode;
        }
        else
        {
            // 不可能发生的情况
            return false;
        }
        return true;
    }

    //##ModelId=3FD885070160
    /*! \brief 删除一个对象
     * 
     *  要在容器中寻找该对象
     *  \param pItem 指向要删除的对象
     *  \return 删除操作是否成功\n
     *          true    成功\n
     *          false   失败
     */
    bool Remove(item * const pItem)
    {
        node * pNode = m_pLast;

        while (pNode)
        {
            if (pNode->m_pItem == pItem)
            {
                // 调整链表指针
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
    /*! \brief 删除容器中的所有对象
     * 
     *  \return 删除操作是否成功\n
     *          true    成功\n
     *          false   失败
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
    node * m_pFirst;    /*!< \brief 指向双向链表中的第一个节点的指针 */
    //##ModelId=3FD885070106
    node * m_pLast;     /*!< \brief 指向双向链表中的最后一个节点的指针 */
};

/*! \brief 在容器中搜寻符合要求的对象的算法
 *
 *  \param i 迭代器，用该迭代器进行搜寻
 *  \param pItem 要搜寻的对象指针
 *  \return 是否找到该对象\n
 *          true    找到该对象，迭代器i指向了搜寻到的对象\n
 *          false   该对象不存在
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
/*! \brief 用于\ref FG_ListFind_If算法的检查接口类
 *
 *  根据对象指针搜寻对象
 *  该类的派生类实现\ref FG_ListCheck::FindIt函数，具体的检查操作由派生类决定，类似C语言中的回调函数
 *  \param ITEM 容器保存的对象类型
 */
template <class ITEM>
class FG_ListCheck
{
public:
    //##ModelId=3FD885070372
    /*! \brief 检查对象是否满足条件
     *
     *  纯虚函数，由\ref FG_ListFind_If算法调用，必须由派生类实现具体的检查操作
     *  \param pItem 要检查的对象指针
     *  \return 是否满足条件\n
     *          true    满足条件\n
     *          false   不满足条件
     */
    virtual bool FindIt(const ITEM * pItem) = 0;
};

/*! \brief 在容器中搜寻符合要求的对象的算法
 *
 *  调用check对象的CheckIt函数来决定对象是否满足条件
 *  \param i 迭代器，用该迭代器进行搜寻
 *  \param check 具体的检查类对象
 *  \return 是否找到该对象\n
 *          true    找到该对象，迭代器i指向了搜寻到的对象\n
 *          false   该对象不存在
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

