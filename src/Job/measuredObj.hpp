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
    //get/set function

    std::string &name() {return m_name;}
    void setName(std::string name) {m_name = name;}

    SDK::Rectangle &body() {return m_body;}
    void setBody(SDK::Rectangle body) {m_body = body;}

    MeasuredObj * pPre() const {return m_pPre;}
    void setPPre(MeasuredObj *pPre){m_pPre = pPre;}

    MeasuredObj * pNext() const {return m_pNext;}
    void setPNext(MeasuredObj *pNext){m_pNext = pNext;}

    inline const MeasuredObj& operator = (MeasuredObj &other)
    {
        m_name.assign(other.m_name);
        m_body = other.body();
        return *this;
    }

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

private:

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //member variant

    std::string m_name{""};//测量对象的名字
    SDK::Rectangle m_body;   //测量对象的所在矩形框
    MeasuredObj * m_pPre{nullptr};//指向前一个测量对象的指针
    MeasuredObj * m_pNext{nullptr};//指向后一个测量对象的指针

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

};//End of class MeasuredObj
}//End of namespcae Job

#endif // MEASUREDOBJ_HPP
