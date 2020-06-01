/*--------------------------------------------------------------------------

	FG_Common.h - FishGUI�������Ͷ���ͷ�ļ�

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
/*! \addtogroup Utility
 *  @{ 
 */

/*! \file 
 *  \brief FishGUI�������Ͷ���ͷ�ļ�
 *
 *  ���ļ�������FIshGUIϵͳ�Ĺ������ͺͳ�����
 *  ���в������ͺͳ���ֵ�����ϵͳ��أ���ֲʱҪ�ı����е�ĳЩ���塣
 */

#ifndef FISHGUI_H_HEADER_INCLUDED_C0B126F2
#define FISHGUI_H_HEADER_INCLUDED_C0B126F2

#ifndef NULL
    /*! \brief ��ָ��Ķ��� */
    #define NULL               0
#endif /* NULL */

//##ModelId=3F4F05EF033B
/*! \brief �޷����ַ� */
typedef unsigned char	        BYTE;

//##ModelId=3F4F05EF036D
/*! \brief �޷��Ŷ����� */
typedef unsigned short	        WORD;

//##ModelId=3F4F05EF034F
/*! \brief �޷��ų����� */
typedef unsigned long	        DWORD;

const WORD SCREEN_WIDTH         = 800;      /*!< \brief ��Ļ��� */
const WORD SCREEN_HEIGHT        = 600;      /*!< \brief ��Ļ�߶� */

/*! \defgroup Color ��ɫ */
/*! @{ */
#if defined(WIN32)
    //##ModelId=3F4F05EF0345
    /*! \brief ��ɫֵ������
     *
     *  ��ֲʱҪ������Ļ����ɫ��ȸı�����͵Ķ���\n
     */
    typedef unsigned long           COLORVAL;

    // color define
    const COLORVAL COLOR_BLACK      = 0x000000;         /*!< \brief��ɫ */
    const COLORVAL COLOR_GRAY       = 0xc0c0c0;         /*!< \brief��ɫ */
    const COLORVAL COLOR_WHITE      = 0xffffff;         /*!< \brief��ɫ */
    const COLORVAL COLOR_DARKGRAY   = 0x808080;         /*!< \brief���ɫ */
    const COLORVAL COLOR_BLUE       = 0xbf0000;         /*!< \briefǳ��ɫ */
    const COLORVAL COLOR_BLUE1      = 0xff0000;         /*!< \brief��ɫ */
    const COLORVAL COLOR_RED        = 0x0000ff;         /*!< \brief��ɫ */
#elif defined(HAVE_LIBX11)
    typedef unsigned long           COLORVAL;

    // color define, set later
    extern COLORVAL COLOR_BLACK;
    extern COLORVAL COLOR_GRAY;
    extern COLORVAL COLOR_WHITE;
    extern COLORVAL COLOR_DARKGRAY;
    extern COLORVAL COLOR_BLUE;
    extern COLORVAL COLOR_BLUE1;
    extern COLORVAL COLOR_RED;
#endif /* WIN32 */
/*! @} */

const WORD TITLE_HEIGHT         = 20;       /*!< \brief ���ڱ���ĸ߶� */

const WORD BUTTON_UP_INTERVAL   = 1000;     /*!< \brief ��ť�ؼ�������ʱ���� */
const WORD EDIT_CURSOR_INTERVAL = 500;      /*!< \brief �༭�ؼ������˸��ʱ���� */
const WORD SCREEN_DRAW_INTERVAL = 50;       /*!< \brief ��Ļˢ�µ�ʱ���� */

/*! \defgroup Style ��� */
/*! @{ */

    /*! \defgroup General_Style ͨ�÷�� */
    /*! @{ */
const WORD GS_TRANSPARENT       = 0x8000;       /*!< \brief��λ���ñ�ʾΪ͸������Ԫ�� */
const WORD GS_FOCUS             = 0x4000;       /*!< \brief��λ���ñ�ʾΪ���㴰��Ԫ��\n��λΪϵͳ�ڲ�ʹ�ã��û������������� */
    /*! @} */

    /*! \defgroup Frame_Style �߿��� */
    /*! @{ */
const WORD FS_NONE              = 0x0001;       /*!< \brief���κα߿� */
const WORD FS_THIN              = 0x0002;       /*!< \briefϸ�߿� */
const WORD FS_RAISED            = 0x0004;       /*!< \brief͹��߿� */
const WORD FS_RECESSED          = 0x0008;       /*!< \brief�³��߿� */
const WORD FS_MASK              = 0x000f;       /*!< \brief�߿�������� */
    /*! @} */

    /*! \defgroup Text_Justification_Style �ı������� */
    /*! @{ */
const WORD TS_RIGHT             = 0x0010;       /*!< \brief�Ҷ��� */
const WORD TS_LEFT              = 0x0020;       /*!< \brief����� */
const WORD TS_CENTER            = 0x0040;       /*!< \brief���ж��� */
const WORD TS_MASK              = 0x0070;       /*!< \brief�ı������������ */
    /*! @} */

/*! @} */

#endif /* FISHGUI_H_HEADER_INCLUDED_C0B126F2 */

/*! @} */

