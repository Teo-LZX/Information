#include<iostream>
#include<fstream>
using namespace std;

class Dog
{
public:
    int age, weight;
    Dog() {}
    Dog(int age, int weight): age(age), weight(weight) {}
};

int main()
{
    Dog dog1(10, 5);
    Dog dog2;
    const char* file = "./test.txt";
    fstream f;
    f.open(file, ios::out);
    f << dog1.weight << endl << dog1.age;
    f.close();
    fstream f2;
    f2.open(file, ios::in);
    f2 >> dog2.weight >> dog2.age;
    cout << "Weight:" << dog2.weight << " Age:" << dog2.age << endl;
    f2.close();
}