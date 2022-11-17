// #include<iostream>
// #include<string>
// using namespace std;

// class Person
// {
// public:
//     friend ostream& operator<<(ostream& os, Person& p);
//     Person(string name, int age):name(name), age(age) {}
// private:
//     string name;
//     int age;
// };
// ostream& operator<<(ostream& os, Person& p)
// {
//     cout << "name:" << p.name << "  age:" << p.age;
//     return os;
// }
// class A
// {
// public:
// 	int a;
//     A() {}
// 	A(int a):a(a) {}
// 	A operator+(A& p)     //+运算符重载
// 	{
// 		A sum;
//         sum.a = this->a + p.a;
//         return sum;
// 	}
// };
// int main()
// {
//     string s = "hello";
//     Person p("tom", 20);
//     cout << p << endl;
//     operator<<(cout, p) << endl;
//     // A x(100), y(200);
//     // A z = x.operator+(y);
//     // cout << z.a << endl;
//     operator<< (cout, s);
// }

#include<iostream>
using namespace std;
class Person
{
public:
    friend ostream& operator<<(ostream& os, const Person& p);  //声明operator<<为友元函数
    Person(string name, int age):name(name), age(age) {}
private:
    string name;
    int age;
};
ostream& operator<<(ostream& os, const Person& p)
{
    cout << "name:" << p.name << "  age:" << p.age << endl;
    return os;
}
int main()
{
    Person p("tom", 20);
    cout << p;
    Person p1("bob", 25), p2("jack", 18);
    cout << p1  << p2;
}
