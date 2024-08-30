#include "ParkingSystem.h"
#include "WrongException.cpp"
#include "InputChecking.h"
#include "EmptyContainerException.h"

#include <iostream>

int main() {
    try
    {
        
        std::cout<<"\n***** KPIT PARKING SYSTEM *****\n\n";
        ParkingSystem parkingSystem(10); // Create a parking system with 10 slots

        while (true) {
            std::cout << "\n1. Park Vehicle\n2. Exit Vehicle\n3. Display Status\n4. Display Bills\n5. Exit\n";
            int choice;
            std::string inpytA;
            while(true)
             {
                std::cout << "Enter Choice: ";
                std::cin >> inpytA;
                if(isValidChoice(inpytA))
                {
                    choice=std::stoi(inpytA);
                    break;
                }
                std::cout<<"Enter the choice number between 1 t0 5\n";
            }

            std::cout<<"\n";
            
        if (choice == 1) {
            int slotNumber;
            std::string vehicleNumber, ownerName, ownerContact;
            VehicleType vehicleType;

            std::string driverName, licenseNumber, driverContact;
           
            
            while(true)
            {
                std::cout << "Enter slot number: ";
                std::cin >> inpytA;
                if(SlotNumberCheck(inpytA))
                {
                    slotNumber=std::stoi(inpytA);
                    break;
                }
                std::cout<<"Enter the Slot number between 1 t0 10\n";
            }
           
           while (true)
           {
                std::cout << "Enter vehicle number: ";
                std::cin >> inpytA;
                if(isValidVehicleNumber(inpytA))
                {
                    vehicleNumber=inpytA;
                    break;
                }
                std::cout<<"ENter valid Vehicle Number\n";
           }
           
            
            while (true)
           {
                std::cout << "Enter vehicle type: ";
                

                std::cin >> inpytA;
                if(isValidVehicleType(inpytA))
                {
                    vehicleType=static_cast<VehicleType> (stoi(inpytA));
                    break;
                }
                std::cout<<"ENter valid VehicleType \t 0.TWO_WH\t 1.THREE_WH \t 2.FOUR_WH \t 3.OTHER \n";
           }

            std::cout << "Enter owner Full name: ";
            std::cin >> ownerName;


             while (true)
           {
                std::cout << "Enter owner contact: ";
                
                std::cin >> inpytA;
                if(isValidMobileNumber(inpytA))
                {
                    ownerContact=inpytA;
                    break;
                }
                std::cout<<"ENter valid Mobile number of owner\n";
           }

            

            
            std::cout << "Enter driver name: ";
            std::cin >> driverName;

            std::cout << "Enter driver license number: ";
            std::cin >> licenseNumber;

              while (true)
           {
                std::cout << "Enter driver contact: ";
                std::cin >> inpytA;
                if(isValidMobileNumber(inpytA))
                {
                    driverContact=inpytA;
                    break;
                }
                std::cout<<"ENter valid Mobile number of driver\n";
           }
            

            Vehicle vehicle(vehicleNumber, vehicleType, ownerName, ownerContact);
            Driver driver(driverName, licenseNumber, driverContact);

            if (parkingSystem.parkVehicle(slotNumber, vehicle, driver)) {
                std::cout << "\n***Vehicle parked successfully***\n";
            } else {
                std::cout << "\n***Failed to park vehicle. Slot may be occupied or invalid***\n";
            }
        } else if (choice == 2) {
            int slotNumber;
            while(true)
            {
                std::cout << "Enter slot number: ";
                std::cin >> inpytA;
                if(SlotNumberCheck(inpytA))
                {
                    slotNumber=std::stoi(inpytA);
                    break;
                }
                std::cout<<"Enter the Slot number between 1 t0 10\n";
            }

            if (parkingSystem.exitVehicle(slotNumber)) {
                std::cout << "\n***Vehicle exited successfully.***\n";
            } else {
                std::cout << "--->Failed to exit vehicle. Slot may be empty or invalid.\n";
            }
        } else if (choice == 3) {
            parkingSystem.displayStatus();
        } else if (choice == 4) {
            try
            {
                parkingSystem.displayBills();
            }
            catch(const EmptyContainerException& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
 std::cout<<"*** THANK YOU TO VISIT KPIT ***\n";
}
    catch(WrongInput& e1)
    {
        std::cerr << e1.what() << '\n';
    }
    catch(EmptyContainerException& ee)
    {
        std::cerr << ee.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
