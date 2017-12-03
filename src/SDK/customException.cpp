#include "customException.hpp"

SDK::CustomException::CustomException()
{

}

SDK::CustomException::CustomException(std::string &message)
{
    this->m_originalMsg = message;
}

SDK::CustomException::~CustomException()
{

}

const std::string SDK::CustomException::originalMsg() const
{
    return this->m_originalMsg;
}
