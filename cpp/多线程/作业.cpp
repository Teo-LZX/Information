#include<iostream>
#include<vector>
#include<thread>     //线程
#include<queue>     //队列
#include<mutex>     //互斥量
#include<atomic>    //原子量
#include<condition_variable>  //条件变量，用来阻塞进程
using namespace std;

int n,p;
atomic<int64_t> ok;
atomic<int64_t> value;  //原子量，表示当前线程数量的信号量
condition_variable con;   //全局条件变量
mutex m;  //全局互斥锁
queue<int> q;  //共享数据队列

void P() 
{
	value--;
	if(value<0)   //当前可用资源为0，将其阻塞
	{
		unique_lock<mutex> lk(m);
		con.wait(lk);
	}
}
void V()
{
	value++;
	if(value<=0)  //当前存在被阻塞的线程，则唤醒一个被阻塞的线程
		con.notify_one();
}
inline void judge(int i)   //判断n是否是N的因数
{
	P();    //申请一个线程资源
	//cout << "current_thread id: " << this_thread::get_id() << endl;
	if(n%i == 0)
	{
		m.lock();
		q.push(i);         //访问共享数据区q时要上锁
		m.unlock();
	}
	V();   //释放一个线程资源
	ok++;
}
int sum()        //对共享数据区的所有数求和
{
	int ans = 0;
	while(!q.empty())
	{
		ans += q.front();
		q.pop();
	}
	return ans;
}
void go()
{
	for(int i=1;i<=n/2;++i)  //将1到N分配给各个线程，保证每个线程不会分到同一个数
	{
		thread th(judge, i);
		th.detach();
	}
}
int main()
{
	cin >> n >> p;
	value = p;    //value信号量初值等于允许创建的线程数量p
	
	ok  = 0;    //设置信号量判断前面所有子线程是否结束
	thread th(go);
	th.join();
	while(ok<n/2) {}   //为了等待前面所有子线程结束
	int ans = sum();
	if(n == ans)
		cout << n << "是一个完全数" << endl;
	else
		cout << n << " 不是一个完全数" << endl;
}