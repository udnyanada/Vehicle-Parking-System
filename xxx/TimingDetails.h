#ifndef TIMINGDETAILS_H
#define TIMINGDETAILS_H

#include <string>
#include <chrono>
//class TimingDetails


class TimingDetails {
    private:
    std::string date;
    std::chrono::time_point<std::chrono::system_clock> entryTime;
    std::chrono::time_point<std::chrono::system_clock> exitTime;

public:
    
    TimingDetails() = default;
    TimingDetails(const TimingDetails&) = default;
    TimingDetails(TimingDetails&&) = delete;
    TimingDetails& operator=(const TimingDetails&) = default;
    TimingDetails& operator=(TimingDetails&&) = delete;
    ~TimingDetails() = default;
    void setEntryTime();
    void setExitTime();
    std::string getDate() const;
    std::chrono::time_point<std::chrono::system_clock> getEntryTime() const;
    std::chrono::time_point<std::chrono::system_clock> getExitTime() const;
    int getHours() const;


};

#endif // TIMINGDETAILS_H
