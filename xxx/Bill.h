#ifndef BILL_H
#define BILL_H

#include "Vehicle.h"
#include "Driver.h"
#include "ParkingSlot.h"
#include "TimingDetails.h"

//class Bill


class Bill {
    private:
    int billId;
    Vehicle vehicle;
    Driver driver;
    ParkingSlot parkingSlot;
    TimingDetails timingDetails;
    double charges;

public:
    Bill() = delete;
    Bill(const Bill&) = default;
    Bill(Bill&&) = delete;
    Bill& operator=(const Bill&) = delete;
    Bill& operator=(Bill&&) = delete;
    ~Bill() = default;

    Bill(int id, const Vehicle& v, const Driver& d, const ParkingSlot& ps, const TimingDetails& td, double c);
    int getBillId() const;
    Vehicle getVehicle() const;
    Driver getDriver() const;
    ParkingSlot getParkingSlot() const;
    TimingDetails getTimingDetails() const;
    double getCharges() const;


};

#endif // BILL_H
