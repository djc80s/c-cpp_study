#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <fstream>

#include <iostream>
#include <QFile>
#include <QDir>

#include "App/appSetting.hpp"
#include "App/captureSetting.hpp"
#include "App/inspectionjob.h"
#include "App/dataGenerator.hpp"

#define MEASURED_OBJ_CNT 50 //测量对象数量

namespace App 
{
class MainWindow
{
public:

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //constructor & destructor

    MainWindow();
    virtual ~MainWindow();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //get and set function

    Job::InspectionData inspectionData() {return this->m_inspectionData;}

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //operate function

    /*
    *  @brief 加载captureSetting.ini文件
    *  @param path：文件路径
    *  @return NA
    */
    void loadCaptureSetting(const QString & path);

    /*
    *  @brief 加载appSetting.ini文件
    *  @param path：文件路径
    *  @return NA
    */
    void loadAppSetting(const QString & path);

    /*
    *  @brief 写程式到xml
    *  @param path：xml文件的路径
    *  @return NA
    */
    void writeToXml(const QString &path);

    /*
    *  @brief 加载程式所在文件
    *         1.如果有程式文件
    *         2.如果没有程式文件，生成默认程式文件
    *  @param
    *  @return
    */
    void loadJobFolder();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


private:

    AppSetting m_appSetting;
    CaptureSetting m_captureSetting;
    InspectionJob m_inspectionJob;
    DataGenerator m_dataGenrator;

    Job::InspectionData m_inspectionData;

    std::string m_defaultJobName{"HUAWEI_CA1204_RED"};
};
}

#endif // MAINWINDOW_HPP
