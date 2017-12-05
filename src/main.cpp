#include <iostream>

#include "SDK/customException.hpp"
#include "App/mainWindow.hpp"

using namespace std;

int main()
{
    string selectedJobName;
    string defaultJobname = "ZTE_CA1524_Black";
    try
    {
        App::MainWindow mainWindow;

        //加载配置文件
        mainWindow.loadAppSetting("./AppConfig/AppSetting.ini");
        mainWindow.loadCaptureSetting("./HardwareConfig/CaptureSetting.ini");

        //尝试加载程式目录
        selectedJobName = mainWindow.loadJobFolder();

        if( "" == selectedJobName )
        {
            mainWindow.generatDefaultJob(defaultJobname);
            //再次加载程式文件选择界面
            selectedJobName = mainWindow.loadJobFolder();
        }

        //加载选中的程式
        mainWindow.loadJobToInspectionData(selectedJobName);

        //写出将InspectionData写出为xml文件
        mainWindow.writeInspectionDataToXml(selectedJobName);

        //将InspectionData输出到界面显示
        mainWindow.printToConsle();
    }
    catch(const SDK::CustomException& ex)
    {
        cout <<"MainWindow错误："<< ex.what() <<endl;
    }

    return 0;
}
