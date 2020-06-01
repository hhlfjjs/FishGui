/*--------------------------------------------------------------------------

	FG_Rect.h - 矩形结构的头文件

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
 *  \brief 矩形结构的头文件
 *
 *  定义屏幕上使用的矩形结构，每一个矩形结构由左上角和右下角两个点来表示
*/

#ifndef FG_RECT_H_HEADER_INCLUDED_C0B10BA4
#define FG_RECT_H_HEADER_INCLUDED_C0B10BA4

#include "FG_Point.h"

//##ModelId=3F4EC135021A
/*! \brief 矩形结构
 *
 *  定义屏幕上使用的矩形结构
 */
struct FG_Rect
{
    //##ModelId=3F4EC4780094
    short wLeft;                   /*!< \brief 矩形左上角的横坐标 */
    //##ModelId=3F4EC47800B2
    short wTop;                    /*!< \brief 矩形左上角的纵坐标 */
    //##ModelId=3F4EC47800D0
    short wRight;                  /*!< \brief 矩形右下角的横坐标 */
    //##ModelId=3F4EC47800EE
    short wBottom;                 /*!< \brief 矩形右下角的纵坐标 */
    
    //##ModelId=40925B4D01C1
    /*! \brief 矩形结构的缺省构造函数
     */
    FG_Rect() : wLeft(0), wTop(0), wRight(0), wBottom(0) {}
    //##ModelId=40925B4D01DF
    /*! \brief 矩形结构的构造函数
     *  \param x1 矩形左上角的横坐标
     *  \param y1 矩形左上角的纵坐标
     *  \param x2 矩形右下角的横坐标
     *  \param y2 矩形右下角的纵坐标
     */
    FG_Rect(const short x1, const short y1, const short x2, const short y2) 
        : wLeft(x1), wTop(y1), wRight(x2), wBottom(y2) {}

    //##ModelId=3F4EC4780210
    /*! \brief 设置新的矩形坐标
     *  \param x1 新矩形左上角的横坐标
     *  \param y1 新矩形左上角的纵坐标
     *  \param x2 新矩形右下角的横坐标
     *  \param y2 新矩形右下角的纵坐标
     */
    void Set(const short x1, const short y1, const short x2, const short y2)
    {
        wLeft = x1;
        wTop = y1;
        wRight = x2;
        wBottom = y2;
    }

    //##ModelId=3F4EC47802E3
    /*! \brief 设置新的矩形坐标
     *  \param ul 新矩形左上角的坐标
     *  \param br 新矩形右下角的坐标
     */
    void Set(const FG_Point ul, const FG_Point br)
    {
        wLeft = ul.x;
        wTop = ul.y;
        wRight = br.x;
        wBottom = br.y;
    }

    //##ModelId=3F4EC478035B
    /*! \brief 判断像素点是否位于本矩形内
     *  \param Test 要测试的像素点
     *  \return true 像素点是否位于本矩形内
     *          false 像素点不在本矩形内
     */
    bool Contains(const FG_Point Test) const;
    
    //##ModelId=3F4EC47803B5
    /*! \brief 判断像素点是否位于本矩形内
     *  \param x 要测试的像素点的横坐标
     *  \param y 要测试的像素点的纵坐标
     *  \return true 像素点是否位于本矩形内
     *          false 像素点不在本矩形内
     */
    bool Contains(const short x, const short y) const;

    //##ModelId=3F4EC4790059
    /*! \brief 判断某矩形是否完全位于本矩形内
     *  \param Rect 要测试的矩形
     *  \return true 矩形是否位于本矩形内
     *          false 矩形不在本矩形内
     */
    bool Contains(const FG_Rect & Rect) const;

    //##ModelId=3F4EC47900C7
    /*! \brief 判断某矩形是否和本矩形互相重载
     *  \param Rect 要测试的矩形
     *  \return true 两个矩形互相重载
     *          false 两个矩形不互相重载
     */
    bool Overlap(const FG_Rect & Rect) const;
    
    //##ModelId=3F4EC479012B
    /*! \brief 平移矩形
     *
     *  横坐标移动到x，纵坐标移动到y
     *  \param x 矩形要移动到的横坐标位置
     *  \param y 矩形要移动到的纵坐标位置
     */
    void MoveTo(const short x, const short y);
    
    //##ModelId=3F4EC47901C2
    /*! \brief 平移矩形
     *
     *  横坐标平移x点，纵坐标平移y点
     *  \param xShift 横坐标平移的像素数
     *  \param yShift 纵坐标平移的像素数
     */
    void Shift(const short xShift, const short yShift);

    //##ModelId=3F4EC4790258
    /*! \brief 重载&=运算符
     *
     *  两个矩形执行&=运算，即取两个矩形相交的部分
     *  \param Other 执行&=运算的另一个矩形
     *  \return 返回结果矩形
     */
    FG_Rect & operator &=(const FG_Rect & Other);

    //##ModelId=3F4EC47902B2
    /*! \brief 重载|=运算符
     *
     *  两个矩形执行|=运算，即能包含两个矩形的最小矩形
     *  \param Other 执行|=运算的另一个矩形
     *  \return 返回结果矩形
     */
    FG_Rect & operator |= (const FG_Rect & Other);

    //##ModelId=3F4EC479030C
    /*! \brief 重载&运算符
     *
     *  两个矩形执行&运算，即取两个矩形相交的部分
     *  \param Rect 执行&运算的另一个矩形
     *  \return 返回结果矩形
     */
    FG_Rect operator &(const FG_Rect & Rect) const;

    //##ModelId=3F4EC47A0000
    /*! \brief 重载+运算符
     *
     *  矩形的x轴方向向左右扩大Poing.x个像素，矩形的y轴方向向上下扩大Poing.y个像素
     *  \param Point 执行+运算的参数
     *  \return 返回结果矩形
     */
    FG_Rect operator +(const FG_Point & Point) const; 
    
    //##ModelId=3F4EC47A0079
    /*! \brief 重载后置++运算符
     *
     *  矩形的x轴和y轴方向各扩大一个像素
     *  \return 返回结果矩形
     */
    const FG_Rect operator ++(int);

    //##ModelId=3F4EC47A00D3
    /*! \brief 重载+=运算符
     *
     *  矩形的x轴和y轴方向各扩大x个像素
     *  \param x 要扩大的像素数
     *  \return 返回结果矩形
     */
    FG_Rect & operator += (const int x);

    //##ModelId=3F4EC47A0137
    /*! \brief 重载后置--运算符
     *
     *  矩形的x轴和y轴方向各缩小一个像素
     *  \return 返回结果矩形
     */
    const FG_Rect operator --(int);
    
    //##ModelId=3F4EC47A019B
    /*! \brief 重载-=运算符
     *
     *  矩形的x轴和y轴方向各缩小x个像素
     *  \param x 要缩小的像素数
     *  \return 返回结果矩形
     */
    FG_Rect & operator -= (const int x);

    //##ModelId=3F4EC47A0209
    /*! \brief 重载!=运算符
     *
     *  比较两个矩形是否不同
     *  \param Rect 要比较的矩形
     *  \return true 不同 false 相同
     */
    bool operator != (const FG_Rect & Rect) const;

    //##ModelId=3F4EC47A028B
    /*! \brief 重载==运算符
     *
     *  比较两个矩形是否相同
     *  \param Rect 要比较的矩形
     *  \return true 相同 false 不同
     */
    bool operator == (const FG_Rect &Rect) const;
                     
    //##ModelId=3F4EC47A0322
    /*! \brief 得到矩形的宽度
     *
     *  \return 矩形的宽度
     */
    short Width(void) const { return (wRight - wLeft + 1); }

    //##ModelId=3F4EC47A039A
    /*! \brief 得到矩形的高度
     *
     *  \return 矩形的高度
     */
    short Height(void) const { return (wBottom - wTop + 1); }
};

#endif /* FG_RECT_H_HEADER_INCLUDED_C0B10BA4 */

/*! @} */

