#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "VehicleType.h"

//class vehicle

class Vehicle {
    private:
    std::string vehicleNumber;
    VehicleType vehicleType;
    std::string ownerName;
    std::string ownerContact;

public:
    
    Vehicle() = default;
    Vehicle(const Vehicle&) = default;
    Vehicle(Vehicle&&) = delete;
    Vehicle& operator=(const Vehicle&) = default;
    Vehicle& operator=(Vehicle&&) = delete;
    ~Vehicle() = default;
    Vehicle(const std::string& number, const VehicleType& type, const std::string& owner, const std::string& contact);

    std::string getVehicleNumber() const;
    VehicleType getVehicleType() const;
    std::string getOwnerName() const;
    std::string getOwnerContact() const;


};

#endif // VEHICLE_H
