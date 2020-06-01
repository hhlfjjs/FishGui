/*--------------------------------------------------------------------------

	FG_String.h - 字符串类的头文件

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
 *  \brief FishGUI字符串类的头文件
 */

#ifndef __FG_STRING_H__
#define __FG_STRING_H__

#include "FG_Common.h"

//##ModelId=409260760166
/*  \brief 字符串类
 *
 *  该类封装字符串的操作，
 *  现在只实现了动态内存管理（在设置不同长度的字符串时，自动改变缓冲区的长度）的部分，
 *  以后可以添加比较、连接、拷贝等各种字符串操作，运算符重载，以及Unicode支持等
 */
class FG_String
{
public:
    //##ModelId=40926077001D
    /*! \brief 字符串类的缺省构造函数 */
    FG_String() : m_pText(NULL), m_wStrLen(0), m_wBufferLen(0) {}
    
    //##ModelId=40926077001E
    /*! \brief 字符串类的转换构造函数
     * 
     *  \param Text 要封装的字符串
     */
    FG_String(const char * Text);

    //##ModelId=409260770031
    /*! \brief 字符串类的构析函数
     *  
     *  负责释放字符串
     */
    virtual ~FG_String();

    //##ModelId=409260770033
    /*! \brief 设置字符串的内容
     * 
     *  \param Text 要设置的字符串
     */
    void DataSet(const char *Text);
    //##ModelId=409260770045
    /*! \brief 得到字符串的内容
     * 
     *  \return 指向字符串的内容，用户无需释放此指针
     */
    char * DataGet(void) const { return m_pText; }
    
    //##ModelId=40926077005A
    /*! \brief 得到字符串的长度
     * 
     *  \return 字符串的长度
     */
    WORD Length(void) const { return m_wStrLen; }

private:
    //##ModelId=4092607603BF
    char * m_pText;             /*!< \brief 字符串类中保存的当前文本 */
    //##ModelId=4092607603D4
    WORD m_wStrLen;             /*!< \brief 当前文本的长度 */
    //##ModelId=4092607603E8
    WORD m_wBufferLen;          /*!< \brief 当前缓冲区的长度的长度，一般比文本的长度长 */
};

#endif

/*! @} */

