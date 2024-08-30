
/*
 Exception handled for wrong inputs
*/

#include <stdexcept>
#include <cstring>

class WrongInput : public std::exception
{
private:
    char* _message;

public:
    WrongInput() = delete;
    WrongInput(const WrongInput&) = delete;
    WrongInput(WrongInput&&) = default;
    WrongInput& operator=(const WrongInput&) = delete;
    WrongInput&& operator=(const WrongInput&&) = delete;
    WrongInput(const char* message)
    {
        _message = new char[strlen(message) + 1];
        strcpy(_message, message);
    }

    ~WrongInput()
    {
        delete[] _message;
    }

    virtual const char* what() const noexcept override
    {
        return _message;
    }
};