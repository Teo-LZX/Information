#include  <iostream>
using  namespace  std;
const  float  pi=3.14;
class  SimpleCircle
{
public:
        SimpleCircle(){
            itsRadius = new float;
        }
        void  setRadius(float  r)
        {
                *itsRadius=r;
        }
        float  getRadius()
        {
                return  *itsRadius;
        }
        float  getArea()
        {
                return  (*itsRadius)*(*itsRadius)*pi;
        }
private:
        float  *itsRadius;
};

int  main()
{
        SimpleCircle  c;
        c.setRadius(10);
        cout<<"Area:"<<c.getArea()<<endl;
}