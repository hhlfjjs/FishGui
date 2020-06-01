/*--------------------------------------------------------------------------

	FG_Win32Adaptor.h - Win32�����������ͷ�ļ�

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
 *  \brief Win32�����������ͷ�ļ�
 */

#ifndef FG_WIN32ADAPTOR_H_HEADER_INCLUDED_C0B1A8C2
#define FG_WIN32ADAPTOR_H_HEADER_INCLUDED_C0B1A8C2

#include "windows.h"
#include "FG_OSAdaptor.h"
class FG_Win32DrawInterface;

//##ModelId=3F49CC120210
/*! \brief Win32����������
 *
 *  �����װWin32����ϵͳ�ĳ������������й���
 */
class FG_Win32Adaptor : public FG_OSAdaptor
{
public:
    //##ModelId=3F4E099D01F1
    /*! \brief �����ʼ��
     *
     *  ����Win32����ע�ᴰ���࣬�������ڣ�ˢ�´���\n
     *  ����\ref FG_MSG_STARTUP��Ϣ
     *  \return ��ʼ���Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    bool InitInstance();

    //##ModelId=3F4E09F802BB
    /*! \brief �����˳�
     *
     *  ����\ref FG_MSG_HALT��Ϣ���ͷŶ���
     *  \return �˳��Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    bool ExitInstance();

    //##ModelId=3F4E09F8031F
    /*! \brief �������й��̣�ִ����Ϣѭ��
     *
     *  ִ��Win32����Ϣѭ��
     *  \return �˳��Ƿ�ɹ�\n
     *          true    �ɹ�\n
     *          false   ʧ��
     */
    bool Execute();

    //##ModelId=3F6EAFFE01EA
    /*! \brief ���õ�ǰӦ�ó����ʵ�����
     *
     *  \param hInst ��ǰӦ�ó����ʵ�����
     */
    void SetInst(HINSTANCE hInst) { m_hInst = hInst; }

    //##ModelId=3F6EAFFE024E
    /*! \brief ����ǰһ��Ӧ�ó����ʵ�����
     *
     *  \param hPrevInst ǰһ��Ӧ�ó����ʵ�����
     */
    void SetPrevInst(HINSTANCE hPrevInst) { m_hPrevInst = hPrevInst; }

    //##ModelId=3F6EAFFE02B2
    /*! \brief ���ô��ڵ���ʾ��ʽ
     *
     *  \param nCmdShow ���ڵ���ʾ��ʽ
     */
    void SetCmdShow(int nCmdShow) { m_nCmdShow = nCmdShow; }

    //##ModelId=40925CB0009F
    /*! \brief ����λͼ�ļ�����Ŀ¼�ľ���·��
     *
     *  \param pPath FishGUI��Ŀ¼�ľ���·����ͨ��GetModuleFileName�������õõ�
     *  \param len �ַ���pPath�ĳ��ȣ��ַ�������֤��0������
     */
    void SetBmpPath(char * pPath, int len);

    //##ModelId=40925CB000E5
    /*! \brief ����λͼ
     *
     *  Win32�������า�Ǹú�������λͼ����ϳ�λͼ�ļ��ľ���·������Ȼ��������\ref FG_OSDrawInterface::DrawBitmap
     *  \param pBmpName Ҫ���Ƶ�λͼ��
     *  \param x1 λͼ���Ͻǵĺ�����
     *  \param y1 λͼ���Ͻǵ�������
     */
    virtual void DrawBitmap(const char * pBmpName, const short x1, const short y1);

protected:
    friend class FG_OSAdaptor;

    //##ModelId=3F4EB7140009
    /*! \brief Win32���������ȱʡ���캯�� */
    FG_Win32Adaptor() : m_hInst(0), m_hPrevInst(0), m_nCmdShow() {}

    //##ModelId=3F6EAFFE00F0
                                            /*!< \brief ��ǰӦ�ó����ʵ����� */
    HINSTANCE m_hInst, m_hPrevInst;         /*!< \brief ǰһ��Ӧ�ó����ʵ����� */

    //##ModelId=3F6EAFFE0172
    int m_nCmdShow;                         /*!< \brief ���ڵ���ʾ��ʽ */

    //##ModelId=40925CAF03E7
    char m_BmpPath[MAX_PATH + 1];           /*!< \brief λͼ�ļ�����Ŀ¼�ľ���·�� */

    //##ModelId=3F6EAFFE0335
    /*! \brief Win32���ں���
     *
     *  ���뾲̬�������ú�������ϵͳ��Ϣ��Ȼ��ͨ���۲���ģʽ���͸���ܲ�
     *  \param hWnd ���ھ��
     *  \param uMessage ��Ϣ����
     *  \param wParam ��Ϣ����
     *  \param lParam ��Ϣ����
     *  \return long ��Ϣ������
     */
    static long FAR WINAPI WndProc(HWND hWnd, UINT uMessage, UINT wParam, LONG lParam);
};

#endif /* FG_WIN32ADAPTOR_H_HEADER_INCLUDED_C0B1A8C2 */

/*! @} */

