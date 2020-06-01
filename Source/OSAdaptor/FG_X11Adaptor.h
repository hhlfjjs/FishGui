/*--------------------------------------------------------------------------

	FG_X11Adaptor.h - X11�����������ͷ�ļ�

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
/*! \addtogroup OSAdaptor
 *  @{ 
 */

/*! \file
 *  \brief X11�����������ͷ�ļ�
 */

#ifndef FG_X11ADAPTOR_H_HEADER_INCLUDED_C0B1A8C3
#define FG_X11ADAPTOR_H_HEADER_INCLUDED_C0B1A8C3

#include <sys/param.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "FG_OSAdaptor.h"

class FG_X11DrawInterface;

//##ModelId=3F6EAFFE00A0
/*! \brief X11����������
 *
 *  �����װX11����ϵͳ�ĳ������������й���
 */
class FG_X11Adaptor : public FG_OSAdaptor
{
public:
    //##ModelId=3F6EB00003E2
    /*! \brief �����ʼ��
     *
     *  ����X11������X11��ʾ�豸����������\n
     *  ����\ref FG_MSG_STARTUP��Ϣ
     *  \return ��ʼ���Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    bool InitInstance();

    //##ModelId=3F6EB00003E3
    /*! \brief �����˳�
     *
     *  �ر�X11��ʾ�豸���ͷŶ���
     *  \return �˳��Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    bool ExitInstance();

    //##ModelId=3F6EB00003E4
    /*! \brief �������й��̣�ִ����Ϣѭ��
     *
     *  ִ��X11����Ϣѭ��
     *  \return �˳��Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    bool Execute();
    
    //##ModelId=40925CB001FE
    /*! \brief ����λͼ�ļ�����Ŀ¼�ľ���·��
     *
     *  ���ַ����õ�FishGUI��Ŀ¼�ľ���·��
     *      - �ӻ�������HOME_FISHGUI�еõ�
     *      - �ӳ�������ʱargv[0]���������г���·���͵�ǰ·����ϵõ�\n
     *
     *  �ڶ��ַ����ڲ�ͬ�Ļ����в��ܱ�֤һ���ܵõ�λͼ�ļ�����Ŀ¼�ľ���·����
     *  ����������û��������û�������HOME_FISHGUI
     *  
     *  \param pPath argv[0]���������г���·��
     */
    void SetXpmPath(const char * pPath);
    
    //##ModelId=40925CB00226
    /*! \brief ����λͼ
     *
     *  X11�������า�Ǹú�������λͼ����ϳ�λͼ�ļ��ľ���·������Ȼ��������\ref FG_OSDrawInterface::DrawBitmap
     *  \param pBmpName Ҫ���Ƶ�λͼ��
     *  \param x1 λͼ���Ͻǵĺ�����
     *  \param y1 λͼ���Ͻǵ�������
     */
    virtual void DrawBitmap(const char * pBmpName, const short x1, const short y1);
    
protected:
    friend class FG_OSAdaptor;

    //##ModelId=3F6EB0010004
    /*! \brief X11���������ȱʡ���캯�� */
    FG_X11Adaptor() {}

private:
    //##ModelId=3F6EB0010005
    /*! \brief X11�¼�������
     *
     *  �ú�������ϵͳ��Ϣ��Ȼ��ͨ���۲���ģʽ���͸���ܲ�
     *  \param report ���յ����¼�
     */
    void process_event(XEvent report);

    //##ModelId=3F6EB00003C5
    Display * display;                      /*!< \brief X11��ʾ�豸 */

    //##ModelId=3F6EB00003CE
    int screen;                             /*!< \brief X11ȱʡ��Ļ�� */
    
    //##ModelId=3F6EB00003D8
    Window win;                             /*!< \brief X11���ڽṹ */
    
    //##ModelId=40925CB001CC
    char XpmPath[MAXPATHLEN + 1];           /*!< \brief λͼ�ļ�����Ŀ¼�ľ���·�� */
};

#endif /* FG_X11ADAPTOR_H_HEADER_INCLUDED_C0B1A8C3 */

/*! @} */

