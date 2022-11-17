#include<bits/stdc++.h>
using namespace std;

class Resource       //资源类
{
public:
    Resource() { }
    Resource(int n):n(n) {}
    int n;         //资源数量
};

class Process
{
public:
    Process() {}
    Process(int p)       //n是资源个数
    {
        Max.resize(p);
        Allocation.resize(p);
        Need.resize(p);
    }
    vector<Resource> Max;  //最大需求
    vector<Resource> Allocation;  //已分配资源
    vector<Resource> Need;   //还需要的资源
    string name;  //进程名称
};
int n, p;
vector<int> work;
vector<Process> processes;
vector<int> order;

bool operator<=(const vector<Resource>& need, const vector<int>& work)  //<=运算符重载
{
    for(int i=0;i<work.size();++i)
        if(need[i].n > work[i])
            return false;
    return true;
}
void operator+=(vector<int>& work, vector<Resource>& need)   //+=运算符重载
{
    for(int i=0;i<work.size();++i)
    {
        work[i] += need[i].n;
    }
}
void operator-=(vector<int>& work, vector<int>& request)
{
    for(int i=0;i<work.size();++i)
    {
        work[i] -= request[i];
    }
}
void operator+=(vector<Resource>& Allocation, vector<int>& request)
{
    for(int i=0;i<Allocation.size();++i)
        Allocation[i].n += request[i];
}
void operator-=(vector<Resource>& Need, vector<int>& request)
{
    for(int i=0;i<Need.size();++i)
        Need[i].n -= request[i];
}
bool Safe(vector<Process>& processes, vector<int>& work)     //安全性检测--判断是否是安全状态
{
    vector<Process> processes2 = processes;   //拷贝一个副本
    vector<int> work2 = work;
    vector<bool> finish(processes2.size(), false);
    order.clear();
    for(int i=0;i<processes2.size();++i)
    {
        for(int j=0;j<processes2.size();++j)
        {
            if(finish[j] == false && processes2[j].Need <= work2)
            {
                work2 += processes2[j].Allocation;
                finish[j] = true;
                order.push_back(j);
            }
        }
    }
    for(int i=0;i<finish.size();++i)
        if(!finish[i])
        {cout << i;    return false;}        //只要有一个进程无法完成，返回false
    //此状态安全，将副本拷贝过来
    processes = processes2;
    work = work2;
    return true;
}

void Init()
{
    cout << "输入进程数量和资源种类：";
    cin >> n >> p;
    work.resize(p);
    processes.resize(n, Process(p));
    // cout << "输入Max矩阵：\n";
    // for(int i=0;i<n;++i)
    //     for(int j=0;j<p;j++)
    //         cin >> processes[i].Max[j].n;   //第i个进程对第j种资源的最大需求量
    cout << "输入Allocation矩阵：\n";
    for(int i=0;i<n;++i)
        for(int j=0;j<p;j++)
            cin >> processes[i].Allocation[j].n;   //第i个进程已经得到第j种资源的数量
    
    cout << "输入Need矩阵：\n";
    for(int i=0;i<n;++i)
        for(int j=0;j<p;j++)
            cin >> processes[i].Need[j].n;   //第i个进程对第j种资源的需求量
    // for(int i=0;i<n;++i)
    //     for(int j=0;j<p;j++)
    //         processes[i].Need[j].n = processes[i].Max[j].n - processes[i].Allocation[j].n;    //第i个进程对第j种资源的需求量
    cout << "输入当前可用资源数量：";
    for(int i=0;i<work.size();++i)
        cin >> work[i];
}

void request()
{
    int n;
    vector<int> request(p);
    cout << "请输入要请求资源的进程编号：";
    cin >> n;
    cout << "请输入请求的资源数量：";
    for(int i=0;i<p;++i)
        cin >> request[i];
    vector<int> work2 = work;  //先拷贝一个副本，避免等会安全性检测通不过
    vector<Process> processes2 = processes;
    if(request <= work2)
    {
        work2 -= request;
        processes2[n].Allocation += request;
        processes2[n].Need -= request;
        //work2 += processes2[n].Allocation;
        //processes2[n].Allocation.resize(processes2[n].Allocation.size(), Resource(0));  //释放此进程所有资源 
        if(!Safe(processes2, work2))
            cout << "分配后会进入不安全状态，分配失败!\n";
        else
        {
            cout << "此请求合法，分配成功！\n 各进程能够避免死锁的执行顺序如下：";
            for(auto &it : order)
                cout << "P" << it << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "请求资源大于可用资源，请求失败!\n";
    }
}
int main()
{   
    Init();
    char ch;
    while(true)
    {
        cout << "有程序要请求资源吗？ y/n: ";
        cin >> ch;
        if(ch == 'N' || ch == 'n')
            break;
        request();
    }
}