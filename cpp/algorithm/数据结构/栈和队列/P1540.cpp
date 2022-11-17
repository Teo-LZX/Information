#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    queue<int> q;
    unordered_set<int> nums;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int a; cin >> a;
        if(nums.count(a) == 0)  //内存中没有该单词
        {
            if(q.size()<m)         //内存容量够，将单词调入内存
            {
                q.push(a);
                nums.insert(a);
                res +=1 ;
            }
            else                 //容量不够，删除队头，插入新单词
            {
                nums.erase(nums.find(q.front()));
                q.pop();
                res += 1;
                q.push(a);
                nums.insert(a);
            }
        }
    }
    cout << res;
    return 0;
}