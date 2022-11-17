#include<iostream.h>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

class CCard
{
public:
	CCard(string id, string psd):id(id), psd(psd) {}
	void deposit(float m) 
	{
		money += m;
		cout << "还款成功"  << endl;
	}
	void draw(float m) 
	{
		if(money>=m)
		{
			money -= m;
			cout << "取款成功" << endl;
		}
		else
			cout << "余额不足" << endl;
	}
	void ShowMoney()
	{
		cout << "余额: " << money << endl; 
	}
private:
	string id, psd;
	static float money;
};

float CCard:: money=0;

class CBase
{
public:
	virtual void show() { cout << "Base Class!" << endl; }
};
class Derived:public CBase
{
public:
	virtual void show() { cout << "Derived Class!" << endl; }
};
void fun(CBase b)
{
	b.show();
}

class S
{
public:
	S()
	{
		x++;
		cout << "create" << x << "student" << endl;
	}
	~S()
	{
		x--;
		cout << "there are" << x << "student" << endl;
	}
private:
	static int x;	
};
int S::x=0;

int main()
{
	// string s = "abc";
	// cout.width(10);
	// cout.fill('#');
	// cout << s << endl;
	//cout  << setw(10) << setiosflags(ios_base::right) << s << endl;
	// CCard c("123", "bob");
	// c.deposit(1000);
	// c.draw(500);
	//c.ShowMoney();
	// string s, s1;
	// getline(cin, s);
	// getline(cin, s1);
	// cout << s << "  " << s1 << endl;
	// CBase base;
	// Derived derived;
	// fun(base);
	// fun(derived);
	// ifstream f("test.txt");
	// char ch=f.get();
	// while(ch != EOF)
	// {
	// 	cout << f.get() << endl;
	// 	ch = f.get();
	// }

	S s1,s2,s3;
	S* p = new S;
	delete p;
}