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

void MainWindow::writeToXml(const QString & path)
{
    this->m_inspectionData.writeToXml(path);
}

void MainWindow::loadJobFolder()
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

    //step3 如果没有程式文件，生成默认程式文件
    if(list.empty())
    {
        //step3.1 生成inspectionData数据
        Job::InspectionData inspectiondate;
        m_dataGenrator.generateObjInspetionData(MEASURED_OBJ_CNT,inspectiondate);

        //step3.2 写入Job文件
        m_inspectionJob.saveJob(inspectiondate,m_appSetting.jobFolderPath() + m_defaultJobName);

        //step3.3 写入xml文件
        inspectiondate.writeToXml( QString::fromStdString(m_appSetting.jobFolderPath() \
                                                          + m_defaultJobName + xmlSuffix));

        //step3.4 将程式数据输出到屏幕
        inspectiondate.print();

    }
    //step4 如果目录下有众多程式，输出到屏幕供操作
    else
    {
        //step4.1 输出程式名到屏幕供选择
        for (int i = 0; i < list.size(); ++i)
        {
            fileInfo = list.at(i);
            std::cout<< i << " " << list.at(i).fileName().toStdString()<< ":\t" <<std::endl;
        }
        std::cout << "请输入序号选择程式：" << "\t";
        int index = 0;
        while (true)
        {
            //step4.2 读取输入选项
            std::cin >> index;
            if(index < list.size() && index >= 0) //判断输入是否符合要求
            {
                fileInfo = list.at(index);

                //step4.3 加载用户选择的程式文件
                m_inspectionJob.readJob(m_inspectionData,m_appSetting.jobFolderPath() + \
                                        fileInfo.fileName().toStdString());

                //step4.4 将程式数据导出为xml文件
                writeToXml( QString::fromStdString(this->m_appSetting.jobFolderPath() +\
                                                         fileInfo.fileName().toStdString() + xmlSuffix ));

                //step4.5 将程式数据输出到屏幕
                m_inspectionData.print();
                break;
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

}//End of namespace App

