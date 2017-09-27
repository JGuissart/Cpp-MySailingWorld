#include "InvalidContainersException.h"

using namespace std;

InvalidContainersException::InvalidContainersException()
{
    setMessage("Defaut");
}
InvalidContainersException::InvalidContainersException(string msg)
{
    setMessage(msg);
}
InvalidContainersException::InvalidContainersException(const InvalidContainersException &ICE)
{
    setMessage(ICE.getMessage());
}
InvalidContainersException::~InvalidContainersException()
{

}

/********* Getters *********/

string InvalidContainersException::getMessage() const
{
    return message;
}

/********* Setters *********/

void InvalidContainersException::setMessage(const string msg)
{
    message = msg;
}

