/*--------------------------------------------------------------------------

	MyModel.h - 用户创建的模型类的头文件

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
/*! \addtogroup MVC_Application
 *  @{ 
 */

/*! \file
 *  \brief 用户创建的模型类的头文件
 *
*/

#ifndef MYMODEL_H_HEADER_INCLUDED_C0AD453B
#define MYMODEL_H_HEADER_INCLUDED_C0AD453B

#include "../../Source/Framework/FG_Framework.h"

/*! \brief 用户创建的模型类
 *
 *  单件类
 */
class MyModel : public FG_Model
{
public:
    /*! \brief 得到模型类的唯一实例对象的指针
     *
     *  \return 指向模型类的唯一实例对象的指针
     */
    static MyModel * GetModel(void);

    /*! \brief 得到第一组中的某个数据
     *
     *  \param num 数据的索引（0-9）
     *  \return 数据（0-255）
     */
    unsigned char GetData1(short num) const
    {
        if (num >= 0 && num < 10) 
            return m_Data[0][num];
        else
            return 0;
    }
    
    /*! \brief 得到第二组中的某个数据
     *
     *  \param num 数据的索引（0-9）
     *  \return 数据（0-255）
     */
    unsigned char GetData2(short num) const
    {
        if (num >= 0 && num < 10) 
            return m_Data[1][num];
        else
            return 0;
    }

    /*! \brief 第一组中添加一个数据
     *
     *  \param data 要添加的数据（0-255）
     */
    void SendData1(unsigned char data);

    /*! \brief 第二组中添加一个数据
     *
     *  \param data 要添加的数据（0-255）
     */
    void SendData2(unsigned char data);

    void AdjustData(void);

protected:
    /*! \brief 模型类的构造函数 */
    MyModel();

private:
    unsigned char m_Data[2][10];    /*!< \brief 保存数据的缓冲区，两组各10个 */

    static MyModel * m_pModel;      /*!< \brief 指向模型类的唯一实例对象的指针 */
};

/*! \brief 得到模型类的唯一实例对象的指针
 *
 *  \return 指向模型类的唯一实例对象的指针
 */
MyModel * GetMyModel(void);

#endif /* MYMODEL_H_HEADER_INCLUDED_C0AD453B */

/*! @} */

