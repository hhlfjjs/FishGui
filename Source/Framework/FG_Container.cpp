/*--------------------------------------------------------------------------

	FG_Container.cpp - ����Ԫ���������ʵ���ļ�

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
 *  \brief ����Ԫ���������ʵ���ļ�
 *
*/

/*! @} */

#include "FG_Container.h"

BEGIN_MESSAGE_MAP(FG_Container, FG_Object)
END_MESSAGE_MAP()

//##ModelId=3F6EAC8F0056
FG_Object * FG_Container::GetChild(const WORD wID) const
{
    FG_OBJECTLIST::forward_iterator i = m_ObjectList.First();
    FG_CheckObjectID check(wID);

    if (FG_ListFind_If(i, check))
        return i;
    else
        return NULL;
}

//##ModelId=3F56008E020D
bool FG_Container::AddChild(FG_Object * const pChild)
{
    // ����Ӵ���Ԫ����Ҫ����ָ�򸸴��ڵ�ָ��
    pChild->Parent(this);
    m_ObjectList.Add(pChild);
    return true;
}

//##ModelId=3F56008E0235
bool FG_Container::RemoveChild(FG_Object * const pChild)
{
    bool ret = m_ObjectList.Remove(pChild);
    delete pChild;
    return ret;
}

//##ModelId=3F56008E025D
bool FG_Container::RemoveAllChild(void)
{
    FG_OBJECTLIST::forward_iterator i;
    for (i = m_ObjectList.First(); ! i.IsDone(); ++ i)
        delete i;
    m_ObjectList.RemoveAll();
    return true;
}

