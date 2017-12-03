#include "mainWindow.hpp"

namespace App 
{

MainWindow::MainWindow()
{
    
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::loadCaptureSetting(const QString & path)
{
    this->m_captureSetting.load(path);
}

void MainWindow::loadAppSetting(const QString & path)
{
    this->m_appSetting.load(path);
}

void MainWindow::loadJobFolder(const QString &path)
{

}

void MainWindow::writeToDB(std::string path)
{
    SSDK::DB::SqliteDB sqlite(path);
        try
        {
            auto isOpened = sqlite.isOpened();
            if(isOpened)
            {
                std::string Version{"V1"};
                std::string LastEditingTime{'\0'};
                //>>>----------------------------------------------------------------------------------------------------------
                //1.读取版本号
                std::string selectedString = "select Version from Job";
                sqlite.prepare(selectedString);
                Version = sqlite.executeScalar<std::string>(selectedString);
                if(Version!="V1")
                {
                    THROW_EXCEPTION("读取程序的版本不对，读取中止");
                }
                this->m_inspectionData.setVersion(Version);

                //2.读取最后检测时间
                selectedString = "select lastEditTime from Job";
                sqlite.prepare(selectedString);
                LastEditingTime = sqlite.executeScalar<std::string>(selectedString);
                this->m_inspectionData.setLastEditingTime(LastEditingTime);

                //>>>----------------------------------------------------------------------------------------------------------
                //3.读取Board表
                selectedString = "select * from Board";
                bool ret = sqlite.prepare(selectedString);
                ret = sqlite.begin();

                while(true)
                {
                    sqlite.step();
                    if (sqlite.latestErrorCode() == SQLITE_DONE)
                    {
                        break;
                    }

                    //创建具体的对象
                    this->m_inspectionData.board().setName(boost::get<std::string>(sqlite.columnValue(0)));
                    this->m_inspectionData.board().setSizeX(boost::get<double>(sqlite.columnValue(1)));
                    this->m_inspectionData.board().setSizeY(boost::get<double>(sqlite.columnValue(2)));
                    this->m_inspectionData.board().setOriginalX(boost::get<double>(sqlite.columnValue(3)));
                    this->m_inspectionData.board().setOriginalY(boost::get<double>(sqlite.columnValue(4)));
                }

                //4.读取measuredObjs表
                selectedString = "select * from MeasuredObjs";
                ret = sqlite.prepare(selectedString);
                ret = sqlite.begin();

                while(true)
                {
                    sqlite.step();
                    if (sqlite.latestErrorCode() == SQLITE_DONE)
                    {
                        break;
                    }

                    //创建具体的对象
                    this->m_inspectionData.board().setName(boost::get<std::string>(sqlite.columnValue(0)));
                    this->m_inspectionData.board().setSizeX(boost::get<double>(sqlite.columnValue(1)));
                    this->m_inspectionData.board().setSizeY(boost::get<double>(sqlite.columnValue(2)));
                    this->m_inspectionData.board().setOriginalX(boost::get<double>(sqlite.columnValue(3)));
                    this->m_inspectionData.board().setOriginalY(boost::get<double>(sqlite.columnValue(4)));
                }



                sqlite.reset();
                sqlite.close();
            }
        }
        catch(const SDK::CustomException& ex)
        {
            std::cout << ex.what() << std::endl;
            if(sqlite.isOpened())
            {
                sqlite.reset();
                sqlite.close();
            }
        }
    }
}

//void MainWindow::loadInspectionData(const QString &path)
//{

//}

//}
