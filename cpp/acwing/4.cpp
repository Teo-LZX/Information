#include "iostream"
#include "vector"
using namespace std;

/*有 N 种物品和一个容量是 V 的背包。

第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。*/


// 将多重物品展开，变成01背包问题
// 状态转移方程：f[j] = max(f[j], f[j-v[i]] + w[i])

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> s(N+1), v(N+1), w(N+1);
    for(int i=1;i<=N;i++) 
        cin >> v[i] >> w[i] >>s[i];
    for(int i=1;i<s.size();i++){
        while(s[i]>1){
            v.push_back(v[i]);
            w.push_back(w[i]);
            s[i]--;
        }
    }
    
    vector<int> f(V+1, 0);  
    N = v.size() - 1;  //物品数量发生了变化
    for(int i=1;i<=N;i++){
        // 注：一维数组要倒着遍历
        for(int j=V;j>0;j--){
            if(j>=v[i]) f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }
    cout << f[V] << endl;
}