# FishGui
备份王咏武大神的FishGui方便后面配合《道法自然》研究设计模式

以下为原作者的README

--------------------------------------------------------------
## FishGUI的安装和使用
## 下载
&nbsp;&nbsp;&nbsp;&nbsp;FishGUI系统的所有UML模型文件、文档、源代码和相关说明文件可以从网上直接下载。
网址是：http://www.contextfree.net/wangyw/ooguide/

&nbsp;&nbsp;&nbsp;&nbsp;FishGUI系统的所有UML模型文件、文档、源代码和相关说明文件被打包在一个名为
fishgui-1.0.0.tar.gz的压缩文件中（本书中提及的其他示例代码被打包在一个名为ooguide-examples-1.0.0.tar.gz的压缩文件中，使用方法请参见本书各章节内的相关说明）。

## 解压
&nbsp;&nbsp;&nbsp;&nbsp;在Windows系统中，可以使用WinRAR 3.0或以上版本，直接解压缩fishgui-1.0.0.tar.gz，所有相关文件都会被解压到名为FishGUI的目录内。  
&nbsp;&nbsp;&nbsp;&nbsp;在UNIX或Linux系统中，可以用如下命令解压fishgui-1.0.0.tar.gz（系统中应已安装
tar和gzip工具），所有相关文件都会被解压到名为FishGUI的目录内：

&nbsp;&nbsp;&nbsp;&nbsp;tar xvfz fishgui-1.0.0.tar.gz

### 目录结构
&nbsp;&nbsp;&nbsp;&nbsp;解压后，FishGUI系统的目录结构如下：

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FishGUI&nbsp;&nbsp;&nbsp;&nbsp;// 主目录  
　　├─Design  &nbsp;&nbsp;&nbsp;&nbsp;// Rose模型文件  
　　├─Doc	&nbsp;&nbsp;&nbsp;&nbsp;// FishGUI文档目录  
　　│  └─html				&nbsp;&nbsp;&nbsp;&nbsp;// HTML格式的设计文档  
　　├─MVC_Win32				&nbsp;&nbsp;&nbsp;&nbsp;// WIN32平台MVC示例应用程序的项目文件  
　　├─MVC_X11				&nbsp;&nbsp;&nbsp;&nbsp;// X11平台MVC示例应用程序的项目文件  
　　├─Source				&nbsp;&nbsp;&nbsp;&nbsp;// FishGUI源代码目录  
　　│  ├─Application			&nbsp;&nbsp;&nbsp;&nbsp;// 应用层（FishGUIDemo）源代码  
　　│  ├─Framework			&nbsp;&nbsp;&nbsp;&nbsp;// 框架层源代码  
　　│  ├─MVC_Application		&nbsp;&nbsp;&nbsp;&nbsp;// MVC示例应用程序源代码  
　　│  ├─OSAdaptor			&nbsp;&nbsp;&nbsp;&nbsp;// 操作系统适配层源代码  
　　│  ├─OSStartup			&nbsp;&nbsp;&nbsp;&nbsp;// 各操作系统的主函数源代码  
　　│  └─Utility			&nbsp;&nbsp;&nbsp;&nbsp;// 应用包源代码  
　　├─Win32				&nbsp;&nbsp;&nbsp;&nbsp;// WIN32平台项目文件  
　　├─Win32_Bmp				&nbsp;&nbsp;&nbsp;&nbsp;// WIN32平台下使用的位图文件  
　　├─X11				&nbsp;&nbsp;&nbsp;&nbsp;// X11平台项目文件  
　　└─X11_Xpm				&nbsp;&nbsp;&nbsp;&nbsp;// X11平台下使用的位图文件  

在FishGUI的主目录下，各子目录的具体内容分别为：  
1. Design目录下，以Rose格式保存了FishGUI框架系统的分析模型和设计模型，该模型文件可以用Rational Rose 2002或以上版本浏览。
2. Doc目录下是FishGUI框架系统的设计文档，该文档利用Doxygen文档生成工具（Doxygen 1.3.6），借助FishGUI源代码自动生成。
3. MVC_Win32目录中是利用FishGUI框架系统实现的MVC示例应用程序（参见“MVC模式”一章）在WIN32系统下的项目文件（包括Visual Studio 6.0和Visual Studio .NET格式）。
4. MVC_X11目录是MVC示例应用程序在X11系统下的项目文件。
5. Source目录包括FishGUI框架系统的源代码。其中Source\Application目录包括应用层（即示例应用程序FishGUIDemo）的源代码，Source\Framework目录包括FishGUI的核心框架层的源代码，Source\MVC_Application目录包括了MVC示例应用程序的源代码，Source\OSAdaptor目录包括操作系统适配层的源代码，Source\OSStartup目录包括操作系统相关的启动源代码，Source\Utility目录包括应用包的源代码。各层的职责请参见书中的详细描述。
6. Win32目录中是示例应用程序FishGUIDemo在WIN32系统下的项目文件（包括Visual Studio 6.0和Visual Studio .NET格式）。
7. Win32_Bmp目录中是WIN32系统下的位图文件。
8. X11目录中是示例应用程序FishGUIDemo在X11系统下的项目文件。
9. X11_Xpm目录中是X11系统下的位图文件。 

### 编译运行

&nbsp;&nbsp;&nbsp;&nbsp;目前，FishGUI框架系统的源码可以在Windows、Linux、UNIX这三种主要的操作系统上
编译运行。具体来说：  
1. 对于WIN32平台，我们在Windows 2000和Windows XP操作系统中进行过测试。理论上，FishGUI也应支持Windows 98/Me和Windows Server 2003等WIN32平台。编译和运行FishGUI前，系统中应已安装Visual Studio 6.0或Visual Studio .NET 2003（或更高版本）。
2. 对于UNIX或Linux平台，我们在Red Hat Linux 9.0和Solaris 8.0操作系统中进行过测试。理论上，FishGUI也应支持其他类型的UNIX或Linux平台。编译和运行FishGUI前，UNIX或Linux系统中应已安装有X11图形环境及其开发库、Xpm位图显示库、gcc 3.2.2或更高版本，以及make、tar和gzip工具。

&nbsp;&nbsp;&nbsp;&nbsp;在Windows系统中编译运行FishGUI的示例应用程序FishGUIDemo的步骤是：
1. 启动Visual Studio 6.0，通过File/Open Workspace菜单打开示例应用程序FishGUIDemo的项目文件FishGUI\Win32\FishGUI.dws；或启动Visual Studio .NET，通过File/Open/Project菜单打开示例应用程序FishGUIDemo的项目文件FishGUI\Win32\FishGUI.sln。
2. 直接在Visual Studio 6.0或Visual Studio .NET中编译运行。

&nbsp;&nbsp;&nbsp;&nbsp;在Windows系统中编译运行FishGUI的MVC示例应用程序的步骤是：
1. 启动Visual Studio 6.0，通过File/Open Workspace菜单打开示例应用程序FishGUIDemo的项目文件FishGUI\MVC_Win32\FishGUI.dws；或启动Visual Studio .NET，通过File/Open/Project菜单打开示例应用程序FishGUIDemo的项目文件FishGUI\MVC_Win32\FishGUI.sln。
2. 直接在Visual Studio 6.0或Visual Studio .NET中编译运行。

&nbsp;&nbsp;&nbsp;&nbsp;在UNIX或Linux中编译运行示例应用程序FishGUIDemo的步骤为：
1. 在系统控制台界面，用“cd”命令进入FishGUI/X11目录。
2. 键入“./configure”命令，检查系统配置，如果系统配置可满足要求，X11目录内会自动生成Makefile文件。如果报告下面的错误，则表示X11库或Xpm库未安装：  大多数支持图形用户界面的UNIX或Linux系统发布时均带有X11和Xpm库。如果X11或Xpm库未安装，请首先安装X11和Xpm库。如果系统未提供Xpm库，大家可以从网址http://koala.ilog.fr/lehors/xpm.html下载Xpm库，并根据该网址上的相关说明安装Xpm库。

    >configure: error: Cannot Find X11 Library!\
    >configure: error: Cannot Find Xpm Library!\
    >configure: error: CannotFind Xpm Include File!\


3. 键入“make”命令，编译生成应用程序。如果编译正确完成，X11目录下会生成可
　　　　　执行程序FishGUI。这时，可直接键入“./FishGUI”命令运行程序。

&nbsp;&nbsp;&nbsp;&nbsp;在UNIX或Linux中编译运行MVC示例应用程序的步骤为：
1. 在系统控制台界面，用“cd”命令进入FishGUI/MVC_X11目录。
2. 键入“./configure”命令，检查系统配置，如果系统配置可满足要求，X11目录内会自动生成Makefile文件。如果报告下面的错误，则表示X11库或Xpm库未安装：  大多数支持图形用户界面的UNIX或Linux系统发布时均带有X11和Xpm库。如果X11或Xpm库未安装，请首先安装X11和Xpm库。如果系统未提供Xpm库，大家可以从网址http://koala.ilog.fr/lehors/xpm.html下载Xpm库，并根据该网址上的相关说明安装Xpm库。

    >configure: error: Cannot Find X11 Library!\
    >configure: error: Cannot Find Xpm Library!\
    >configure: error: CannotFind Xpm Include File!\
　　　　
3. 键入“make”命令，编译生成应用程序。如果编译正确完成，MVC_X11目录下会生成可执行程序FishGUI。这时，可直接键入“./FishGUI”命令运行程序。

### 安装注意事项
&nbsp;&nbsp;&nbsp;&nbsp;对于FishGUI的示例应用程序，用户可以在编译后直接运行，可以将完整的FishGUI目
录复制到其他位置运行，也可以在桌面建立指向应用程序的快捷方式。我们没有为FishGUI及其示例程序提供专门的安装程序。但在复制和运行FishGUI示例应用程序时，还有一些需要注意的事情：
1. 在WIN32系统下，代码用GetModuleFileName()函数获得可执行程序的绝对路径，并通过在绝对路径中搜索字符串“FishGUI”定位FishGUI的主目录，然后在FishGUI\Win32_Bmp中寻找位图文件。因此，只要保证FishGUI的目录结构不变，编译生成的Debug或Release版本应用程序就既可以在Visual Studio中直接运行，也可以通过资源管理器或快捷方式运行。如果用户希望把可执行程序安装到其他计算机上，只要把编译后的FishGUI目录拷贝到目标计算机就可以了。
2. 在支持X11的UNIX或Linux系统下，代码通过获取当前目录和命令行参数的办法得到FishGUI主目录的绝对路径，然后在FishGUI/X11_Xpm中寻找位图文件。但这种方法并不能保证在所有UNIX或Linux操作系统下都可行。因此，代码也可以从环境变量HOME_FISHGUI中得到FishGUI主目录的绝对路径。在我们测试过的Red hat Linux 9.0和Solaris 8.0系统中，有如下两种情况：在Red hat Linux 9.0中，无需设置环境变量，用户既可以在控制台或资源管理器中直接运行，也可以在桌面上创建快捷方式，通过快捷方式运行；在Solaris 8.0中，通过控制台直接运行时，FishGUI能正确地找到位图文件，但通过快捷方式运行时，无法得到FishGUI主目录的绝对路径，找不到位图文件，这时，只要把环境变量HOME_FISHGUI设置为FishGUI主目录的绝对路径，就能正确运行示例程序了。也就是说，在UNIX或Linux系统中，如果用户希望把可执行程序安装到其他计算机上运行，也要把编译后的FishGUI目录拷贝到目标计算机，并在必要时设置环境变量HOME_FISHGUI。

Rose模型

&nbsp;&nbsp;&nbsp;&nbsp;FishGUI\Design中的Rose模型FishGUI.mdl需要使用Rational Rose 2002或更高版本打
开。该模型并不是一个完整的设计模型，它只包括了本书中用到的一些用例图和交互图。\
&nbsp;&nbsp;&nbsp;&nbsp;其中，Use Case View是本书中用到的一些用例图和用例描述，Logical View的Analysis Model中包括本书涉及到的分析模型，Design Model中包括FishGUI系统的架构图、详细的类图（包括应用层、框架层、操作系统适配层和应用包）以及部分用例实现的交互图，Component View是用于生成C++代码的应用层、框架层、操作系统适配层和应用包的部件定义。

### 文档

&nbsp;&nbsp;&nbsp;&nbsp;FishGUI\Doc中是利用Doxygen文档生成工具为FishGUI框架系统生成的文档。用户可以
用浏览器打开FishGUI\Doc\html\index.htnl，以浏览该文档的内容。该文档由下面几部分
组成：

1. 文档首页：包含了FishGUI框架系统的简介和版权信息。
2. 文件列表：包含了FishGUI源代码中所有文件的列表，通过该列表可以直接浏览某个文件中定义的类、宏、变量等，也可以直接浏览某个文件中的源代码。
3. 组合类型列表：列出了FishGUI系统中所有的类、结构、联合以及接口的定义。通过该列表可以浏览某个类的简要介绍、继承关系图、包括关联和继承关系的详细类图、类中的所有成员及其简要介绍、复杂成员函数的调用关系图等等。
4. 类继承关系：按字典顺序列出了系统中的类及其继承关系。
5. 组合类型成员：按字典顺序列出了所有类、结构、联合的成员。
6. 模块：列出了FishGUI框架系统的四个模块（应用包、操作系统适配层、框架层、应用层），以及属于每一个模块的文件、宏定义、类、枚举、函数、变量等各种元素。
7. 文件成员：按照字母顺序列出了不属于类、结构或联合的全局函数、变量、类型定义、枚举、宏定义等元素。
8. 类继承关系图：以图形的方式列出了系统中的类及其继承关系。\

　　
&nbsp;&nbsp;&nbsp;&nbsp;不同类型的文档之间有丰富的链接，因此，从不同类型的文档出发都可以在整个文档
中随意浏览。这份文档是用户查考FishGUI中各要素功用及结构的主要依据。

### 移植步骤

&nbsp;&nbsp;&nbsp;&nbsp;关于FishGUI框架系统在不同操作系统间移植的原理，请参阅书中的详细描述，特别是参阅“外观模式”、“观察者模式”、“单件类”和“适配器模式”等章节。这里再把移植时需要做的工作总结一下（假设我们要将FishGUI移植到Xxx操作系统上）：

1. 修改FishGUI\Utility\FG_Common.h文件，该文件中包括若干个和系统相关的类型及变量定义，移植时需要改变：屏幕宽度和高度：常量SCREEN_WIDTH和SCREEN_HEIGHT；颜色的类型：类型定义COLORVAL，根据物理屏幕的颜色深度，该类型可以定义为unsigned long、unsigned short或unsigned char；COLOR_BLACK、COLOR_GRAY、COLOR_WHITE等颜色值的常量定义。
2. 添加具体的操作系统适配器和绘图接口类，这包括：在FishGUI\OSAdaptor目录中添加FG_XxxAdaptor.h、FG_XxxAdaptor.h、FG_XxxDrawInterface.h、FG_XxxDrawInterface.cpp等文件，操作系统适配器和绘图接口类的具体实现方法请参考“外观模式”和“适配器模式”等章节的详细描述；在FishGUI\OSAdaptor\FG_OSAdaptor.cpp中添加对于新的操作系统适配器类的实例化过程，即通过定义不同操作系统的宏来决定实例化哪一个具体的操作系统适配器类（参见“单件类”一章）。
3. 仿照FishGUI\Source\OSStartup内的WinMain.cpp或main.cpp的样子，编写该系统下的启动函数，放在FishGUI\Source\OSStartup目录下。
4. 添加一个项目文件目录，如FishGUI\Xxx，为FishGUIDemo建立该系统下的项目文件，用于编译、生成可执行程序。\

　　
&nbsp;&nbsp;&nbsp;&nbsp;只要完成了上面这几个步骤，并且正确地实现了操作系统适配器和绘图接口类，我们
就能看到FishGUIDemo应用程序在Xxx操作系统中的正确运行结果了。

