#include<iostream>
using namespace std;

class Rect
{
public:
    Rect(int a, int b):length(a), width(b) { cout << "构造Rect" << endl; }
    void perim()
    {
        cout << "Perim=" << (length+width)*2 << endl;
    }
    ~Rect() { cout << "析构Rect" << endl; }
private:
    int length, width;
};

int main()
{
    Rect myrect(5, 10);
    myrect.perim();
}