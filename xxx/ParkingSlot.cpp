#include "ParkingSlot.h"



void ParkingSlot::parkVehicle(const Vehicle& v, const Driver& d) {
    vehicle = v;
    driver = d;
    timing.setEntryTime();
    occupied = true;
}

void ParkingSlot::exitVehicle() {
    timing.setExitTime();
    occupied = false;
}

int ParkingSlot::getSlotNumber() const {
    return slotNumber;
}

Vehicle ParkingSlot::getVehicle() const {
    return vehicle;
}

Driver ParkingSlot::getDriver() const {
    return driver;
}

TimingDetails ParkingSlot::getTimingDetails() const {
    return timing;
}


ParkingSlot::ParkingSlot(int number) : slotNumber(number), occupied(false) {}

bool ParkingSlot::isOccupied() const {
    return occupied;
}