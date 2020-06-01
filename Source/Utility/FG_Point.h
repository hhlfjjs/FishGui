/*--------------------------------------------------------------------------

	FG_Point.h - 像素点结构的头文件

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
 *  \brief 像素点结构的头文件
 *
 *  定义屏幕上使用的像素点的结构，每一个像素点由横坐标和纵坐标构成
*/

#ifndef FG_POINT_H_HEADER_INCLUDED_C0B109A9
#define FG_POINT_H_HEADER_INCLUDED_C0B109A9

//##ModelId=3F4EC1290046
/*! \brief 像素点结构
 *
 *  定义屏幕上使用的像素点的结构
 */
struct FG_Point
{
    //##ModelId=3F4EC47701FB
    short x;                        /*!< \brief 像素点的横坐标 */
    //##ModelId=3F4EC477034F
    short y;                        /*!< \brief 像素点的纵坐标 */

    //##ModelId=3F4EC477036D
    /*! \brief 比较两个点是否不同
     *
     *  !=运算符，比较本像素点和另外一个像素点是否不同（即横坐标和纵坐标至少有一个不同）
     *  \param InPoint 被比较的像素点
     *  \return true: 两个点不同    false: 两个点相同
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
    /*! \brief 比较两个点是否相同
     *
     *  ==运算符，比较本像素点和另外一个像素点是否相同（即横坐标和纵坐标都相同）
     *  \param InPoint 被比较的像素点
     *  \return true: 两个点相同    false: 两个点不同
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
    /*! \brief 两个点相加
     *
     *  +运算符，本像素点和另外一个像素点相加（即横坐标和纵坐标分别相加）
     *  \param Point 被相加的像素点
     *  \return 返回相加结果
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

