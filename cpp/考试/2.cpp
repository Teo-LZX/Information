#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
    string name;
    char sex;
    int age;
    Person(string name, char sex, int age):name(name), sex(sex), age(age) {}
    void show()
    {
        cout << "姓名:" << name << endl;
        cout << "性别:" << sex << endl;
        cout << "年龄:" << age << endl;
    }
};
class Student:public Person
{
public:
    int num;
    float score;
    Student(int num, string name, char sex, int age, float score): Person(name, sex, age), num(num), score(score) {}
     void show()
    {
        if (num<=0 || score<0)
        {
            cout << "信息错误!" << endl;
        }
        else
        {
            cout << "学号:" << num << endl;
            cout << "姓名:" << name << endl;
            cout << "性别:" << sex << endl;
            cout << "年龄:" << age << endl;
            cout << "成绩:" << score << endl;
        }
        
    }
};
int main()
{
    string name;
    char sex;
    int age,num;
    float score;
    cin >> num >> name >> sex >> age >> score;
    if(age<=0 || !(sex=='w' || sex=='W' || sex=='M' || sex=='m'))
    {
        cout << "信息错误!" << endl;
        return 0;
    }
    Person p(name, sex, age);
    p.show();
    cout << endl;
    Student s(num, name, sex, age, score);
    s.show();
    return 0;
}