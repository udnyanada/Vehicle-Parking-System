#include "TimingDetails.h"
#include <ctime>



void TimingDetails::setEntryTime() {
    entryTime = std::chrono::system_clock::now();
    std::time_t now = std::chrono::system_clock::to_time_t(entryTime);
    date = std::ctime(&now);
}

void TimingDetails::setExitTime() {
    exitTime = std::chrono::system_clock::now();
}

std::string TimingDetails::getDate() const {
    return date;
}

std::chrono::time_point<std::chrono::system_clock> TimingDetails::getEntryTime() const {
    return entryTime;
}

std::chrono::time_point<std::chrono::system_clock> TimingDetails::getExitTime() const {
    return exitTime;
}

int TimingDetails::getHours() const {
    return std::chrono::duration_cast<std::chrono::hours>(exitTime - entryTime).count();
}
