#include <iostream>
#include <iomanip>
#include <fstream>

// Time class definition
class Time {
private:
    int hour;
    int minute;

public:
    // Default constructor
    Time() : hour(0), minute(0) {}

    // Constructor with hour and minute validation
    Time(int hourVal, int minuteVal) {
        // Validate and set the hour
        if (hourVal >= 0 && hourVal <= 24) {
            this->hour = hourVal;
        } else {
            this->hour = 0;
        }

        // Validate and set the minute
        if (minuteVal >= 0 && minuteVal < 60) {
            this->minute = minuteVal;
        } else {
            this->hour += minuteVal / 60;
            this->minute = minuteVal % 60;
        }
    }

    // Setter for time
    void setTime(int h, int m) {
        hour = h;
        minute = m;
    }

    // Getters for hour and minute
    int getHour() const {
        return hour;
    }

    int getMinute() const {
        return minute;
    }

    // Overload the output stream operator
    friend std::ostream& operator <<(std::ostream& out, const Time &time);

    // Overload the addition operator
    Time operator +(const Time& time2) const {
        int tmpHour = hour + time2.hour;
        int tmpMinute = minute + time2.minute;

        // Adjust minutes and hours
        if (tmpMinute >= 60) {
            tmpHour += tmpMinute / 60;
            tmpMinute %= 60;
        }

        if (tmpHour >= 24) {
            tmpHour %= 24;
        }

        return Time(tmpHour, tmpMinute);
    }
};

// Implementation of the overloaded output stream operator
std::ostream& operator <<(std::ostream& out, const Time &time) {
    out << std::setw(2) << std::setfill('0') << time.hour 
        << ":" 
        << std::setw(2) << std::setfill('0') << time.minute;
    return out;
}

// Function to find the lowest time in an array of Time objects
Time lowestTime(Time times[4]) {
    int minIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (times[i].getHour() < times[minIndex].getHour() || 
            (times[i].getHour() == times[minIndex].getHour() && times[i].getMinute() < times[minIndex].getMinute())) {
            minIndex = i;
        }
    }
    return times[minIndex];
}

int main() {
    // Read time data from file
    Time times[4];
    std::ifstream inFile("data2.dat");

    if (!inFile) {
        std::cerr << "Unable to open file.\n";
        return 1;
    }

    int hour, minute;
    int index = 0;
    while (inFile >> hour >> minute && index < 4) {
        times[index].setTime(hour, minute);
        index++;
    }

    inFile.close();

    // Demonstrate addition of two Time objects
    Time time1(5, 23);
    Time time2(23, 42);
    Time time3 = time1 + time2;
    std::cout << time1 << " + " << time2 << " = " << time3 << std::endl;

    // Display all times read from the file
    for (int i = 0; i < 4; i++) {
        std::cout << "Time " << std::to_string(i + 1) << " = " << times[i] << std::endl;
    }

    // Display the lowest time
    std::cout << "The earliest time is: " << lowestTime(times) << std::endl;

    return 0;
}
