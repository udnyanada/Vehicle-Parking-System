#include "ParkingSystem.h"
#include <iostream>
#include "EmptyContainerException.h"

ParkingSystem::ParkingSystem(int capacity) : maxSlots(capacity), billCounter(0) {
    for (int i = 1; i <= maxSlots; ++i) {
        slots.emplace(i, ParkingSlot(i));
    }
}

bool ParkingSystem::parkVehicle(int slotNumber, const Vehicle& vehicle, const Driver& driver) {
    if (slotNumber < 1 || slotNumber > maxSlots || slots[slotNumber].isOccupied()) {
        return false;
    }
    slots[slotNumber].parkVehicle(vehicle, driver);
    return true;
}

bool ParkingSystem::exitVehicle(int slotNumber) {
    if (slotNumber < 1 || slotNumber > maxSlots || !slots[slotNumber].isOccupied()) {
        return false;
    }
    slots[slotNumber].exitVehicle();
    auto timing = slots[slotNumber].getTimingDetails();
    double charges = calculateCharges(slots[slotNumber].getVehicle().getVehicleType(), timing.getHours());
    Bill bill(++billCounter, slots[slotNumber].getVehicle(), slots[slotNumber].getDriver(), slots[slotNumber], timing, charges);
    bills.push_back(bill);
    return true;
}

void ParkingSystem::displayStatus() const {

    if(slots.empty())
    {
        throw EmptyContainerException("Data is Empty,Nothing to show\n");
    }
    for (const auto& slot : slots) {
        std::cout << "\n***Slot " << slot.first << ": " << (slot.second.isOccupied() ? "Occupied***\n" : "Available***\n") << std::endl;
    }
}

void ParkingSystem::displayBills() const {
    if(bills.empty())
    {
        throw EmptyContainerException("No bills are there to show\n");
    }
    for (const auto& bill : bills) {
        std::cout << "\nBill ID: " << bill.getBillId() << ", Vehicle: " << bill.getVehicle().getVehicleNumber()
                  << ", Driver: " << bill.getDriver().getName() << ", Charges: $" << bill.getCharges() << std::endl;
    }
}

double ParkingSystem::calculateCharges(const VehicleType& vehicleType, int hours) const {
    if (vehicleType == VehicleType::OTHER) {
        return hours * 5.0; // Example rate: $5 per hour
    } else if (vehicleType == VehicleType::FOUR_WHEEL) {
        return hours * 4.0; // Example rate: $4 per hour
    } else if (vehicleType == VehicleType::THREE_WH) {
        return hours * 3.0; // Example rate: $3 per hour
    } 
    else
    {
        return hours * 2.0; // Example rate: $2 per hour
    }
}
