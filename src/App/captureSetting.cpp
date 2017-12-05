#include "captureSetting.hpp"

namespace App
{

CaptureSetting::CaptureSetting()
{

}

CaptureSetting::~CaptureSetting()
{

}

void CaptureSetting::load(const QString &path)
{
    try
    {
        if(!QFile::exists(path)) //假如路径不存在的话, 抛出异常
        {
            THROW_EXCEPTION("没有硬件配置文件!");
        }      
        else //文件路径存在, 判断文件内容是否正确，不正确则抛出异常
        {
            QSettings configFile(path, QSettings::IniFormat);

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //step1. 读取图像的宽度,若数据异常则抛出异常

            int width =  configFile.value("ImgWidth").toInt();
            if( (width >= 3072) && (width <= 4096) )
            {
                this->m_imgWidth = width;
            }
            else
            {
                THROW_EXCEPTION("读取ImgWidth失败!");
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //step2. 读取图像的高度，若数据异常则抛出异常
            int height =  configFile.value("ImgHeight").toInt();
            if( (height >= 3072) && (height <= 4096) )
            {
                this->m_imgHeight = height;
            }
            else
            {
                THROW_EXCEPTION("读取ImgHeight失败!");
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //step3. 读取图像位数，若数据异常则抛出异常

            int imgBits =  configFile.value("ImgBits").toInt();
            if( imgBits == 8 )
            {
                this->m_imgBits = IMGBITS::BIT8;
            }
            else if ( imgBits == 16 )
            {
                this->m_imgBits = IMGBITS::BIT16;
            }
            else
            {
                THROW_EXCEPTION("读取ImgBits失败!");
            }
        }//End of else(路径不存在)
    }
    catch(const SDK::CustomException& ex)
    {
        THROW_EXCEPTION(ex.what()); //抛出异常
    }
}

}
