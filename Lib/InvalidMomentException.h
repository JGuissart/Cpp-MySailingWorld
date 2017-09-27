#ifndef INVALIDMOMENTEXCEPTION_H_INCLUDED
#define INVALIDMOMENTEXCEPTION_H_INCLUDED

#include <string>

class InvalidMomentException
{
    private:
        std::string message;
    public:
        InvalidMomentException();
        InvalidMomentException(std::string msg);
        InvalidMomentException(const InvalidMomentException &IME);
        ~InvalidMomentException();

        /********* Getters *********/

        std::string getMessage() const;

        /********* Setters *********/

        void setMessage(const std::string msg);
};

#endif // INVALIDMOMENTEXCEPTION_H_INCLUDED
