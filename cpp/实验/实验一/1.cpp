#include <iostream>

using namespace std;

class TAdd

{

public:

 TAdd(int a,int b)

 {

    x=a;y=b;

    cout<<"constructor."<<endl;

    cout<<x<<","<<y<<endl;

 }

 ~TAdd()

 {

    cout<<"destructor."<<endl;

    cout<<x<<","<<y<<endl;

  }

  int add(){return x+y;}

private:

  int x,y;

};

int main()
{
   TAdd p1(3,4);
   cout<<"x+y="<<p1.add()<<endl;
   TAdd p2(30,40);
   cout<<"x+y="<<p2.add()<<endl;
   return 0;

}