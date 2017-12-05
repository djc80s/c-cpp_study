#ifndef INSPECTIONJOB_H
#define INSPECTIONJOB_H

#include <fstream>

#include <iostream>
#include <QFile>
#include <QDir>

#include "DB/sqlitedb.hpp"
#include "Job/inspectionData.hpp"
#include "SDK/customException.hpp"

namespace App
{
class InspectionJob
{
public:
    InspectionJob();
    virtual ~InspectionJob();

    /*
    *  @brief 将inspectionData存入数据库Job文件中
    *  @param path：写程式所在路径
    *  @return NA
    */
    void saveJob(Job::InspectionData& inspectionData, std::string path);

    /*
    *  @brief 将数据库格式Job文件加载到inspectionData数据结构中
    *  @param path:读的程式所在路径
    *  @return
    */
    void readJob(Job::InspectionData& inspectionData, std::string path);
};
}

#endif // INSPECTIONJOB_H
