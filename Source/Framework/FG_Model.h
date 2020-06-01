/*--------------------------------------------------------------------------

	FG_Model.h - MVCģʽ�е�ģ�����ͷ�ļ�

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
 *  \brief MVCģʽ�е�ģ�����ͷ�ļ�
 *
*/

#ifndef FG_MODEL_H_HEADER_INCLUDED_C0AD453B
#define FG_MODEL_H_HEADER_INCLUDED_C0AD453B

//##ModelId=3F844CD702B8
/*! \brief MVCģʽ�е�ģ����
 *
 *  ����������������ΪMVCģʽ�е�ģ����
 */
class FG_Model
{
public:
    //##ModelId=3F844CD8029A
    /*! \brief ��ģ����ע����ͼ
     *
     *  \param pView Ҫע�����ͼָ�룬��ͼ������\ref FG_Object��������
     *  \return ע������Ƿ�ɹ�\n
     *          true�� �ɹ�\n
     *          false��ʧ��
     */
    bool RegisterView(FG_Object * const pView)
    {
        if (pView)
            return m_ViewList.Add(pView);
        else
            return false;
    }

    //##ModelId=3F844CD802AE
    /*! \brief ������ע�����ͼ����\ref FG_MSG_UPDATE_VIEW
     *
     */
    void UpdateView(void)
    {
        FG_Message Msg(FG_MSG_UPDATE_VIEW);
        FG_VIEWLIST::iterator i;
        for (i = m_ViewList.First(); ! i.IsDone(); ++ i)
            i->Message(& Msg);
    }

private:
    //##ModelId=3F844CD702E9
    /*! \brief ��������ע�����ͼ��ָ�����������
     *
     */
    typedef FG_SList<FG_Object> FG_VIEWLIST;

    //##ModelId=3F844CD8027D
    FG_VIEWLIST m_ViewList;             /*!< ��������ע�����ͼ��ָ����������� */
};

#endif /* FG_MODEL_H_HEADER_INCLUDED_C0AD453B */

/* @} */

