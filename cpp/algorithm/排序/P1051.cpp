#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int scholarship(int s1, int s2, char ch1, char ch2, int num)
{
    int money = 0;
    if(s1 > 80)
    {
        //院士奖学金
        if(num>0)
            money += 8000;
        //五四奖学金
        if(s1 > 85 && s2 > 80)
            money += 4000;
        //成绩优秀奖
        if(s1 > 90)
            money  += 2000;
        //西部奖学金
        if(s1 > 85 && ch2 == 'Y')
            money += 1000;
    }
    //班级贡献奖
    if(s2 > 80 && ch1 == 'Y')
        money += 850;
    return money;
}

class student
{
public:
    string name;
    int scholarship;
    student(string name, int scholarship):name(name), scholarship(scholarship) {}
    bool operator<(student& p)
    {
        return scholarship<p.scholarship;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<student> stu;
    string name; 
    int s1, s2, num;
    char ch1, ch2;
    for(int i=0;i<N;i++)
    {
        cin >> name >> s1 >> s2 >> ch1 >> ch2 >> num;
        stu.push_back(student(name, scholarship(s1, s2, ch1, ch2, num)));
    }
    int a=0;
    num=0;
    for(int i=0;i<stu.size();i++)
    {
        if(stu[i].scholarship > a)
        {
            a = stu[i].scholarship;
            name = stu[i].name;
        }
        num += stu[i].scholarship;
    }
    cout << name << endl << a << endl << num;
}