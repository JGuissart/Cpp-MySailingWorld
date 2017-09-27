#ifndef INVALIDCONTAINERSEXCEPTION_H_INCLUDED
#define INVALIDCONTAINERSEXCEPTION_H_INCLUDED

#include <string>

class InvalidContainersException
{
    private:
        std::string message;
    public:
        InvalidContainersException();
        InvalidContainersException(std::string msg);
        InvalidContainersException(const InvalidContainersException &ICE);
        ~InvalidContainersException();

        /********* Getters *********/

        std::string getMessage() const;

        /********* Setters *********/

        void setMessage(const std::string msg);
};

#endif // InvalidContainersException_H_INCLUDED
