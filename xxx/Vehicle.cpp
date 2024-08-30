#include "Vehicle.h"

Vehicle::Vehicle(const std::string& number, const VehicleType& type, const std::string& owner, const std::string& contact)
    : vehicleNumber(number), vehicleType(type), ownerName(owner), ownerContact(contact) {}

std::string Vehicle::getVehicleNumber() const {
    return vehicleNumber;
}

VehicleType Vehicle::getVehicleType() const {
    return vehicleType;
}

std::string Vehicle::getOwnerName() const {
    return ownerName;
}

std::string Vehicle::getOwnerContact() const {
    return ownerContact;
}
