#ifndef MEASUREDOBJ_HPP
#define MEASUREDOBJ_HPP

#include <iostream>

#include "SDK/rectangle.hpp"

namespace Job
{
/**
 *  @brief MeasuredObj
 *         代表一个检测对象
 *
 *  @author grace
 *  @version 1.00 2017-11-27 grace
 *                note:create it
 */
class MeasuredObj
{
public:

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //constructor & destructor

    MeasuredObj();
    ~MeasuredObj();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //operate function

    std::string name() {return this->m_name;}
    void setName(std::string name) {this->m_name = name;}

    SDK::Rectangle body() {return this->m_body;}
    void setBody(SDK::Rectangle body) {this->m_body = body;}

    MeasuredObj * pPre() {return this->m_pPre;}
    void setPPre(MeasuredObj *pPre){this->m_pPre = pPre;}

    MeasuredObj * pNext() {return this->m_pNext;}
    void setPNext(MeasuredObj *pNext){this->m_pNext = pNext;}

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

private:

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //member variant

    std::string m_name{'\0'};//测量对象的名字
    SDK::Rectangle m_body;   //测量对象的所在矩形框
    MeasuredObj * m_pPre{nullptr};//指向前一个测量对象的指针
    MeasuredObj * m_pNext{nullptr};//指向后一个测量对象的指针

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

};//End of class MeasuredObj
}//End of namespcae Job

#endif // MEASUREDOBJ_HPP
