#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Box
{
private:
    /* data */
    double length;
    double height;
    double breadth;
public:
    double get_volume(){
        return this->length*this->breadth*this->height;
    }
    void show(){
        cout << this->length << " " << this->breadth << " " << this->height << endl;
    }
    void set_length(double length){
        this->length = length;
    }
    void set_height(double height){
        this->height = height;
    }
    void set_breadth(double breadth){
        this->breadth = breadth;
    }
    Box operator+(const Box& box){  //运算符重载函数
        Box temp(box.length+this->length, box.breadth+this->breadth, box.height+this->height);
        return temp;
    }
    Box(double length, double breadth, double height);
};


Box::Box(double length, double breadth, double height)
{
    set_height(height);
    set_breadth(breadth);
    set_length(length);   
}


class LiMoSi{
    //friend void lizhenxin(LiMoSi& limosi); //lizhenxin是全局友元函数，可以访问LIMOSI的私有成员
    friend class LiZhenXin;   //友元类
public:
    string name;
    int age;
    LiMoSi(){
        name = "李沫思";
        age = 19;
        wife = "李沫思的老婆";
        money = 999999999999999;
    }
private:
    long long int money;
    string wife;
};


class LiZhenXin{
public:
    LiZhenXin(){
        l = new LiMoSi;
    }
    void take(){
        cout << l->name << " " << l->age << " " << l->money << " " << l->wife << endl;
    }
private:
    LiMoSi *l;
};

//友元函数可以访问类的私有成员
// void lizhenxin(LiMoSi &limosi){    //全局友元函数
//     cout  << limosi.name << " " << limosi.age << " " << limosi.money << " " <<limosi.wife << endl;
// }

void test_lizhenxin(){
    // LiMoSi limosi;
    // cout << "全局函数:" << lizhenxin(limosi) <<endl;
    LiZhenXin lizhenxin;
    lizhenxin.take();
    cout <<"友元类:" <<lizhenxin.take()
}


int main()
{
    Box box1(1,2,3);
    Box box2(4,5,6);
    Box box3(3,2,1);
    Box box4 = box1 + box2 + box3;
    box4.show();
    cout << box4.get_volume() << endl;
    //test_lizhenxin();
}









//--------------------------------------------------------------------------------------------------------
// #include <iostream> 
// using namespace std;
// class MyInt 
// { 
// 	int nVal; 
// 	public: 
// 	MyInt( int n) { nVal = n ;}
// // 在此处补充你的代码
//     void operator-(int n){
//         nVal -= n;
//     }
// }; 
// int Inc(int n) {
// 	return n + 1;
// }
// int main () { 
// 	int n;
// 	while(cin >>n) {
// 		MyInt objInt(n); 
// 		objInt-2-1-3; 
// 		cout << Inc(objInt);
// 		cout <<","; 
// 		objInt-2-1; 
// 		cout << Inc(objInt) << endl;
// 	}
// 	return 0;
// }

