#ifndef APPSETTING_HPP
#define APPSETTING_HPP

#include <iostream>
#include <iostream>
#include <fstream>
#include <QSettings>
#include <QFile>

#include "SDK/customException.hpp"

namespace App
{
class AppSetting
{
public:

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //enum variant class

    enum class THEME
    {
        BLACK,
        WHITE
    };
    enum class LANG
    {
        CN,
        EN
    };
    enum class LANEMODE
    {
        SIMULATOR,
        SINGLE_LANE,
        DUAL_LANE
    };
    enum class MACHINETYPE
    {
        SPI,
        AOI3D
    };

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //constructor & destuctor

    AppSetting();
    virtual ~AppSetting();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //get & set function

    std::string companyName() {return this->m_companyName;}
    void setCompanyName(std::string companyName) {this->m_companyName = companyName;}

    std::string jobFolderPath() {return this->m_jobFolderPath;}
    void setJobFolderPath(std::string jobFolderPath) {this->m_jobFolderPath = jobFolderPath;}

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //operate function

    void load(const QString& path);

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

private:

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //member variant

    THEME m_theme{THEME::BLACK};
    LANG m_lang{LANG::CN};
    LANEMODE m_laneMode{LANEMODE::SIMULATOR};
    MACHINETYPE m_machineType{MACHINETYPE::SPI};
    std::string m_companyName{"SCIJET"};
    std::string m_jobFolderPath{"./Inspection/"};

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

};
}

#endif // APPSETTING_HPP