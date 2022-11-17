#include<iostream>
#include<vector>
#include<string>
using namespace std;

class People{
    protected:
        string name;
        int age;
    public:
        People() {
            cout << "People constructor1" << endl;
        }
        People(string name, int age): name(name), age(age) {
            cout << "People constructor2" << endl;
        } 
        ~People(){
            cout << "People destructor" << endl;
        }
};
class Student:public People{
    private:
        double score;
    public:
        Student() {
            cout << "Student constructor1" << endl;
        }      //必须要有People()
        Student(string name, int age, double score): People(name, age), score(score) {
            cout << "Student constructor2" << endl;
        }
        ~Student(){
            cout << "Student destructor" << endl;
        }
        void display(){
            cout << name << " " << age << " " << score << endl;
        }
};
int main()
{
    Student s[2];
}