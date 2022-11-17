#include <iostream>
using namespace std;

/* 你需要补充代码 */
class Mammal
{
public:
    virtual void speak() = 0;
};
class Dog:public Mammal
{
public:
    void speak()
    {
        cout << "Dog is speaking!\n";
    }
};

int main()
{
    Dog dog;
    Mammal *p;
    dog.speak();
    p=&dog;
    p->speak();
    return 0;
}

