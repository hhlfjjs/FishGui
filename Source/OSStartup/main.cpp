/*--------------------------------------------------------------------------

	main.cpp - X11ϵͳ������UNIX��LINUX���������ļ�

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
/*! \file 
 *  \brief X11ϵͳ������UNIX��LINUX���������ļ�
 */

#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlocale.h>
#include <../Source/OSAdaptor/FG_X11Adaptor.h>

/*! \brief main:
 *
 *  \param argc 
 *  \param argv 
 *  \return  
 */
main(int argc, char ** argv)
{
    if (setlocale(LC_CTYPE, "") == NULL)
    {
  	    fprintf (stderr, "System cannot set locale\n");
  	    exit(0);
  	}
    if (! XSupportsLocale())
    {
  	    fprintf (stderr, "X does not support locale\n");
  	    exit(0);
  	}
    if (XSetLocaleModifiers("") == NULL)
    {
  	    fprintf (stderr, "Cannot set input modifiers\n");
  	    exit(0);
  	}

    FG_X11Adaptor * pAdp = (FG_X11Adaptor *)FG_GetAdaptor();
    
    pAdp->SetXpmPath(argv[0]);
    
    pAdp->Run();
}

