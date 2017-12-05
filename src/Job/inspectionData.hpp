#ifndef INSPECTIONDATA_HPP
#define INSPECTIONDATA_HPP

#include "Job/measuredObjList.hpp"
#include "Job/board.hpp"

namespace Job
{
/**
 *  @brief InspectionData
 *         把检测程式写入到XML文件
 *
 *  @author grace
 *  @version 1.00 2017-11-29 grace
 *                note:create it
 */
class InspectionData
{
public:
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //constructor & destructor

    InspectionData();
    virtual ~InspectionData();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //operate function

    /*
    *  @brief  将内存中的inspectionData数据结构写入到Xml文件中
    *  @param  fileName：待写入的文件名
    *  @return
    */
    void writeToXml(const QString & fileName);


    /*
    *  @brief 将内存中的inspectionData打印到终端
    *  @param
    *  @return
    */
    void print();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //get & set function
    Job::Board &board() {return this->m_board;}
    void setBoard(Job::Board board) {this->m_board = board;}

    std::string &version() {return this->m_version;}
    void setVersion(std::string version) {this->m_version = version;}

    std::string &lastEditingTime() {return this->m_lastEditingTime;}
    void setLastEditingTime(std::string lastEditingTime)
    {this->m_lastEditingTime = lastEditingTime;}

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

private:

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //member variant
    std::string m_version{"V1"};
    std::string m_lastEditingTime{"2017年 12月 03日 星期日 21:12:32 CST"};
    Job::Board m_board;

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};
}


#endif // INSPECTIONDATA_HPP
