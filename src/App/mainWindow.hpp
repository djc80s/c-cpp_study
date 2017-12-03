#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <iostream>
#include <QFile>
#include <QDir>

#include "DB/sqlitedb.hpp"

#include "App/appSetting.hpp"
#include "App/captureSetting.hpp"
#include "Job/inspectionData.hpp"

#define MEASURED_OBJ_CNT 50 //测量对象数量

namespace App 
{
class MainWindow
{
public:

    MainWindow();
    virtual ~MainWindow();

    Job::InspectionData inspectionData() {return this->m_inspectionData;}

    void loadCaptureSetting(const QString & path);
    void loadAppSetting(const QString & path);
    void loadJobFolder(const QString & path);
    void writeToDB(std::string path);
//    void loadInspectionData(const QString & path);

private:

    AppSetting m_appSetting;
    CaptureSetting m_captureSetting;
    Job::InspectionData m_inspectionData;

};
}

#endif // MAINWINDOW_HPP
