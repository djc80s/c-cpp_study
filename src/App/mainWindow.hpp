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

    Job::InspectionData &inspectionData() {return this->m_inspectionData;}

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
    void writeInspectionDataToXml(const std::string &filename);

    /*
    *  @brief 加载程式所在文件
    *  @param
    *  @return string : 1.如果有程式文件,返回程式文件名
    *                   2.如果没有程式文件,返回空字符串
    */
    std::string loadJobFolder();

    /*
    *  @brief 生成默认程式
    *  @param
    *  @return
    */
    void generatDefaultJob(std::string JobName);

    /*
    *  @brief  将加载的程式输出到终端
    *  @param
    *  @return
    */
    void printToConsle();

    /*
    *  @brief  加载Appsetting目录下的指定检测程式
    *  @param  filename: 程式的名称
    *  @return
    */
    void loadJobToInspectionData(std::string &filename);

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


private:

    AppSetting m_appSetting;
    CaptureSetting m_captureSetting;

    InspectionJob m_inspectionJob;
    DataGenerator m_dataGenrator;

    Job::InspectionData m_inspectionData;
};
}

#endif // MAINWINDOW_HPP
