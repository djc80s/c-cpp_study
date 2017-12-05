#include "appSetting.hpp"

namespace App
{
AppSetting::AppSetting()
{

}

AppSetting::~AppSetting()
{

}

void AppSetting::load(const QString &path)
{
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //step1. 设置默认参数

    QString defaultTheme = "Black";
    QString defaultLang = "CN";
    QString defaultLaneMode = "Simulator";
    QString defaultMachineType = "SPI";
    QString defaultCompanyName = "SCIJET";
    QString defaultJobFolderPath = "./Job/";
    QSettings configFile(path, QSettings::IniFormat);

    this->m_lang = LANG::CN;
    this->m_laneMode = LANEMODE::SIMULATOR;
    this->m_machineType = MACHINETYPE::SPI;
    this->m_companyName = defaultCompanyName.toStdString();
    this->m_jobFolderPath = defaultJobFolderPath.toStdString();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //step2. 判断文件是否存在。不存在创建默认文件，存在内容不对则改为默认内容

    if(!QFile::exists(path)) //2.1 假如路径不存在,重新创建一个配置文件
    {
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.1.1 把默认参数写入文件

        std::cout <<"没有该文件, 写入默认值"<<std::endl;
        configFile.setValue("Theme", defaultTheme);
        configFile.setValue("Lang", defaultLang);
        configFile.setValue("LaneMode",defaultLaneMode);
        configFile.setValue("MachineType",defaultMachineType);
        configFile.setValue("CompanyName",defaultCompanyName);
        configFile.setValue("JobFolderPath",defaultJobFolderPath);

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.1.2 默认参数赋值给成员变量

        this->m_companyName = defaultCompanyName.toStdString();
        this->m_jobFolderPath = defaultJobFolderPath.toStdString();
    } 
    else  //2.2 文件路径存在
    {
        QSettings configFile(path, QSettings::IniFormat);

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.2.1 读取Theme, 如果不正确则写入默认值

        QString theme =  configFile.value("Theme").toString();
        if("Black" != theme  && "White" != theme)
        {
            std::cout << "读取Theme失败"<<std::endl;
            configFile.setValue("Theme", "Black");
            this->m_theme = THEME::BLACK;
        }
        else if(theme == "Black")
        {
            this->m_theme = THEME::BLACK;
        }
        else
        {
            this->m_theme = THEME::WHITE;
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.2.2 读取Lang,如果不正确则写入默认值

        QString lang =  configFile.value("Lang").toString();
        if("CN" != lang && "EN" != lang)
        {
            std::cout << "读取Lang失败"<<std::endl;
            configFile.setValue("Lang", "CN");
            this->m_lang = LANG::CN;
        }
        else if("CN" == lang)
        {
            this->m_lang = LANG::CN;
        }
        else
        {
            this->m_lang = LANG::EN;
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.2.3 读取LaneMode,如果不正确则写入默认值

        QString laneMode = configFile.value("LaneMode").toString();
        if("Simulator" != laneMode
                && "DualLane" != laneMode
                && "SingleLane" != laneMode)
        {
            std::cout << "读取LaneMode失败" <<std::endl;
            configFile.setValue("LaneMode", "Simulator");
            this->m_laneMode = LANEMODE::SIMULATOR;
        }
        else if("Simulator" == laneMode)
        {
            this->m_laneMode = LANEMODE::SIMULATOR;
        }
        else if("DualLane" == laneMode)
        {
            this->m_laneMode = LANEMODE::DUAL_LANE;
        }
        else
        {
            this->m_laneMode = LANEMODE::SINGLE_LANE;
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.2.4 读取MachineType,如果不正确则写入默认值

        QString machineType = configFile.value("MachineType").toString();
        if("SPI" != machineType && "AOI3D" != machineType)
        {
            std::cout << "读取MachineType失败"<<std::endl;
            configFile.setValue("MachineType", "SPI");
            this->m_machineType = MACHINETYPE::SPI;
        }
        else if("SPI" == machineType)
        {
            this->m_machineType = MACHINETYPE::SPI;
        }
        else
        {
            this->m_machineType = MACHINETYPE::AOI3D;
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.2.5 读取CompanyName,如果不存在则设置为默认值

        QString companyName = configFile.value("Company").toString();
        if("\0" != companyName)
        {
            this->m_companyName = defaultCompanyName.toStdString();
        }
        else
        {
            this->m_companyName = companyName.toStdString();
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.2.6 读取JobFolderPath,如果路径目录不存在则设置为默认路径

        QString jobFolderPath = configFile.value("JobFolderPath").toString();
        std::fstream file;
        file.open(jobFolderPath.toStdString(),std::ios::in);//指定可读方式打开文件
        if(!file)
        {
            std::cout << "存放程式路径不存在，使用默认路径\n" << std::endl;
            this->m_jobFolderPath = defaultJobFolderPath.toStdString();
        }
        else
        {
            this->m_jobFolderPath = jobFolderPath.toStdString();
        }
    }//End of else（目录不存在）

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

}//End of void AppSetting::load(const QString &path)

}//End of namespace App

