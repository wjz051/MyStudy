#coding=utf-8
#-------------------------
# 编译Qt代码
#-------------------------

import os

#Start--------------设置项---------------
#设置源代码项目路径
codeFilePath = 'E:/Code/'

#设置编译环境 x86 / x64
buildEnv = 'x86'

#设置编译类型 Debug / Release / Debug_And_Release
buildType = 'Debug_And_Release'

#设置Msvc2013 x86环境，即“vcvars32.bat”所在路径
msvcEnv32 = 'D:/Microsoft Visual Studio 12.0/VC/bin/'
#设置Msvc2013 x64环境，即“vcvars64.bat”所在路径
msvcEnv64 = 'D:/Microsoft Visual Studio 12.0/VC/bin/amd64/'

#设置Qt x86环境，即“qtenv2.bat”所在路径
qtEnv32 = 'D:/Qt5.5/Qt32/5.5/msvc2013/bin/'
#设置Qt x64环境，即“qtenv2.bat”所在路径
qtEnv64 = 'D:/Qt5.5/Qt64/5.5/msvc2013_64/bin/'

#End----------------设置项---------------

#Msvc运行环境批处理文件
batMsvc32 = 'vcvars32.bat'
batMsvc64 = 'vcvars64.bat'

#Qt运行环境批处理文件
batQt = 'qtenv2.bat'

#Msvc和Qt环境
msvcEnv = ''
batMsvc = ''
qtEnv = ''
if (buildEnv == 'x86'):
    msvcEnv = msvcEnv32
    batMsvc = batMsvc32
    qtEnv = qtEnv32
elif (buildEnv == 'x64'):
    msvcEnv = msvcEnv64
    batMsvc = batMsvc64
    qtEnv = qtEnv64
else:
    print('buildEnv 设置值为 x86 / x64，请重新选择')
    quit

# 编译类型
qmakeConfig = ''
if (buildType == 'Debug'):
    qmakeConfig = 'debug'
elif (buildType == 'Release'):
    qmakeConfig = 'release'
elif (buildType == 'Debug_And_Release'):
    qmakeConfig = '"debug_and_release build_all"'
else:
    print ('buildType 设置值为 Debug / Release / Debug_And_Release')
    quit

#Msvc的“vcvars32.bat”文件所在磁盘
tmpDir = msvcEnv.split(':')
msvcDir = tmpDir[0] + ':'

#Qt的“qtenv2.bat”文件所在磁盘
tmpDir = qtEnv.split(':')
qtDir = tmpDir[0] + ':'

#源代码项目所在磁盘
tmpDir = codeFilePath.split(':')
codeDir = tmpDir[0] + ':'

#编译命令
cmd_Build = '''%s & \
cd %s & \
%s & \
%s & \
cd %s & \
%s & \
%s & \
cd %s & \
qmake & \
qmake CONFIG+=%s & \
nmake & \
nmake clean & \
''' % (msvcDir, msvcEnv, batMsvc, qtDir, qtEnv, batQt, codeDir, codeFilePath, qmakeConfig)

#删除Makefile文件
def rmMakefile(rootDir):
    for fileName in os.listdir(rootDir):
        pathName = os.path.join(rootDir, fileName)
        if (os.path.isfile(pathName)):
            if (fileName.startswith('Makefile')):
                os.remove(pathName)
        else:
            rmMakefile(pathName)

print(cmd_Build)
# #删除Makefile文件
# rmMakefile(codeFilePath)
# #执行编译
# os.system(cmd_Build)
# #编译完成后删除Makefile文件
# rmMakefile(codeFilePath)