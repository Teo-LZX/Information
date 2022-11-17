#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<iomanip>
#include<stack>
#include<algorithm>
using namespace std;

vector<string> names{"牛大", "牛二", "牛三",  "虎大", "虎二", "虎三"};
vector<vector<int>> valid_status;    //合法状态
vector<vector<int>> transition_status{{1,0,0,0,0,0}, 
                                                                                {1,1,0,0,0,0}, 
                                                                                {1,0,1,0,0,0}, 
                                                                                {1,0,0,1,0,0}, 
                                                                                {1,0,0,0,1,0},
                                                                                {1,0,0,0,0,1},
                                                                                {0,0,0,1,0,0},
                                                                                {0,1,0,1,0,0},
                                                                                {0,0,1,1,0,0},
                                                                                //{0,0,0,1,0,0},//
                                                                                {0,0,0,1,1,0},
                                                                                {0,0,0,1,0,1}};  //转移方法
vector<string> status{"100000", "110000", "101000", "100100", "100001", "000100", "010100",  "001100", "000110",
  "000101"};
  //---------------------------------------------------------------------------------------------------------------------------------------------------------
  vector<bool> visited;  //标志访问数组，DFS用
  vector<vector<int>> graph;   //DFS图
  vector<vector<int>> visitway;   //记录DFS的路径
  

bool valid(vector<int> &temp){  //判断状态是否合法
    int cattles=0, tigers=0;   //统计起点处牛和虎的数量，判断是否合法
    for(int i=0;i<3;i++)
        if(temp[i] == 0)
            cattles++;
    for(int i=3;i<6;i++)
        if(temp[i] == 0)
            tigers++;
    if(cattles == 3 || cattles == 0 || cattles == tigers)
        return true;
    return false;
}

vector<int> Xor(vector<int> &a, vector<int> &b){    //状态转移
    vector<int> temp(a.size(), 0);
    // for(int i=0;i<a.size();i++){
    //     if(a[0] == a[i]){
    //         for(int j=0;j<temp.size();j++)
    //             temp[j] = a[j] ^ b[j];
    //     }
    // }
    // for(int i=1;i<a.size();i++){
    //     if(a[3] == a[i]){
    //         for(int j=0;j<temp.size();j++)
    //             temp[j] = a[j] ^ b[j];
    //     }
    // }

    for(int i=0;i<6;i++){
        temp[i] = a[i] ^ b[i];
    }
    return temp;
}

vector<int> SB;
int locate(vector<int> &temp){      //查找temp状态在valid_status数组中的位置
    for(int i=0;i<valid_status.size();i++)
        if(temp == valid_status[i])
            return i;
    return -1;
}
void buildGraph(){        //建立图
    for(int i=0;i<valid_status.size();i++){
        vector<int> s;      //节点i的所有邻接点
        //cout << "i==" << i  << "          ----------------------------------------------------------" << endl;
        for(int j=0;j<transition_status.size();j++){
            vector<int> flag;

            for(int k=0;k<transition_status[j].size();k++)
                if(transition_status[j][k] == 1)
                    flag.push_back(k);
            
            if(flag.size() == 1 || valid_status[i][flag[0]] == valid_status[i][flag[1]]){
                vector<int> temp  = Xor(valid_status[i], transition_status[j]);
                //cout << "flag.size() = " << flag.size() << "     ";
                // if(valid(temp)){
                //     for(auto &it : temp)
                //          cout << it;
                //     cout << "j=" << j << "     "; 
                    int location = locate(temp);  //cout << "   "  << location; cout << endl;
                    if(location != -1 && !count(s.begin(), s.end(), location))
                        s.push_back(location);
                }
            }
            graph.push_back(s);
        }
    }

void tenTotwo(vector<int> &temp, int num){  //十进制转二进制
    int i=5;
    while(num>0){
        temp[i] = num%2;
        num /= 2;
        --i;
    }
}
// void DFS(int v){
//     visited[v] = true;
//     visitway.push_back(valid_status[v]);
//     SB.push_back(v);
//     // if(v == 4){
//     //     cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//     //     for(auto &it : graph[v])
//     //         cout << it << "*";
//     //     cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//     // }
//     for(int i=0;i<graph[v].size();i++){
//         int w = graph[v][i];
//         // if(w == 18){
//         //     cout << "~~~~~~~~~"  << v << "~~~~~~~~~~~~~~~~" << endl;
//         // }
//         if(!visited[w])
//             DFS(w);
//     }
// }
void print_transfer(vector<int> &last, vector<int> &now, int k){
    cout << "    第" << k << "次过河动物：";
    for(int i=0;i<6;i++){
        if(now[i] != last[i])
            cout << names[i];
    }
    //cout << setw(10);
    // if(k !=0){
    //     cout << "        ";
    //      if(k%2 == 1)
    //         cout << "起点 to 终点";
    //     else 
    //         cout << "终点 to 起点";
    // }
}
void show(){
    int k=0;
    vector<int> temp = visitway[0];  //记录当前状态的上一个状态，便于打印转移过程
    for(int i=0;i<visitway.size();i++){
       

        for(int j=0;j<visitway[i].size();j++){            //输出起始岸的动物
            if(visitway[i][j] == 0)
                cout << names[j] << " ";
        }
        cout  <<  "   |   "  ;
         for(int j=0;j<visitway[i].size();j++){        //输出终点岸的动物
            if(visitway[i][j] == 1)
                cout << names[j] <<  " ";
         }
        if(i != 0)
            print_transfer(temp, visitway[i], i);
        temp = visitway[i];
        cout << endl;
      
    }
}

void DFS2(){
    stack<int> s;
    s.push(0);
    while(!s.empty()){
        int cur = s.top();s.pop();
        visited[cur] = true;
        visitway.push_back(valid_status[cur]);
        SB.push_back(cur);
        if(cur == 33) break;    //到达终点结束
        for(int i=0;i<graph[cur].size();i++)
            if(!visited[graph[cur][i]])
                s.push(graph[cur][i]);
    }
}

int main()
{
    vector<int> temp(6, 0);
    for(int i=0;i<64;++i){                 //找到所有有效状态
        tenTotwo(temp, i);
        if(valid(temp))
             valid_status.push_back(temp);
    }
    visited.resize(valid_status.size(), false);
    buildGraph();
    // for(int i=0;i<graph.size();++i){
    //     cout << i << "    ";
    //         for(int k=0;k<valid_status[i].size();k++)
    //             cout << valid_status[i][k];
    //         cout << "    ";
    //         for(int j=0;j<graph[i].size();j++){
    //             cout << "  " << graph[i][j];
    //         }
    //         cout << endl;
    //         }

    DFS2();
    show();
   cout << valid_status.size() << endl;
   
}