#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Person{
    private:
        int *age;
    public:
        Person(int n){
            age = new int(n);
        }
        void set_age(int n){
            *age = n;
        }
        void show_age(){
            cout << *age << endl;
        }
        Person& operator=(Person& p){  //只能返回引用，返回值的话会调用拷贝构造函数，
            if(age != NULL){
                delete age;
                age = NULL;
            }
            age  = new int(*p.age); //做深拷贝
            return *this;    //返回对象本身
        }
        ~Person(){
            delete age;
        }
};

void test(){
    Person p(18);
    Person p2(20);
    Person p3(30);
    p2 .operator=(p);    //没有=重载的时候，这里是浅拷贝，p2和p指向的内存地址相同
   // p2.operator=(p); 
    p.show_age();
    p2.show_age();
    p3.show_age();
}
int main()
{
    test();
}


