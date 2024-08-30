#include "Bill.h"

Bill::Bill(int id, const Vehicle& v, const Driver& d, const ParkingSlot& ps, const TimingDetails& td, double c)
    : billId(id), vehicle(v), driver(d), parkingSlot(ps), timingDetails(td), charges(c) {}

int Bill::getBillId() const {
    return billId;
}

Vehicle Bill::getVehicle() const {
    return vehicle;
}

Driver Bill::getDriver() const {
    return driver;
}

ParkingSlot Bill::getParkingSlot() const {
    return parkingSlot;
}

TimingDetails Bill::getTimingDetails() const {
    return timingDetails;
}

double Bill::getCharges() const {
    return charges;
}
