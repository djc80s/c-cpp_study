[TOC]

# 1.概述
项目名称:shownInspectionData    
项目创建时间: 2017-11-20     
项目创建人:grace     
项目概述:基于C++的模拟软件

## 1.1 工作需求
### 1.1.1 实现一个C++仿真APP程序，用法如下：
1、用QT打开代码，并运行
2、gcc -c -o 运行

### 1.1.2 要实现以下功能：

- 启动软件，加载AppSetting.ini和CaptureSetting.ini。    
1. AppSetting.ini不存在则生成默认文件，如果存在但参数有误则修改成默认配置参数。 2. CaptureSetting.ini不存在或者参数有误直接在屏幕打印出错信息并退出软件。
- 在2个配置都加载成功的基础上，扫描JobFolderPath目录下的程式
- 如果JobFolderPath没有文件的话，自动生成程序（包括内存中的数据结构）：
1. 生成50个Target，20个chip，30个ic，命名以"chip_xxx/ic_xxx"
2. 生成以下信息。  
   1. 软件的版本信息  
   2. 上次程式的编辑时间  
   3. 板子的名称，大小和原点  
   4. 所有的Target的名称，坐标位置，大小和角度信息    
- 如果JobFolderPath有文件的话，把文件全部在屏幕上列举出来，然后让用户选择
- 加载用户选择的程式
1. 如果是低版本则自动转换为高版本
- 读取成功后把所有的InspectionData信息在屏幕上打印出来
- 读取成功后把所有的InspectionData信息同时以xml格式输出
1. 输出到JobFolderPath，同名后缀名不同
2. 格式请参考BoardData.xml，调用使用Qt的XML库

```
<?xml version="1.0" encoding="UTF-8"?>
<DataVersion Value="312">
  <LastEditing Date="2017/04/01" Time="16:43:30" />
  <Board>
    <Board_001 SizeX="200.000" SizeY="111.000" SizeZ="1.600" Surface="  0" TbSideType="0" />
    <Board_002 />
    <Board_003 AutoLibMatch="  0" SkipNoComp="  0" PassMode="  0" />
    <Board_004 ResoX="0.018229" ResoY="0.018231" OriginX="0.000" OriginY="0.000" />
    <Board_005 PushUpUnit="  1" PuRiseTimer=" 0.0" PuDownTimer=" 0.0" OutBoardCheck="0" RackBoardSlot="0" StopNGCountMax="0" TableSpeed="  3" ConvTimer=" 0.0" />
    <Board_006 />
    <Board_007 UseXRayMode="0" UseXRayZoom="1" UseXRayNo="0" OffsetX="0.000" OffsetY="0.000" FirstCheckType="0" FirstCheckUnits="0" />
    <Board_008 ImageAutoSave="0" CollectionMax="50" UseRepair="0" ImageAutoDelete="0" />
    <Board_009 HeightPitchMode="1" ProductMode="0" BoardColor3D="0" />
  </Board>
```

