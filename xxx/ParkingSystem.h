#ifndef PARKINGSYSTEM_H
#define PARKINGSYSTEM_H

#include "Vehicle.h"
#include "Driver.h"
#include "ParkingSlot.h"
#include "Bill.h"
#include <unordered_map>
#include <vector>
#include "VehicleType.h"

//class ParkingSystem


class ParkingSystem {
    private:
    std::unordered_map<int, ParkingSlot> slots;
    std::vector<Bill> bills;
    int maxSlots;
    int billCounter;

    double calculateCharges(const VehicleType& vehicleType, int hours) const;

public:
    ParkingSystem() = default;
    ParkingSystem(const ParkingSystem&) = delete;
    ParkingSystem(ParkingSystem&&) = delete;
    ParkingSystem& operator=(const ParkingSystem&) = delete;
    ParkingSystem& operator=(ParkingSystem&&) = delete;
    ~ParkingSystem() = default;
    ParkingSystem(int capacity);
    bool parkVehicle(int slotNumber, const Vehicle& vehicle, const Driver& driver);
    bool exitVehicle(int slotNumber);
    void displayStatus() const;
    void displayBills() const;


};

#endif // PARKINGSYSTEM_H
