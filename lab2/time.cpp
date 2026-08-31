#include "time"

#include <cmath>
#include <cstdio>
Time::Time() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}
Time::Time(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
    normalize();
}

Time::~Time() {}

Time::Time(const Time& other) {
    this->hours = other.hours;
    this->minutes = other.minutes;
    this->seconds = other.seconds;
}
Time& Time::operator=(const Time& other) {
    if (this == &other) return *this;
    hours = other.hours;
    minutes = other.minutes;
    seconds = other.seconds;
    return *this;
}

Time Time::operator+(int value) const {
    Time result = *this;

    result.seconds += value;
    result.normalize();

    return result;
}
Time Time::operator-(int value) const {
    Time result = *this;

    result.seconds -= value;
    result.normalize();

    return result;
}
Time Time::operator*(int value) const {
    Time result = *this;

    result.hours *= value;
    result.minutes *= value;
    result.seconds *= value;
    result.normalize();

    return result;
}
Time Time::operator/(int value) const {
    if (value == 0) return *this;

    Time result = *this;

    result.hours /= value;
    result.minutes /= value;
    result.seconds /= value;
    result.normalize();

    return result;
}

void Time::normalize() {
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    } else if (seconds < 0) {
        int borrow = (abs(seconds) + 59) / 60;
        minutes -= borrow;
        seconds += borrow * 60;
    }

    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;

    } else if (minutes < 0) {
        int borrow = (abs(minutes) + 59) / 60;
        hours -= borrow;
        minutes += borrow * 60;
    }

    if (hours < 0) {
        hours = 0;
    }
}

void Time::print_time() const { printf("%02d:%02d:%02d\n", hours, minutes, seconds); }