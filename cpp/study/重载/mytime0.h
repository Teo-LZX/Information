#include<iostream>
using namespace std;
class Time
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    Time();
    Time(int h, int m=0, int s=0);
    void AddMin(int m);
    void AddHr(int h);
    void AddSec(int s);
    void Reset(int h=0, int m=0, int s=0);
    Time Sum(const Time & t) const;
    Time operator+(const Time& t) const;
    Time operator-(const Time& t) const;
    Time operator*(const double n) const;
    void Show() const;
    friend ostream& operator<<(ostream& os, const Time& t);
};
ostream& operator<<(ostream& os, const Time& t) 
{ 
    cout << t.hours << "hours,  " << t.minutes << "minutes,  " << t.seconds << "seconds" << endl;
    return os;
}

Time::Time()
{
    hours = minutes = 0;
}
Time::Time(int h, int m, int s)
{
    hours = h;
    minutes = m;
    seconds = s;
}
void Time::AddSec(int s)
{
    seconds += s;
    minutes += seconds/60;
    seconds %= 60;
}
void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes/60;
    minutes %= 60;
}
void Time::AddHr(int h)
{
    hours += h;
}
void Time::Reset(int h, int m, int s)
{
    hours = h;
    minutes = m;
    seconds = s;
}
Time Time::Sum(const Time& t) const
{
    Time sum;
    sum.seconds = seconds + t.seconds;
    sum.minutes = minutes + t.minutes + sum.seconds/60;
    sum.hours = hours + t.hours + sum.minutes/60;
    sum.seconds %= 60;
    sum.minutes %= 60;
    return sum;
}
Time Time::operator+(const Time& t) const
{
    Time sum;
    sum.seconds = seconds + t.seconds;
    sum.minutes = minutes + t.minutes + sum.seconds/60;
    sum.hours = hours + t.hours + sum.minutes/60;
    sum.seconds %= 60;
    sum.minutes %= 60;
    return sum;
}
Time Time::operator-(const Time& t) const
{
    Time sub;
    int tot1 = t.minutes - minutes;
    return sub;
}
Time Time::operator*(const double mult) const
{
    Time res;
    long totalminutes = hours * mult * 60 + minutes * mult;
    res.hours = totalminutes/60;
    res.minutes = totalminutes%60;
    return res;
}
void Time::Show() const
{
    cout << hours << "hours,  " << minutes << "minutes,  " << seconds << "seconds" << endl;
}