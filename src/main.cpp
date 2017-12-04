#include <iostream>

#include "Job/measuredObj.hpp"
#include "Job/inspectionData.hpp"
#include "Job/board.hpp"

#include "App/dataGenerator.hpp"
#include "App/mainWindow.hpp"
#include "SDK/customException.hpp"

#define MEASURED_OBJ_CNT 50 //测量对象数量

using namespace std;

int main()
{
    Job::Board board;
    Job::MeasuredObjList objList;
    Job::MeasuredObj measuredObj[MEASURED_OBJ_CNT]={};

    App::DataGenerator data;
    App::MainWindow mainWindow;

    //加载配置文件
    try{

        mainWindow.loadAppSetting("./AppConfig/AppSetting.ini");
        mainWindow.loadCaptureSetting("./HardwareConfig/CaptureSetting.ini");
    }
    catch(SDK::CustomException& ex)
    {
        //调用堆栈信息, 文件、行数、调用函数等信息
        cout <<"配置文件加载失败："<< ex.what() <<endl;
    }

    //    data.generateObjsRandomly(MEASURED_OBJ_CNT,measuredObj);

    //    for (int i = 0; i < MEASURED_OBJ_CNT; ++i)
    //    {
    //        objList.pushTailNode(&measuredObj[i]);
    //    }

    //    board.setMeasuredObjList(objList);

    //    Job::InspectionData xmlData;
    //    xmlData.setBoard(board);
    //    xmlData.writeToXml("grCp.xml");

    return 0;
}
