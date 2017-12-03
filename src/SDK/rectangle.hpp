#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>

namespace SDK
{
/**
 *  @brief Rectangle
 *         设置一个矩形
 *  @author grace
 *  @version 1.00 2017-11-27 grace
 *                note:create it
 */
class Rectangle
{
public:

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //constructor & destructor

    Rectangle();

    Rectangle(double xCoord,double yCoord,double width,double height);

    ~Rectangle();

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //get & set function

    double xCoord() {return this->m_xCoord;}
    void setXCoord(double xCoord) {this->m_xCoord = xCoord;}

    double yCoord() {return this->m_yCoord;}
    void setYCoord(double yCoord) {this->m_yCoord = yCoord;}

    double angle() {return this->m_angle;}
    void setAngle(double angle) {this->m_angle = angle;}

    double width() {return this->m_width;}
    void setWidth(double width) {this->m_width = width;}

    double height() {return this->m_height;}
    void setHeight(double height) {this->m_height = height;}

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

private:

    //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //member variant

    double m_xCoord{0.0}; //矩形左上角x坐标
    double m_yCoord{0.0}; //矩形左上角y坐标
    double m_angle{0.0};  //矩形四个角的角度
    double m_width{0.0};  //矩形宽
    double m_height{0.0}; //矩形长

    //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

};//End of class Rectangle
}//End of namespace SDK

#endif // RECTANGLE_HPP
