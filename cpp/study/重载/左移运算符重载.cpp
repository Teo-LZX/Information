#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Student{
    friend void operator<<(ostream &out, Student &p){
        cout << p.name << "  " << p.age << endl;
    }
    private:
        string name;
        int age;
    public:
        Student(string name, int age): name(name), age(age) {}
       // Student operator+;
};
int main()
{
    Student s("tom", 99);
    cout << s;
}