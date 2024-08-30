#ifndef DRIVER_H
#define DRIVER_H

#include <string>

//class Driver 

class Driver {
    private:
    std::string name;
    std::string licenseNumber;
    std::string contact;

public:
    
    Driver() = default;
    Driver(const Driver&) = default;
    Driver(Driver&&) = delete;
    Driver& operator=(const Driver&) = default;
    Driver& operator=(Driver&&) = delete;
    ~Driver() = default;
    Driver(const std::string& name, const std::string& license, const std::string& contact);

    std::string getName() const;
    std::string getLicenseNumber() const;
    std::string getContact() const;


};

#endif // DRIVER_H
