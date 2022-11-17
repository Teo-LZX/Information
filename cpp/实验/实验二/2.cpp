#include  <iostream>
#include  <string>
using  namespace  std;

class  Employee
{
public:
        Employee();
        void  display();
private:
        static  int  base_id;
        int  id;
        string  name;
};
int Employee::base_id=1000;
Employee:: Employee(){
    cout << "Input name:";
    cin >> name;
}
void Employee::display(){
    cout << "ID:" << base_id << " Name:" << name << endl;
    base_id++;
}

int  main()
{
        Employee  e1;
        Employee  e2;
        e1.display();
        e2.display();
        return  0;
}