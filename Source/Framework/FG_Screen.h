/*--------------------------------------------------------------------------

	FG_Screen.h - ��Ļ���ͷ�ļ�

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
/*! \addtogroup Framework
 *  @{ 
 */

/*! \file
 *  \brief ��Ļ���ͷ�ļ�
 *
*/

#ifndef FG_SCREEN_H_HEADER_INCLUDED_C0AD5887
#define FG_SCREEN_H_HEADER_INCLUDED_C0AD5887

#include "../Utility/FG_Utility.h"
#include "../OSAdaptor/FG_OSAdaptor.h"
#include "FG_Window.h"

class FG_Factory;

//##ModelId=3F52B6B70300
/*! \brief ��Ļ��
 *
 *  ����Ϊ�����࣬����������Ļ�豸������Ļ�Ͽ��Է��ö�����໥���ǵĴ���
 */
class FG_Screen : public FG_Container, FG_OSMsgObserver
{
public:
    //##ModelId=3F57524C03BA
    /*! \brief �õ���Ļ���Ψһʵ�������ȫ�ַ��ʵ㺯��
     *
     *  ע��Ϊ\ref FG_MSG_DRAW��\ref FG_MSG_KEY��\ref FG_MSG_MOUSE��Ϣ�Ĺ۲���
     *  \return ָ����Ļ���Ψһʵ�������ָ��
     */
    static FG_Screen * GetScreen(void);

    //##ModelId=3F71AB1F0386
    /*! \brief ɾ����Ļ���Ψһʵ������
     */
    static void DeleteScreen(void);

    //##ModelId=3F57F111009E
    /*! \brief ����Ļ�����һ������
     *
     *  �������\ref FG_Container::AddChild����Ҫ���ͽ����л���Ϣ
     *  \param pWindow Ҫ��ӵĴ��ڶ����ָ��
     *  \return ��Ӳ����Ƿ�ɹ�
     *          true    �ɹ�
     *          false   ʧ��
     */
    bool AddWindow(FG_Window * pWindow);

    //##ModelId=3F57F1110120
    /*! \brief ����Ļ��ɾ��һ������
     *
     *  �������\ref FG_Container::RemoveChild����Ҫ���ͽ����л���Ϣ
     *  \param pWindow Ҫɾ���Ĵ��ڶ����ָ��
     *  \return ɾ�������Ƿ�ɹ�
     *          true    �ɹ�
     *          false   ʧ��
     */
    bool RemoveWindow(FG_Window * pWindow);

    //##ModelId=3F57524C03C5
    void OSMessage(FG_Message * pMsg);

    //##ModelId=3F6EAC8F01AA
    /*! \brief �õ���ǰʹ�õĹ�������
     *
     *  \return ָ��ǰʹ�õĹ��������ָ��
     */
    FG_Factory * GetFactory() const { return m_pFactory; }

    //##ModelId=3F6EAC8F01B4
    /*! \brief ���õ�ǰʹ�õĹ�������
     *
     *  \param pFactory Ҫ���õĹ��������ָ��
     */
    void SetFactory(FG_Factory * pFactory);

protected:
    //##ModelId=3F6193A70319
    /*! \brief ���ڷ��͵�Ҫ���ػ���Ϣ\ref FG_MSG_DRAW_REQUEST�Ĵ�����
     *
     *  ���ڴ��ڶ��������ػ����󣬲���ֱ���ػ�����������һ��ʱ��Ϊ\ref SCREEN_DRAW_INTERVAL��50���룩�Ķ�ʱ����
     *  ��ʱ������ʱ��ִ���ػ��������ö�ʱ����ɾ��֮ǰֻ�ܱ��ɹ�һ�Σ����50 �����ڵ�ֻ�ᷢ��һ���ػ�������
     *  ������ػ���Ч�ʣ�����������˸��
     *  \param pMsg ָ��Ҫ���ػ���Ϣ�ṹ��ָ��
     */
    void OnDrawRequest(FG_Message * pMsg);

    //##ModelId=3F71AB1F03C2
    /*! \brief ���ڼ����ػ������Ķ�ʱ����Ϣ��\ref TIMERID_DRAW���Ĵ�����
     *
     *  �����ػ����еĴ���
     */
    void OnDrawTimer(void);

    //##ModelId=3F6193A70337
    /*! \brief �����ػ����д���
     *
     *  ͨ������\ref FG_MSG_DRAW��ϢҪ�󴰿��ػ��Լ�
     */
    void DrawAllWindow();

    //##ModelId=3F57524D0036
    /*! \brief ��Ļ��Ĺ��캯�����û�����ֱ�ӵ���
     *
     *  \param Rect ��Ļռ�ݵľ����������Ͻ��������ǣ�0, 0�������½�����Ϊ��\ref SCREEN_WIDTH, \ref SCREEN_HEIGHT��
     */
    FG_Screen(const FG_Rect & Rect);

    //##ModelId=3F71AB20003E
    /*! \brief �����������û�����ֱ�ӵ��� */
    ~FG_Screen();

    //##ModelId=3F71ACB000E4
    FG_Factory * m_pFactory;            /*!< \brief ָ��ǰʹ�õĹ��������ָ�� */

private:
    //##ModelId=3F71AB1F034A
    /*! \brief ��ʱ��ID
     */
    enum 
    {
        TIMERID_DRAW = 0xff             /*!< \brief ���ڼ����ػ������Ķ�ʱ��ID */
    };

    //##ModelId=3F57524C0393
    static FG_Screen * m_pScreen;       /*!< \brief ָ��Ψһ����Ļ���ʵ�������ָ�룬����ʵ�ֵ����� */

    DECLARE_MESSAGE_MAP()
};

/*! \brief ��װ��Ļ���ȫ�ַ��ʵ㺯����\ref FG_Screen::GetScreen����ȫ�ֺ���
 *
 *  \return ָ����Ļ���Ψһʵ�������ָ��
 */
FG_Screen * FG_GetScreen();

/*! \brief ��װ�õ���ǰʹ�õĹ�������\ref FG_Screen::GetFactory����ȫ�ֺ���
 *
 *  \return ָ��ǰʹ�õĹ��������ָ��
 */
FG_Factory * FG_GetFactory();

/*! \brief ��װ���õ�ǰʹ�õĹ�������\ref FG_Screen::SetFactory����ȫ�ֺ���
 *
 *  \param pFactory Ҫ���õĹ��������ָ��
 */
void FG_SetFactory(FG_Factory * pFactory);

#endif /* FG_SCREEN_H_HEADER_INCLUDED_C0AD5887 */

/*! @} */

