#include  <iostream>
#include  <string>
using  namespace  std;
class  Mammal
{
public:
        Mammal(string  name):name(name)
        {
                cout<<"Con.Mammal"<<endl;
        }
        ~Mammal()
        {
                cout<<"Des.Mammal"<<endl;
        }
protected:
        string  name;
};
class Dog: public Mammal{
    public:
        Dog(string name):Mammal(name) {
            cout << "Con.Dog:" << name << endl;
        }
        ~Dog(){
            cout << "Des.Dog:" << name << endl;
        }
};
int  main()
{
        string  name;
        cout<<"Input  Dog  Name:";
        cin>>name;
        Dog  d(name);
        return  0;
}