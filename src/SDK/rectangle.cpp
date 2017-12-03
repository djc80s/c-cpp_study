#include "SDK/rectangle.hpp"

SDK::Rectangle::Rectangle()
{

}

SDK::Rectangle::Rectangle(double xCoord, double yCoord, double width, double height)
{
    this->m_xCoord = xCoord;
    this->m_yCoord = yCoord;
    this->m_width = width;
    this->m_height = height;
}

SDK::Rectangle::~Rectangle()
{

}
