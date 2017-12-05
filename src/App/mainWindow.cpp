#include "mainWindow.hpp"

using namespace std;
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

void MainWindow::writeInspectionDataToXml(const string & filename)
{
   m_inspectionData.writeToXml(QString::fromStdString(this->m_appSetting.jobFolderPath() +\
                                                      filename + ".xml"));
}

string MainWindow::loadJobFolder()
{
    QDir dir(QString::fromStdString(m_appSetting.jobFolderPath()));

    //step1 判断文件夹是否存在，不存在则创建
    if(!dir.exists())
    {
        QString path = dir.absolutePath();
        //文件夹不存在，判断是否创建成功，不成功则抛出异常
        if( !dir.mkpath(path) )
        {
            THROW_EXCEPTION("程式路径不存在且创建失败!");
        }
    }

    //step2 创建过滤器列表，过滤xml、txt为后缀的文件
    QStringList filters;
    filters << "*[^xml|^txt]";
    dir.setNameFilters(filters);

    dir.setFilter(QDir::Files);
    QFileInfoList list = dir.entryInfoList();
    QFileInfo fileInfo;
    std::string xmlSuffix = ".xml";

    //step3 如果没有程式文件，返回空字符串
    if(list.empty())
    {
        return "";
    }
    //step4 如果目录下有众多程式，输出到屏幕供选择
    else
    {
        //step4.1 输出程式名到屏幕供选择
        for (int i = 0; i < list.size(); ++i)
        {
            fileInfo = list.at(i);
            std::cout<< i << " " << list.at(i).fileName().toStdString() <<std::endl;
        }
        std::cout << "请输入序号选择程式：";
        int index = 0;
        while (true)
        {
            //step4.2 读取输入选项
            std::cin >> index;
            if(index < list.size() && index >= 0)          //判断输入是否符合要求
            {
                fileInfo = list.at(index);
                return fileInfo.fileName().toStdString();  //返回文件名
            }
            else
            {
                std::cout << "请重新输入索引！" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
}

void MainWindow::generatDefaultJob(string JobName)
{
    //step1 生成inspectionData数据
    Job::InspectionData inspectiondate;
    m_dataGenrator.generateObjInspetionData(MEASURED_OBJ_CNT,inspectiondate);

    //step2 写入Job文件
    m_inspectionJob.saveJob(inspectiondate,m_appSetting.jobFolderPath() + JobName);
}

void MainWindow::printToConsle()
{
    m_inspectionData.print();
}

void MainWindow::loadJobToInspectionData(string &filename)
{
    m_inspectionJob.readJob(m_inspectionData,m_appSetting.jobFolderPath() + \
                            filename);
}

}//End of namespace App

