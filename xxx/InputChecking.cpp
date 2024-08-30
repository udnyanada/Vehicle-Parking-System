#include "InputChecking.h"
#include <regex>



bool isValidChoice(std::string str)
{
     for(char ch:str)
    {
        if(ch!='0'&&ch!='1'&&ch!='2'&&ch!='3'&&ch!='4'&&ch!='5'&&ch!='6'&&ch!='7'&&ch!='8'&&ch!='9')
        {
            return false;
        }
    }
     int number = std::stoi(str);
     if(number>0&&number<=5)
     {
        return true;
     }
    return false;
}

bool SlotNumberCheck(std::string str) {
    for(char ch:str)
    {
        if(ch!='0'&&ch!='1'&&ch!='2'&&ch!='3'&&ch!='4'&&ch!='5'&&ch!='6'&&ch!='7'&&ch!='8'&&ch!='9')
        {
            return false;
        }
    }
     int number = std::stoi(str);
     if(number>0&&number<=10)
     {
        return true;
     }
    return false;
}

bool isValidVehicleNumber(const std::string& vehicleNumber) {
    // Regular expression pattern for a basic vehicle number
    std::regex pattern("[A-Z]{2}[0-9]{2}[A-Z]{2}[0-9]{4}");

    // Check if the vehicle number matches the pattern
    return std::regex_match(vehicleNumber, pattern);
}

bool isValidVehicleType(std::string str)
{
   for(char ch:str)
    {
        if(ch!='0'&&ch!='1'&&ch!='2'&&ch!='3'&&ch!='4'&&ch!='5'&&ch!='6'&&ch!='7'&&ch!='8'&&ch!='9')
        {
            return false;
        }
    }

     int number = std::stoi(str);
     if(number>=0&&number<=3)
     {
        return true;
     }
    return false;
    
}



bool isValidMobileNumber(const std::string& number) {
    // Regular expression to match a typical mobile number pattern
    std::regex pattern(R"(\d{10})"); // Assumes a 10-digit number
    
    // Check if the number matches the pattern
    return std::regex_match(number, pattern);
}