#include <iostream>

#include "App/dataGenerator.hpp"
#include "Job/measuredObj.hpp"
#include "Job/inspectionData.hpp"
#include "Job/board.hpp"

#define MEASURED_OBJ_CNT 50 //测量对象数量

using namespace std;

int main()
{
    Job::Board board;
    App::DataGenerator data;
    Job::MeasuredObjList objList;
    Job::MeasuredObj measuredObj[MEASURED_OBJ_CNT]={};
    data.generateObjsRandomly(MEASURED_OBJ_CNT,measuredObj);

    for (int i = 0; i < MEASURED_OBJ_CNT; ++i)
    {
        objList.pushTailNode(&measuredObj[i]);
    }

    board.setMeasuredObjList(objList);

    Job::InspectionData xmlData;
    xmlData.setBoard(board);
    xmlData.writeToXml("grCp.xml");

    return 0;
}
