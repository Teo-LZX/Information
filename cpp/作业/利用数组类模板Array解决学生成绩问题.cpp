#include<iostream>
using namespace std;
template<class T>
class Array
{
public:
    void input(int n)
    {
        for(int i=0;i<n;++i)
            cin >> a[i];
    }
    T average(int n)
    {
        T avg = 0;
        for(int i=0;i<n;++i)
        {
            avg += a[i];
        }
        return avg/n; 
    }
private:
    T a[1000];
};
int main()
{
    int n;
    cout << "Input n:";
    cin >> n;
    cout << "Input scores:";
    Array<double> A;
    A.input(n);
    cout << "Average:" << A.average(n);
}