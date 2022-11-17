#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Cat{
    private:
        static int numOfCats;
    public:
        Cat(){numOfCats++;}
        static int getNumOfCats(){
            return numOfCats;
        }
};
int Cat:: numOfCats = 0;

int main()
{
    Cat c;
    cout<<"Num:"<<Cat::getNumOfCats()<<endl;
    Cat carr[4];
    cout<<"Num:"<<Cat::getNumOfCats()<<endl;
    return 0;
}