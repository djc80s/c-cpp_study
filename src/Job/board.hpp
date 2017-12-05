#ifndef BOARD_HPP
#define BOARD_HPP

#include <QTextStream>
#include <QFile>
#include <QDomDocument>
#include <string>

#include "measuredObjList.hpp"

namespace Job
{
/**
 *  @brief Board
 *         把板子基本信息写到XML文件
 *
 *  @author grace
 *  @version 1.00 2017-11-27 grace
 *                note:create it
 */
class Board
{
public:
    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //construtor & destructor

    Board();
    Board(double sizeX,double sizeY,double originalX,double originalY);
    ~Board();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //get & set function
    Job::MeasuredObjList &measuredObjList() {return this->m_measuredObjList;}
    void setMeasuredObjList(Job::MeasuredObjList &measureObj) {this->m_measuredObjList = measureObj;}

    std::string name() const {return this->m_name;}
    void setName(std::string name) {this->m_name = name;}

    double sizeX() const {return this->m_sizeX;}
    void setSizeX(double sizeX) {this->m_sizeX = sizeX;}

    double sizeY() const {return this->m_sizeY;}
    void setSizeY(double sizeY) {this->m_sizeY = sizeY;}

    double originalX() const {return this->m_originalX;}
    void setOriginalX(double originalX) {this->m_originalX = originalX;}

    double originalY() const {return this->m_originalY;}
    void setOriginalY(double originalY) {this->m_originalY = originalY;}

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //operate function

    /*
    *  @brief 写板子的信息到XML文件
    *  @param qXmlDoc：文件名
    *  @return NA
    */
    void writeToXml( QDomDocument & qXmlDoc);

    /*
    *  @brief 输出Board信息到终端
    *  @param
    *  @return
    */
    void print();

    inline const Board& operator = (const Board &other)
    {
        m_name = other.name();
        m_sizeX = other.sizeX();
        m_sizeY = other.sizeY();
        m_originalX = other.originalX();
        m_originalY = other.originalY();
        m_measuredObjList = other.m_measuredObjList;
        return *this;
    }

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

private:

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //member variant
    Job::MeasuredObjList m_measuredObjList;
    std::string m_name{"iPhone"};
    double m_sizeX{10};
    double m_sizeY{20};
    double m_originalX{30};
    double m_originalY{40};

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

};
}

#endif // BOARD_HPP
