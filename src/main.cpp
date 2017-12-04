#include <iostream>

#include <QDir>

#include "SDK/customException.hpp"

#include "Job/measuredObj.hpp"
#include "Job/inspectionData.hpp"
#include "Job/board.hpp"
#include "Job/measuredObjList.hpp"

#include "App/dataGenerator.hpp"
#include "App/appSetting.hpp"
#include "App/captureSetting.hpp"
#include "App/mainWindow.hpp"
#include "SDK/customException.hpp"

#define MEASURED_OBJ_CNT 50 //测量对象数量

using namespace std;

int main()
{
    Job::Board board;
    Job::MeasuredObjList objList;
    Job::MeasuredObj measuredObj[MEASURED_OBJ_CNT]={};
    try
    {
        QString appSettingPath = "./Ini/appSetting.ini";
        QString captureSettingPath = "./Ini/captureSetting.ini";

    App::DataGenerator data;
        App::MainWindow mainWindow;

    //加载配置文件
    try{
        mainWindow.loadAppSetting("./AppConfig/AppSetting.ini");
        mainWindow.loadCaptureSetting("./HardwareConfig/CaptureSetting.ini");
    }
    catch(const SDK::CustomException& ex)
    {
        cout <<"配置文件加载失败："<< ex.what() <<endl;
    }

    return 0;
}
