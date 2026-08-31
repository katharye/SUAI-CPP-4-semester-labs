#ifndef TIME_H
#define TIME_H

class Time 
{
private:
    int hours;
    int minutes;   
    int seconds;   
    
    void normalize();  

public:
    Time();
    explicit Time(int h, int m = 59, int s = 59);
    
    ~Time();

    Time(const Time& other);    
    Time& operator=(const Time& other);

    Time operator+(int value) const;
    Time operator-(int value) const;
    Time operator*(int value) const;
    Time operator/(int value) const;

    void print_time() const;  
};

#endif