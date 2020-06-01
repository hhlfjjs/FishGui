/*--------------------------------------------------------------------------

	MyModel.h - �û�������ģ�����ͷ�ļ�

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
/*! \addtogroup MVC_Application
 *  @{ 
 */

/*! \file
 *  \brief �û�������ģ�����ͷ�ļ�
 *
*/

#ifndef MYMODEL_H_HEADER_INCLUDED_C0AD453B
#define MYMODEL_H_HEADER_INCLUDED_C0AD453B

#include "../../Source/Framework/FG_Framework.h"

/*! \brief �û�������ģ����
 *
 *  ������
 */
class MyModel : public FG_Model
{
public:
    /*! \brief �õ�ģ�����Ψһʵ�������ָ��
     *
     *  \return ָ��ģ�����Ψһʵ�������ָ��
     */
    static MyModel * GetModel(void);

    /*! \brief �õ���һ���е�ĳ������
     *
     *  \param num ���ݵ�������0-9��
     *  \return ���ݣ�0-255��
     */
    unsigned char GetData1(short num) const
    {
        if (num >= 0 && num < 10) 
            return m_Data[0][num];
        else
            return 0;
    }
    
    /*! \brief �õ��ڶ����е�ĳ������
     *
     *  \param num ���ݵ�������0-9��
     *  \return ���ݣ�0-255��
     */
    unsigned char GetData2(short num) const
    {
        if (num >= 0 && num < 10) 
            return m_Data[1][num];
        else
            return 0;
    }

    /*! \brief ��һ�������һ������
     *
     *  \param data Ҫ��ӵ����ݣ�0-255��
     */
    void SendData1(unsigned char data);

    /*! \brief �ڶ��������һ������
     *
     *  \param data Ҫ��ӵ����ݣ�0-255��
     */
    void SendData2(unsigned char data);

    void AdjustData(void);

protected:
    /*! \brief ģ����Ĺ��캯�� */
    MyModel();

private:
    unsigned char m_Data[2][10];    /*!< \brief �������ݵĻ������������10�� */

    static MyModel * m_pModel;      /*!< \brief ָ��ģ�����Ψһʵ�������ָ�� */
};

/*! \brief �õ�ģ�����Ψһʵ�������ָ��
 *
 *  \return ָ��ģ�����Ψһʵ�������ָ��
 */
MyModel * GetMyModel(void);

#endif /* MYMODEL_H_HEADER_INCLUDED_C0AD453B */

/*! @} */

