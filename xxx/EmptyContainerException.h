/*
 Exception handled for Empty containers
*/


#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include <stdexcept>
#include <cstring>

class EmptyContainerException : public std::exception
{
private:
    char* _message;

public:
    EmptyContainerException() = delete;
    EmptyContainerException(const EmptyContainerException&) = delete;
    EmptyContainerException(EmptyContainerException&&) = default;
    EmptyContainerException& operator=(const EmptyContainerException&) = delete;
    EmptyContainerException&& operator=(const EmptyContainerException&&) = delete;
    EmptyContainerException(const char* message)
    {
        _message = new char[strlen(message) + 1];
        strcpy(_message, message);
    }

    ~EmptyContainerException()
    {
        delete[] _message;
    }

    virtual const char* what() const noexcept override
    {
        return _message;
    }
};

#endif // EMPTYCONTAINEREXCEPTION_H
