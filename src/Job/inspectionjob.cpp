#include "inspectionjob.h"

InspectionJob::InspectionJob()
{

}

void Job::InspectionJob::createJob(std::string path)
{
    try
    {
        SSDK::DB::SqliteDB v1Sqlite;
        if(!v1Sqlite.open(path))        //打开程式文件
        {
            THROW_EXCEPTION("程式文件创建时出错");
        }

        //2.创建job表
        std::string version = "V1";
        this->m_inspectionData.setVersion(version);     //将版本号设置为V2

        std::string sqlcreate = "create table Job ( version varchar(6), lastEditTime varchar(50) )";
        v1Sqlite.execute(sqlcreate);

        std::string sqlInsert = "insert into Job(version,lastEditTime) values(?,?)";
        v1Sqlite.execute(sqlInsert,this->m_inspectionData.version(), this->m_inspectionData.lastEditingTime());

        //3.创建board表
        //新建表
        sqlcreate = "create table Board (name varchar(50),sizeX REAL,sizeY REAL,originalX REAL,originalY REAL)";
        v1Sqlite.execute(sqlcreate);

        //插入数据
        sqlInsert = "insert into Board(name,sizeX,sizeY,originalX,originalY) values(?,?,?,?,?)";

        v1Sqlite.execute(sqlInsert, this->m_inspectionData.board().name(),\
                         this->m_inspectionData.board().sizeX(), \
                         this->m_inspectionData.board().sizeY(),\
                         this->m_inspectionData.board().originalX(),\
                         this->m_inspectionData.board().originalY());


        //4.创建MeasuredObjs表
        //新建表
        sqlcreate = "create table MeasuredObjs (name varchar(50),width REAL,height REAL,xPos REAL,yPos REAL,angle REAL)";
        v1Sqlite.execute(sqlcreate);

        //插入数据
        sqlInsert = "insert into MeasuredObjs(name,width,height,xPos,yPos,angle) values(?,?,?,?,?,?)";
        Job::MeasuredObj* pListHead = this->m_inspectionData.board().measuredObjList().headMeasuredObjs();

        v1Sqlite.prepare(sqlInsert);
        v1Sqlite.begin();

        while (nullptr != pListHead)    //循环插入所有元件的数据
        {
            v1Sqlite.executeWithParms(pListHead->name().data(),\
                                      pListHead->body().width(),\
                                      pListHead->body().height(),\
                                      pListHead->body().xCoord(),\
                                      pListHead->body().yCoord(),
                                      pListHead->body().angle());
            pListHead = pListHead->pNext();
        }

        v1Sqlite.commit();
        v1Sqlite.close();

    }
    catch(const SDK::CustomException& ex)
    {
        THROW_EXCEPTION(ex.what());
        //        if(v1Sqlite.isOpened())
        //        {
        //            v1Sqlite.reset();
        //            v1Sqlite.close();
        //        }
    }
}

void MainWindow::readJob(std::string path)
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
            std::string selectedString = "select version from Job";
            sqlite.prepare(selectedString);
            this->m_inspectionData.setVersion(sqlite.executeScalar<std::string>(selectedString));

            //>>>----------------------------------------------------------------------------------------------------------
            //2.读取最后检测时间
            selectedString = "select lastEditTime from Job";
            sqlite.prepare(selectedString);
            this->m_inspectionData.setLastEditingTime(sqlite.executeScalar<std::string>(selectedString));

            //>>>----------------------------------------------------------------------------------------------------------
            //3.读取Board表
            selectedString = "select * from Board";
            sqlite.prepare(selectedString);
            sqlite.begin();

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

            //>>>----------------------------------------------------------------------------------------------------------
            //4.读取measuredObjs表
            selectedString = "select * from MeasuredObjs";
            sqlite.prepare(selectedString);
            sqlite.begin();

            Job::MeasuredObj measuredObj;
            while(true)
            {
                sqlite.step();
                if (sqlite.latestErrorCode() == SQLITE_DONE)
                {
                    break;
                }

                //创建具体的对象
                measuredObj.setName(boost::get<std::string>(sqlite.columnValue(0)));
                measuredObj.body().setHeight(boost::get<double>(sqlite.columnValue(1)));
                measuredObj.body().setWidth(boost::get<double>(sqlite.columnValue(2)));
                measuredObj.body().setXCoord(boost::get<double>(sqlite.columnValue(3)));
                measuredObj.body().setYCoord(boost::get<double>(sqlite.columnValue(4)));
                this->m_inspectionData.board().measuredObjList().pushHeadNode(&measuredObj);
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
