#include  <iostream>
using  namespace  std;
class  Exception
{
public:
        virtual  void  showMessage()=0;
};

class RangeError:public Exception
{
public:
    RangeError(const char* s): s(s) {}
    void showMessage() { cout << s; }
private:
    const char* s;
};


int  main()
{
        try
        {
                int  n;
                cout<<"Input  n(1<=n<=100):";
                cin>>n;
                if(n<1||n>100)
                    throw RangeError("Exception:Range Error!");
                cout<<"n:"<<n<<endl;
        }
        catch(Exception&  e)
        {
                e.showMessage();
        }
}