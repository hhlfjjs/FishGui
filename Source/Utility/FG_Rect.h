/*--------------------------------------------------------------------------

	FG_Rect.h - ���νṹ��ͷ�ļ�

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
 *  \brief ���νṹ��ͷ�ļ�
 *
 *  ������Ļ��ʹ�õľ��νṹ��ÿһ�����νṹ�����ϽǺ����½�����������ʾ
*/

#ifndef FG_RECT_H_HEADER_INCLUDED_C0B10BA4
#define FG_RECT_H_HEADER_INCLUDED_C0B10BA4

#include "FG_Point.h"

//##ModelId=3F4EC135021A
/*! \brief ���νṹ
 *
 *  ������Ļ��ʹ�õľ��νṹ
 */
struct FG_Rect
{
    //##ModelId=3F4EC4780094
    short wLeft;                   /*!< \brief �������Ͻǵĺ����� */
    //##ModelId=3F4EC47800B2
    short wTop;                    /*!< \brief �������Ͻǵ������� */
    //##ModelId=3F4EC47800D0
    short wRight;                  /*!< \brief �������½ǵĺ����� */
    //##ModelId=3F4EC47800EE
    short wBottom;                 /*!< \brief �������½ǵ������� */
    
    //##ModelId=40925B4D01C1
    /*! \brief ���νṹ��ȱʡ���캯��
     */
    FG_Rect() : wLeft(0), wTop(0), wRight(0), wBottom(0) {}
    //##ModelId=40925B4D01DF
    /*! \brief ���νṹ�Ĺ��캯��
     *  \param x1 �������Ͻǵĺ�����
     *  \param y1 �������Ͻǵ�������
     *  \param x2 �������½ǵĺ�����
     *  \param y2 �������½ǵ�������
     */
    FG_Rect(const short x1, const short y1, const short x2, const short y2) 
        : wLeft(x1), wTop(y1), wRight(x2), wBottom(y2) {}

    //##ModelId=3F4EC4780210
    /*! \brief �����µľ�������
     *  \param x1 �¾������Ͻǵĺ�����
     *  \param y1 �¾������Ͻǵ�������
     *  \param x2 �¾������½ǵĺ�����
     *  \param y2 �¾������½ǵ�������
     */
    void Set(const short x1, const short y1, const short x2, const short y2)
    {
        wLeft = x1;
        wTop = y1;
        wRight = x2;
        wBottom = y2;
    }

    //##ModelId=3F4EC47802E3
    /*! \brief �����µľ�������
     *  \param ul �¾������Ͻǵ�����
     *  \param br �¾������½ǵ�����
     */
    void Set(const FG_Point ul, const FG_Point br)
    {
        wLeft = ul.x;
        wTop = ul.y;
        wRight = br.x;
        wBottom = br.y;
    }

    //##ModelId=3F4EC478035B
    /*! \brief �ж����ص��Ƿ�λ�ڱ�������
     *  \param Test Ҫ���Ե����ص�
     *  \return true ���ص��Ƿ�λ�ڱ�������
     *          false ���ص㲻�ڱ�������
     */
    bool Contains(const FG_Point Test) const;
    
    //##ModelId=3F4EC47803B5
    /*! \brief �ж����ص��Ƿ�λ�ڱ�������
     *  \param x Ҫ���Ե����ص�ĺ�����
     *  \param y Ҫ���Ե����ص��������
     *  \return true ���ص��Ƿ�λ�ڱ�������
     *          false ���ص㲻�ڱ�������
     */
    bool Contains(const short x, const short y) const;

    //##ModelId=3F4EC4790059
    /*! \brief �ж�ĳ�����Ƿ���ȫλ�ڱ�������
     *  \param Rect Ҫ���Եľ���
     *  \return true �����Ƿ�λ�ڱ�������
     *          false ���β��ڱ�������
     */
    bool Contains(const FG_Rect & Rect) const;

    //##ModelId=3F4EC47900C7
    /*! \brief �ж�ĳ�����Ƿ�ͱ����λ�������
     *  \param Rect Ҫ���Եľ���
     *  \return true �������λ�������
     *          false �������β���������
     */
    bool Overlap(const FG_Rect & Rect) const;
    
    //##ModelId=3F4EC479012B
    /*! \brief ƽ�ƾ���
     *
     *  �������ƶ���x���������ƶ���y
     *  \param x ����Ҫ�ƶ����ĺ�����λ��
     *  \param y ����Ҫ�ƶ�����������λ��
     */
    void MoveTo(const short x, const short y);
    
    //##ModelId=3F4EC47901C2
    /*! \brief ƽ�ƾ���
     *
     *  ������ƽ��x�㣬������ƽ��y��
     *  \param xShift ������ƽ�Ƶ�������
     *  \param yShift ������ƽ�Ƶ�������
     */
    void Shift(const short xShift, const short yShift);

    //##ModelId=3F4EC4790258
    /*! \brief ����&=�����
     *
     *  ��������ִ��&=���㣬��ȡ���������ཻ�Ĳ���
     *  \param Other ִ��&=�������һ������
     *  \return ���ؽ������
     */
    FG_Rect & operator &=(const FG_Rect & Other);

    //##ModelId=3F4EC47902B2
    /*! \brief ����|=�����
     *
     *  ��������ִ��|=���㣬���ܰ����������ε���С����
     *  \param Other ִ��|=�������һ������
     *  \return ���ؽ������
     */
    FG_Rect & operator |= (const FG_Rect & Other);

    //##ModelId=3F4EC479030C
    /*! \brief ����&�����
     *
     *  ��������ִ��&���㣬��ȡ���������ཻ�Ĳ���
     *  \param Rect ִ��&�������һ������
     *  \return ���ؽ������
     */
    FG_Rect operator &(const FG_Rect & Rect) const;

    //##ModelId=3F4EC47A0000
    /*! \brief ����+�����
     *
     *  ���ε�x�᷽������������Poing.x�����أ����ε�y�᷽������������Poing.y������
     *  \param Point ִ��+����Ĳ���
     *  \return ���ؽ������
     */
    FG_Rect operator +(const FG_Point & Point) const; 
    
    //##ModelId=3F4EC47A0079
    /*! \brief ���غ���++�����
     *
     *  ���ε�x���y�᷽�������һ������
     *  \return ���ؽ������
     */
    const FG_Rect operator ++(int);

    //##ModelId=3F4EC47A00D3
    /*! \brief ����+=�����
     *
     *  ���ε�x���y�᷽�������x������
     *  \param x Ҫ�����������
     *  \return ���ؽ������
     */
    FG_Rect & operator += (const int x);

    //##ModelId=3F4EC47A0137
    /*! \brief ���غ���--�����
     *
     *  ���ε�x���y�᷽�����Сһ������
     *  \return ���ؽ������
     */
    const FG_Rect operator --(int);
    
    //##ModelId=3F4EC47A019B
    /*! \brief ����-=�����
     *
     *  ���ε�x���y�᷽�����Сx������
     *  \param x Ҫ��С��������
     *  \return ���ؽ������
     */
    FG_Rect & operator -= (const int x);

    //##ModelId=3F4EC47A0209
    /*! \brief ����!=�����
     *
     *  �Ƚ����������Ƿ�ͬ
     *  \param Rect Ҫ�Ƚϵľ���
     *  \return true ��ͬ false ��ͬ
     */
    bool operator != (const FG_Rect & Rect) const;

    //##ModelId=3F4EC47A028B
    /*! \brief ����==�����
     *
     *  �Ƚ����������Ƿ���ͬ
     *  \param Rect Ҫ�Ƚϵľ���
     *  \return true ��ͬ false ��ͬ
     */
    bool operator == (const FG_Rect &Rect) const;
                     
    //##ModelId=3F4EC47A0322
    /*! \brief �õ����εĿ��
     *
     *  \return ���εĿ��
     */
    short Width(void) const { return (wRight - wLeft + 1); }

    //##ModelId=3F4EC47A039A
    /*! \brief �õ����εĸ߶�
     *
     *  \return ���εĸ߶�
     */
    short Height(void) const { return (wBottom - wTop + 1); }
};

#endif /* FG_RECT_H_HEADER_INCLUDED_C0B10BA4 */

/*! @} */

