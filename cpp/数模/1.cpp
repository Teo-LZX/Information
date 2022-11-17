#include<iostream>
#include<vector>
using namespace std;
// tasks[i][j]表示第i项任务由第j个人完成所需时间
vector<vector<int> > tasks  = {{15, 19, 26, 19}, {18, 23, 17, 21}, {21, 22, 16, 23},{24, 18, 19, 17}};
int main(){
    int ans = 99999;
    for(int i=0;i<4;++i) {
        int t_time=0;
        t_time += tasks[0][i];
        for(int j=0;j<4;++j){
            if(i == j) continue;     //保证每个任务一个人做
            t_time += tasks[1][j];
            for(int k=0;k<4;++k){
                if(i == k || j == k) continue;             //保证每个任务一个人做
                t_time += tasks[2][k];
                for(int x=0;x<4;++x) {
                    if(x == i || x == j || x == k)continue;        //保证每个任务一个人做
                    t_time += tasks[3][x];cout << "i=" << i << "  j=" << j << "  k=" << k << "  x=" << x  << "  " << t_time  << endl;
                    ans = min(ans, t_time);   
                }
            }
        }
    }
    cout << ans << endl;   //输出结果
}