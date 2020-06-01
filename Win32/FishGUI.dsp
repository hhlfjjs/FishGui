# Microsoft Developer Studio Project File - Name="FishGUI" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=FishGUI - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "FishGUI.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "FishGUI.mak" CFG="FishGUI - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "FishGUI - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "FishGUI - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "FishGUI - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "FishGUI - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "FishGUI - Win32 Release"
# Name "FishGUI - Win32 Debug"
# Begin Group "OS Startup Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\Source\OSStartup\WinMain.cpp
# End Source File
# End Group
# Begin Group "FishGUI OSAdaptor Source files"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\Source\OSAdaptor\FG_OSAdaptor.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\OSAdaptor\FG_Win32Adaptor.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\OSAdaptor\FG_Win32DrawInterface.cpp
# End Source File
# End Group
# Begin Group "FishGUI OSAdaptor Header files"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\Source\OSAdaptor\FG_OSAdaptor.h
# End Source File
# Begin Source File

SOURCE=..\Source\OSAdaptor\FG_OSDrawInterface.h
# End Source File
# Begin Source File

SOURCE=..\Source\OSAdaptor\FG_Win32Adaptor.h
# End Source File
# Begin Source File

SOURCE=..\Source\OSAdaptor\FG_Win32DrawInterface.h
# End Source File
# End Group
# Begin Group "FishGUI Utility Source files"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\Source\Utility\FG_Rect.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Utility\FG_String.cpp
# End Source File
# End Group
# Begin Group "FishGUI Utility Header files"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\Source\Utility\FG_Common.h
# End Source File
# Begin Source File

SOURCE=..\Source\Utility\FG_List.h
# End Source File
# Begin Source File

SOURCE=..\Source\Utility\FG_Message.h
# End Source File
# Begin Source File

SOURCE=..\Source\Utility\FG_OSMsgObserver.h
# End Source File
# Begin Source File

SOURCE=..\Source\Utility\FG_Point.h
# End Source File
# Begin Source File

SOURCE=..\Source\Utility\FG_Rect.h
# End Source File
# Begin Source File

SOURCE=..\Source\Utility\FG_String.h
# End Source File
# Begin Source File

SOURCE=..\Source\Utility\FG_Utility.h
# End Source File
# End Group
# Begin Group "FishGUI Framework Source files"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\Source\Framework\FG_Application.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Bitmap.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Button.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_CheckBox.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Container.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Edit.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Group.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_KeyMap.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Label.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_MsgMap.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Object.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_RadioButton.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Screen.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_TextWidget.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_TimerManager.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Widget.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Window.cpp
# End Source File
# End Group
# Begin Group "FishGUI Framework Header files"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\Source\Framework\FG_Application.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Bitmap.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Button.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_CheckBox.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Container.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Edit.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Factory.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Framework.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Group.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_KeyMap.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Label.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Model.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_MsgMap.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Object.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_RadioButton.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Screen.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_TextWidget.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_TimerManager.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Widget.h
# End Source File
# Begin Source File

SOURCE=..\Source\Framework\FG_Window.h
# End Source File
# End Group
# Begin Group "FishGUI Application Source files"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\Source\Application\MainWindow.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Application\MyApp.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Application\MyButton.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Application\Win1.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Application\Win2.cpp
# End Source File
# End Group
# Begin Group "FishGUI Application Header files"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\Source\Application\MainWindow.h
# End Source File
# Begin Source File

SOURCE=..\Source\Application\MyApp.h
# End Source File
# Begin Source File

SOURCE=..\Source\Application\MyButton.h
# End Source File
# Begin Source File

SOURCE=..\Source\Application\MyFactory.h
# End Source File
# Begin Source File

SOURCE=..\Source\Application\Win1.h
# End Source File
# Begin Source File

SOURCE=..\Source\Application\Win2.h
# End Source File
# End Group
# End Target
# End Project
