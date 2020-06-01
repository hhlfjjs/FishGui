/*--------------------------------------------------------------------------

	FG_Point.h - ���ص�ṹ��ͷ�ļ�

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
 *  \brief ���ص�ṹ��ͷ�ļ�
 *
 *  ������Ļ��ʹ�õ����ص�Ľṹ��ÿһ�����ص��ɺ�����������깹��
*/

#ifndef FG_POINT_H_HEADER_INCLUDED_C0B109A9
#define FG_POINT_H_HEADER_INCLUDED_C0B109A9

//##ModelId=3F4EC1290046
/*! \brief ���ص�ṹ
 *
 *  ������Ļ��ʹ�õ����ص�Ľṹ
 */
struct FG_Point
{
    //##ModelId=3F4EC47701FB
    short x;                        /*!< \brief ���ص�ĺ����� */
    //##ModelId=3F4EC477034F
    short y;                        /*!< \brief ���ص�������� */

    //##ModelId=3F4EC477036D
    /*! \brief �Ƚ��������Ƿ�ͬ
     *
     *  !=��������Ƚϱ����ص������һ�����ص��Ƿ�ͬ�����������������������һ����ͬ��
     *  \param InPoint ���Ƚϵ����ص�
     *  \return true: �����㲻ͬ    false: ��������ͬ
     */
    bool operator != (const FG_Point & InPoint) const
    {
        if (x != InPoint.x || y != InPoint.y)
        {
            return true;
        }
        return false;
    }

    //##ModelId=3F4EDAC100D3
    /*! \brief �Ƚ��������Ƿ���ͬ
     *
     *  ==��������Ƚϱ����ص������һ�����ص��Ƿ���ͬ����������������궼��ͬ��
     *  \param InPoint ���Ƚϵ����ص�
     *  \return true: ��������ͬ    false: �����㲻ͬ
     */
    bool operator == (const FG_Point & InPoint) const
    {
        if (x == InPoint.x && y == InPoint.y)
        {
            return true;
        }
        return false;
    }

    //##ModelId=3F4EDAC10123
    /*! \brief ���������
     *
     *  +������������ص������һ�����ص���ӣ����������������ֱ���ӣ�
     *  \param Point ����ӵ����ص�
     *  \return ������ӽ��
     */
    const FG_Point operator + (const FG_Point & Point) const
    {
        FG_Point NewPt;

        NewPt.x = x + Point.x;
        NewPt.y = y + Point.y;
        return NewPt;
    }
};

#endif /* FG_POINT_H_HEADER_INCLUDED_C0B109A9 */

/* @} */

