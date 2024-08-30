#include "Driver.h"

Driver::Driver(const std::string& name, const std::string& license, const std::string& contact)
    : name(name), licenseNumber(license), contact(contact) {}

std::string Driver::getName() const {
    return name;
}

std::string Driver::getLicenseNumber() const {
    return licenseNumber;
}

std::string Driver::getContact() const {
    return contact;
}
