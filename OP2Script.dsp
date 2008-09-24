# Microsoft Developer Studio Project File - Name="OP2Script" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=OP2Script - Win32 Release MinSize
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "OP2Script.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "OP2Script.mak" CFG="OP2Script - Win32 Release MinSize"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "OP2Script - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinSize"
# PROP BASE Intermediate_Dir "ReleaseMinSize"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinSize"
# PROP Intermediate_Dir "ReleaseMinSize"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib advapi32.lib shell32.lib ..\lib\libctiny.lib ..\lib\op2.lib /nologo /base:"0x11000000" /subsystem:windows /dll /machine:I386 /nodefaultlib:"libcmt.lib"
# SUBTRACT LINK32 /pdb:none
# Begin Target

# Name "OP2Script - Win32 Release MinSize"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Main.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BaseData.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "Outpost2DLL"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\Outpost2DLL\Enumerators.h
# End Source File
# Begin Source File

SOURCE=..\Outpost2DLL\Enums.h
# End Source File
# Begin Source File

SOURCE=..\Outpost2DLL\Functions.h
# End Source File
# Begin Source File

SOURCE=..\Outpost2DLL\Groups.h
# End Source File
# Begin Source File

SOURCE=..\Outpost2DLL\MapIdEnum.h
# End Source File
# Begin Source File

SOURCE=..\Outpost2DLL\NonExportedEnums.h
# End Source File
# Begin Source File

SOURCE=..\Outpost2DLL\Outpost2DLL.h
# End Source File
# Begin Source File

SOURCE=..\Outpost2DLL\Player.h
# End Source File
# Begin Source File

SOURCE=..\Outpost2DLL\RequiredExports.h
# End Source File
# Begin Source File

SOURCE=..\Outpost2DLL\Structs.h
# End Source File
# Begin Source File

SOURCE=..\Outpost2DLL\TethysGame.h
# End Source File
# Begin Source File

SOURCE=..\Outpost2DLL\Units.h
# End Source File
# End Group
# Begin Group "OP2Helper"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\OP2Helper\BaseBuilder.cpp
# End Source File
# Begin Source File

SOURCE=..\OP2Helper\BaseBuilder.h
# End Source File
# Begin Source File

SOURCE=..\OP2Helper\EnumSoundID.h
# End Source File
# Begin Source File

SOURCE=..\OP2Helper\EnumTechID.h
# End Source File
# Begin Source File

SOURCE=..\OP2Helper\OP2Helper.cpp
# End Source File
# Begin Source File

SOURCE=..\OP2Helper\OP2Helper.h
# End Source File
# End Group
# End Target
# End Project
