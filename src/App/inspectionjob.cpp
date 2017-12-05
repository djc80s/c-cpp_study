#include "inspectionjob.h"

App::InspectionJob::InspectionJob()
{

}

App::InspectionJob::~InspectionJob()
{

}

void App::InspectionJob::saveJob(Job::InspectionData &inspectionData, std::string path)
{
    SSDK::DB::SqliteDB sqlite;
    try
    {
        //>>>----------------------------------------------------------------------------------------------------------
        //1.打开数据库文件
        if(!sqlite.open(path))                //打开程式文件
        {
            THROW_EXCEPTION("程式文件创建时出错");
        }

        //>>>----------------------------------------------------------------------------------------------------------
        //2.创建job表
        std::string sqlcreate = "create table Job ( version varchar(6), lastEditTime varchar(50) )";//新建表
        sqlite.execute(sqlcreate);

        std::string sqlInsert = "insert into Job(version,lastEditTime) values(?,?)";
        sqlite.execute(sqlInsert,inspectionData.version(), inspectionData.lastEditingTime()); //插入数据

        //>>>----------------------------------------------------------------------------------------------------------
        //3.创建board表

        sqlcreate = "create table Board (name varchar(50),sizeX REAL,sizeY REAL,originalX REAL,originalY REAL)";
        sqlite.execute(sqlcreate);

        sqlInsert = "insert into Board(name,sizeX,sizeY,originalX,originalY) values(?,?,?,?,?)";
        sqlite.execute(sqlInsert, inspectionData.board().name(),\
                       inspectionData.board().sizeX(), \
                       inspectionData.board().sizeY(),\
                       inspectionData.board().originalX(),\
                       inspectionData.board().originalY());

        //>>>----------------------------------------------------------------------------------------------------------
        //4.创建MeasuredObjs表
        sqlcreate = "create table MeasuredObjs (name varchar(50),width REAL,height REAL,xPos REAL,yPos REAL,angle REAL)";
        sqlite.execute(sqlcreate);

        sqlInsert = "insert into MeasuredObjs(name,width,height,xPos,yPos,angle) values(?,?,?,?,?,?)";
        Job::MeasuredObj* pListHead = inspectionData.board().measuredObjList().headMeasuredObjs();

        sqlite.prepare(sqlInsert);
        sqlite.begin();

        while (nullptr != pListHead)    //循环插入所有元件的数据
        {
            sqlite.executeWithParms(pListHead->name().data(),\
                                    pListHead->body().width(),\
                                    pListHead->body().height(),\
                                    pListHead->body().xCoord(),\
                                    pListHead->body().yCoord(),
                                    pListHead->body().angle());
            pListHead = pListHead->pNext();
        }

        //>>>----------------------------------------------------------------------------------------------------------
        //5.提交更改并关闭连接
        sqlite.commit();
        sqlite.close();

    }
    catch(const SDK::CustomException& ex)
    {
        THROW_EXCEPTION(ex.what());
        if(sqlite.isOpened())
        {
            sqlite.reset();
            sqlite.close();
        }
    }
}

void App::InspectionJob::readJob(Job::InspectionData &inspectionData, std::string path)
{
    SSDK::DB::SqliteDB sqlite;
    try
    {
        if(!sqlite.open(path))
        {
            //>>>----------------------------------------------------------------------------------------------------------
            //1.读取版本号
            std::string selectedString = "select version from Job";
            sqlite.prepare(selectedString);
            inspectionData.setVersion(sqlite.executeScalar<std::string>(selectedString));

            //>>>----------------------------------------------------------------------------------------------------------
            //2.读取最后检测时间
            selectedString = "select lastEditTime from Job";
            sqlite.prepare(selectedString);
            inspectionData.setLastEditingTime(sqlite.executeScalar<std::string>(selectedString));

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
                inspectionData.board().setName(boost::get<std::string>(sqlite.columnValue(0)));
                inspectionData.board().setSizeX(boost::get<double>(sqlite.columnValue(1)));
                inspectionData.board().setSizeY(boost::get<double>(sqlite.columnValue(2)));
                inspectionData.board().setOriginalX(boost::get<double>(sqlite.columnValue(3)));
                inspectionData.board().setOriginalY(boost::get<double>(sqlite.columnValue(4)));
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
                inspectionData.board().measuredObjList().pushHeadNode(&measuredObj);
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
