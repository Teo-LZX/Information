#include<bits/stdc++.h>
using namespace std;

template<class T>
class My_priority_queue
{
public:
    My_priority_queue() {}
    My_priority_queue(vector<T> &t);
    void insert(const T& t);
    void front();
    void pop();
    void show();
private:
    vector<T> q;
    void PercolateDown(int i);
    void pre_order(int i);
};
template<class T>
My_priority_queue<T>::My_priority_queue(vector<T>& t)
{
    int n = t.size();
    q.resize(1);
    for(auto& ch:t)
        q.push_back(ch);
    for(int i=q.size()/2;i>0;--i)
        PercolateDown(i);  
}
template<class T>
void My_priority_queue<T>::PercolateDown(int i)  //建堆
{
    int child;
    int n = q.size();
    T tmp;
    for(tmp=q[i];2*i<n;i=child)
    {
        child = 2*i;     //节点i的左孩子
        if(child != n-1 && q[child]>q[child+1])
            child++;
        if(tmp > q[child])
            q[i] = q[child];
        else
            break;
    }
    q[i] = tmp;
}
template<class T>
void My_priority_queue<T>::insert(const T &t)
{
    int i;
    T tmp = t;
    q.push_back(tmp);
    for(i=q.size();q[i]<t;i/=2)
        q[i] = q[i/2];
    q[i] = t;
}
template<class T>
void My_priority_queue<T>::show()
{
    
    pre_order(1);
    //cout << endl << q.size();
}
template<class T>
void My_priority_queue<T>::pre_order(int i)
{
    if(i>q.size())
        return;
    cout << q[i] << " ";
    pre_order(2*i);
    pre_order(2*i+1);
}
int main()
{
    vector<int> a = {2,3,1,6,5,4};
    My_priority_queue<int> q(a);
    q.show();
    //q.insert(4);
}