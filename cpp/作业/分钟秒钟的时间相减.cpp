#include  <iostream>
using  namespace  std;
#define  N  100

class CTime
{
public:
    CTime(int min, int sec):min(min), sec(sec) {}
    void input()
    {
        cin >> min >> sec;
    }
    bool beZero()
    {
        if(min == 0 && sec == 0)
            return true;
        return false;
    }
    int operator-(const CTime& t)
    {
        return (min-t.min)*60 + sec-t.sec;
    }
private:
    int min, sec;
};
int main()
{
    CTime time[N];
    int count=-1;
    do
    {
        count++;
        time[2*count].input();
        time[2*count+1].input();
    }while(!(time[2*count].beZero()&&time[2*count+1].beZero()));
    for(int  i=0;i<count;i++)
    {
        cout<<time[2*i+1]-time[2*i]<<endl;
    }
    return 0;
}
