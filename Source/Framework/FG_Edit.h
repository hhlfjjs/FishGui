/*--------------------------------------------------------------------------

	FG_Edit.h - 编辑控件类的头文件

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
/*! \addtogroup Framework
 *  @{ 
 */

/*! \file
 *  \brief 编辑控件类的头文件
 */

#ifndef FG_EDIT_H_HEADER_INCLUDED_C0A79742
#define FG_EDIT_H_HEADER_INCLUDED_C0A79742

#include "FG_Label.h"

//##ModelId=3F37D6F50106
/*! \brief 编辑控件类
 *
 *  该控件可以放置在窗口上，用户通过该控件可以输入文字
 */
class FG_Edit : public FG_Label
{
public:
    //##ModelId=3F65E8E20322
	/*! \brief 编辑控件的构造函数
	 *
	 *  \param Text 编辑控件中显示的初始文本
	 *  \param Rect 编辑控件占据的巨型区域
	 *  \param wLimit 编辑控件中能输入的最大字符数
	 *  \param wID 编辑控件的唯一标识，缺省为0
	 *  \param wStyle 编辑控件的\ref Style，缺省为\ref TS_LEFT|\ref FS_RECESSED
	 */
	FG_Edit(const char * Text, const FG_Rect & Rect, const WORD wLimit, const WORD wID = 0, const WORD wStyle = TS_LEFT|FS_RECESSED);

    //##ModelId=3F6EAC8F0074
    /*! \brief 返回控件能否得到焦点的标志
     *
     *  编辑控件能得到焦点
     *  \return true   该控件能得到焦点
     */
    bool CanGetFocus() const { return true; }

protected:
    //##ModelId=3F65E8E20368
    /*! \brief 重画消息\ref FG_MSG_DRAW的处理函数
     *
     *  \param pAdaptor 指向操作系统适配器的指针
     */
	void OnDraw(FG_OSAdaptor * pAdaptor);

    //##ModelId=3F65E8E2037C
    /*! \brief 键盘按下消息（\ref FG_MSG_KEY，\ref FKS_DOWN）的处理函数
     *
     *  特殊处理\ref FVK_DELETE、\ref FVK_LEFT、\ref FVK_RIGHT等键，输入数字0--9
     *  \param pMsg 指向键盘消息结构的指针
     */
	bool OnKeyDown(FG_Message * pMsg);

    //##ModelId=3F65E8E2039A
    /*! \brief 鼠标消息（\ref FG_MSG_MOUSE）的处理函数
     *
     *  \param pMsg 指向鼠标消息结构的指针
     */
	bool OnMouse(FG_Message * pMsg);

    //##ModelId=3F65E8E203AF
    /*! \brief 光标闪烁的定时器消息（\ref TIMERID_CURSOR）的处理函数
     *
     */
    void OnCursorTimer(void);

    //##ModelId=3F65E8E203B9
    /*! \brief 焦点切换消息\ref FG_MSG_FOCUS的处理函数
     *
     *  \param pMsg 指向焦点切换消息结构的指针
     */
    void OnFocus(FG_Message * pMsg);

    //##ModelId=3F65E8E202C9
	WORD m_wLimit;                  /*!< \brief 编辑控件中能输入的最大的字符个数 */
    //##ModelId=3F65E8E202E7
	WORD m_wCursorPos;              /*!< \brief 光标的当前位置 */
    //##ModelId=3F65E8E20304
	bool m_bDrawCursor;             /*!< \brief 光标是否显示，true表示显示，false表示不显示 */

private:
    //##ModelId=3F65E8E20296
    /*! \brief 控制光标闪烁的定时器ID
     */
    enum
    {
        TIMERID_CURSOR = 0xff
    };

    //##ModelId=3F65E8E203D7
    /*! \brief 在编辑控件的当前光标位置插入一个字符
     *
     *  \param wKey 要插入的字符的\ref Virtual_Key
     */
    void InsertChar(WORD wKey);

    //##ModelId=3F65E8E30003
	/*! \brief 删除当前光标后的一个字符
	 */
	void DeleteChar();

    //##ModelId=3F65E8E30017
	/*! \brief 重画文本（包括光标）
	 *
	 *  把光标设置为显示，然后要求重画
	 */
	void DrawWithCursor();

    DECLARE_MESSAGE_MAP()
};

#endif /* FG_EDIT_H_HEADER_INCLUDED_C0A79742 */

/*! @} */

