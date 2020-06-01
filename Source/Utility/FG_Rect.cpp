/*--------------------------------------------------------------------------

	FG_Rect.cpp - 矩形结构的实现文件

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
 *  \brief 矩形结构的实现文件
 */

/*! @} */

#include "FG_Rect.h"

//##ModelId=3F4EC478035B
bool FG_Rect::Contains(const FG_Point Test) const
{
    if (Test.x >= wLeft &&
        Test.x <= wRight &&
        Test.y >= wTop &&
        Test.y <= wBottom)
    {
        return true;
    }
    return false;
}

//##ModelId=3F4EC47803B5
bool FG_Rect::Contains(const short x, const short y) const
{
    if (x >= wLeft &&
        x <= wRight &&
        y >= wTop &&
        y <= wBottom)
    {
        return true;
    }
    return false;
}

//##ModelId=3F4EC4790059
bool FG_Rect::Contains(const FG_Rect & Rect) const
{
    if (Rect.wLeft >= wLeft &&
        Rect.wRight <= wRight &&
        Rect.wTop >= wTop &&
        Rect.wBottom <= wBottom)
    {
        return true;
    }
    return false;
}

//##ModelId=3F4EC47900C7
bool FG_Rect::Overlap(const FG_Rect & Rect) const
{
    if (Rect.wLeft <= wRight &&
        Rect.wTop <= wBottom &&
        Rect.wBottom >= wTop &&
        Rect.wRight >= wLeft)
    {
        return true;
    }
    return false;
}

//##ModelId=3F4EC479012B
void FG_Rect::MoveTo(const short x, const short y)
{
    short xShift = x - wLeft;
    short yShift = y - wTop;
    Shift(xShift, yShift);
}

//##ModelId=3F4EC47901C2
void FG_Rect::Shift(const short xShift, const short yShift)
{
    wLeft += xShift;
    wRight += xShift;
    wTop += yShift;
    wBottom += yShift;
}

//##ModelId=3F4EC4790258
FG_Rect & FG_Rect::operator &= (const FG_Rect & Rect)
{
    if (Rect.wLeft > wLeft)
    {
        wLeft = Rect.wLeft;
    }
    if (Rect.wRight < wRight)
    {
        wRight = Rect.wRight;
    }
    if (Rect.wTop > wTop)
    {
        wTop = Rect.wTop;
    }
    if (Rect.wBottom < wBottom)
    {
        wBottom = Rect.wBottom;
    }
    return * this;
}

//##ModelId=3F4EC47902B2
FG_Rect & FG_Rect::operator |= (const FG_Rect & Rect)
{
    if (wLeft > Rect.wLeft)
    {
        wLeft = Rect.wLeft;
    }

    if (wRight < Rect.wRight)
    {
        wRight = Rect.wRight;
    }
    if (wTop > Rect.wTop)
    {
        wTop = Rect.wTop;
    }
    if (wBottom < Rect.wBottom)
    {
        wBottom = Rect.wBottom;
    }
    return * this;
}

//##ModelId=3F4EC479030C
FG_Rect FG_Rect::operator &(const FG_Rect & Rect) const
{
    FG_Rect NewRect = * this;
    if (NewRect.wLeft < Rect.wLeft)
    {
        NewRect.wLeft = Rect.wLeft;
    }
    if (NewRect.wRight > Rect.wRight)
    {
        NewRect.wRight = Rect.wRight;
    }
    if (NewRect.wTop < Rect.wTop)
    {
        NewRect.wTop = Rect.wTop;
    }
    if (NewRect.wBottom > Rect.wBottom)
    {
        NewRect.wBottom = Rect.wBottom;
    }
    return NewRect;
}

//##ModelId=3F4EC47A0000
FG_Rect FG_Rect::operator +(const FG_Point & Point) const
{
    FG_Rect NewRect;
    NewRect.wLeft = wLeft + Point.x;
    NewRect.wRight = wRight + Point.x;
    NewRect.wTop = wTop + Point.y;
    NewRect.wBottom = wBottom + Point.y;
    return NewRect;
}

const FG_Rect FG_Rect::operator++(int)
{
    FG_Rect temp = * this;
    wLeft--;
    wRight++;
    wTop--;
    wBottom++;
    return temp;
}

FG_Rect & FG_Rect::operator+=(const int Val)
{
    wLeft -= Val;
    wRight += Val;
    wTop -= Val;
    wBottom += Val;
    return *this;
}

const FG_Rect FG_Rect::operator--(int)
{
    FG_Rect temp = * this;
    
    wLeft++;
    wRight--;
    wTop++;
    wBottom--;

    if (wLeft > wRight)
    {
        wRight = wLeft;
    }
    if (wBottom < wTop)
    {
        wBottom = wTop;
    }
    return temp;
}

FG_Rect & FG_Rect::operator-=(const int Val)
{
    wLeft += Val;
    wRight -= Val;
    wTop += Val;
    wBottom -= Val;
    if (wLeft > wRight)
    {
        wRight = wLeft;
    }
    if (wBottom < wTop)
    {
        wBottom = wTop;
    }
    return * this;
}

//##ModelId=3F4EC47A0209
bool FG_Rect::operator != (const FG_Rect & Rect) const
{
    if (Rect.wTop != wTop ||
        Rect.wBottom != wBottom ||
        Rect.wLeft != wLeft ||
        Rect.wRight != wRight)
    {
        return true;
    }
    return false;
}

//##ModelId=3F4EC47A028B
bool FG_Rect::operator == (const FG_Rect & Rect) const
{
    if (Rect.wTop == wTop &&
        Rect.wBottom == wBottom &&
        Rect.wLeft == wLeft &&
        Rect.wRight == wRight)
    {
        return true;
    }
    return false;
}

