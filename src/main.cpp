#include <iostream>

#include <QDir>

#include "SDK/customException.hpp"

#include "App/appSetting.hpp"
#include "App/captureSetting.hpp"
#include "App/mainWindow.hpp"

#define MEASURED_OBJ_CNT 50 //测量对象数量

using namespace std;

int main()
{
    try
    {
        App::MainWindow mainWindow;

        //加载配置文件
        mainWindow.loadAppSetting("./AppConfig/AppSetting.ini");
        mainWindow.loadCaptureSetting("./HardwareConfig/CaptureSetting.ini");

        //展示操作目录下的程式
        mainWindow.loadJobFolder();
    }
    catch(const SDK::CustomException& ex)
    {
        cout <<"MainWindow错误："<< ex.what() <<endl;
    }

    return 0;
}
