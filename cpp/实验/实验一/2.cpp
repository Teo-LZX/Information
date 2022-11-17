#include  <iostream>
using  namespace  std;
class  Date
{
public:
    Date()
    {
        cout<<"Input  Date:";
        cin>>y>>m>>d;
    }
    int  beLeapYear()
    {
        return  ((y%4==0&&y%100!=0) || (y%400==0));
    }
    void  addOneDay()
    {
        int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(beLeapYear()){
            if(m==2 && d==29){
                m++;
                d=1;
            }
            else{
                d++;
            }
        }
        else{
            if(d == months[m]){
                m++;
                d = 1;
            }
            else{
                d++;
            }
        }
        if(m==13){
            m=1;
            y++;
        }
      
    }
    void  showDate()
    {
        cout<<y<<"-"<<m<<"-"<<d<<endl;
    }
private:
    int  y,m,d;
    };
int  main()
{
      Date  d;
      d.showDate();
      d.addOneDay();
      d.showDate();
}