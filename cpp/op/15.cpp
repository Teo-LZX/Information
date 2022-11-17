#include <iostream> 
using namespace std;
class MyInt 
{ 
	int nVal; 
	public: 
	MyInt( int n) { nVal = n ;}
// 在此处补充你的代码
    MyInt& operator-(int n){
        nVal -= n;
        return *this;
    }
    operator int(){
        return nVal;    //??????????????????返回值。。。。。
    }
}; 

int Inc(int n) {
	return n + 1;
}
int main () { 
	int n;
	while(cin >>n) {
		MyInt objInt(n); 
		objInt-2-1-3; 
		cout << Inc(objInt.operator int());
		cout <<","; 
		objInt-2-1; 
		cout << Inc(objInt.operator int()) << endl;
	}
	return 0;
}