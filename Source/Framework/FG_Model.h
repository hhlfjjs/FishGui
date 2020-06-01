/*--------------------------------------------------------------------------

	FG_Model.h - MVC模式中的模型类的头文件

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
 *  \brief MVC模式中的模型类的头文件
 *
*/

#ifndef FG_MODEL_H_HEADER_INCLUDED_C0AD453B
#define FG_MODEL_H_HEADER_INCLUDED_C0AD453B

//##ModelId=3F844CD702B8
/*! \brief MVC模式中的模型类
 *
 *  该类的派生类可以作为MVC模式中的模型类
 */
class FG_Model
{
public:
    //##ModelId=3F844CD8029A
    /*! \brief 在模型中注册视图
     *
     *  \param pView 要注册的视图指针，试图必须是\ref FG_Object的派生类
     *  \return 注册操作是否成功\n
     *          true　 成功\n
     *          false　失败
     */
    bool RegisterView(FG_Object * const pView)
    {
        if (pView)
            return m_ViewList.Add(pView);
        else
            return false;
    }

    //##ModelId=3F844CD802AE
    /*! \brief 给所有注册的视图发送\ref FG_MSG_UPDATE_VIEW
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
    /*! \brief 保存所有注册的视图的指针的容器类型
     *
     */
    typedef FG_SList<FG_Object> FG_VIEWLIST;

    //##ModelId=3F844CD8027D
    FG_VIEWLIST m_ViewList;             /*!< 保存所有注册的视图的指针的容器变量 */
};

#endif /* FG_MODEL_H_HEADER_INCLUDED_C0AD453B */

/* @} */

