#include "InvalidMomentException.h"

using namespace std;

InvalidMomentException::InvalidMomentException()
{
    setMessage("Defaut");
}
InvalidMomentException::InvalidMomentException(string msg)
{
    setMessage(msg);
}
InvalidMomentException::InvalidMomentException(const InvalidMomentException &IME)
{
    setMessage(IME.getMessage());
}
InvalidMomentException::~InvalidMomentException()
{

}

/********* Getters *********/

string InvalidMomentException::getMessage() const
{
    return message;
}

/********* Setters *********/

void InvalidMomentException::setMessage(const string msg)
{
    message = msg;
}

