#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H

#include "Vehicle.h"
#include "Driver.h"
#include "TimingDetails.h"

//class ParkingSlot

class ParkingSlot {
    private:
    int slotNumber;
    bool occupied;
    Vehicle vehicle;
    Driver driver;
    TimingDetails timing;

public:
    
    ParkingSlot() = default;
    ParkingSlot(const ParkingSlot&) = default;
    ParkingSlot(ParkingSlot&&) = delete;
    ParkingSlot& operator=(const ParkingSlot&) = default;
    ParkingSlot& operator=(ParkingSlot&&) = delete;
    ~ParkingSlot() = default;
    ParkingSlot(int number);
    bool isOccupied() const;
    void parkVehicle(const Vehicle& vehicle, const Driver& driver);
    void exitVehicle();
    int getSlotNumber() const;
    Vehicle getVehicle() const;
    Driver getDriver() const;
    TimingDetails getTimingDetails() const;


};

#endif // PARKINGSLOT_H
