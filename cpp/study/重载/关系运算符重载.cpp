#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Person{
    private:
        string name;
        int age;
    public:
        Person(string s, int n): name(s), age(n) {}
        bool operator==(Person& p){
            if(p.name == name && p.age == age)
                return true;
            else
                return false; 
        }
};
int main()
{
    Person p1("tom", 18);
    Person p2("tom", 18);
    if(p1 == p2)
        cout << "p1 == p2" << endl;
}