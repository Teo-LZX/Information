#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> graph;
vector<string> names{"人", "狗", "鸡",  "米"};
vector<string> status{"0000", "0001", "0010", "0100", "0101", "1010", "1011",  "1101", "1110",  "1111"};
vector<vector<int>> valid_status{{0,0,0,0,}, {0,0,0,1}, {0,0,1,0}, {0,1,0,0}, {0,1,0,1}, {1,0,1,0}, {1,0,1,1},  {1,1,0,1}, {1,1,1,0}, {1,1,1,1}};
vector<vector<int>> transition_status{{1,0,0,0}, {1,1,0,0}, {1,0,1,0}, {1,0,0,1}};
vector<bool> visit(10, false);  //标志访问数组，记录每个节点是否访问
vector<string> visited; //记录访问路径
int locate(vector<int> &temp){
    for(int i=0;i<valid_status.size();i++)
        if(valid_status[i] == temp)
            return i;
    return -1;
}
bool judge(vector<int> &temp){
    for(auto &it:valid_status)
        if(it == temp)
            return true;
    return false;
}
vector<int> Xor(vector<int> &a, vector<int> &b){
    vector<int> temp(a.size());
    for(int i=0;i<a.size();i++)
        temp[i] = a[i]^b[i];
    return temp;
}
void buildGraph(){
    for(int i=0;i<valid_status.size();i++){
        vector<int> s;
        for(auto &it :transition_status){
            vector<int> temp  = Xor(it, valid_status[i]);
            if(judge(temp))
                s.push_back(locate(temp));
        }
        graph.push_back(s);
    }
}
bool status_ok(string &s){
    if(s[0] == s[1] == s[2] == s[3] == '1')
        return true;
    return false;
}
void DFS(int v){
    if(status_ok(status[v]))
        return;
    visit[v] = true;
    visited.push_back(status[v]);
    //cout << status[v];// << graph[v].size() <<endl;
    //cout << "   ";
    // for(int i=0;i<status[v].size();i++)
    //     if(status[v][i] == '0')
    //         cout << names[i];
    // cout << " | ";
    //  for(int i=0;i<status[v].size();i++)
    //     if(status[v][i] == '1')
    //         cout << names[i];
    //cout << endl;
    
    for(int i=0;i < graph[v].size();i++){
        int w = graph[v][i];
        if(visit[w] == false)
            DFS(w);
    }
    //cout << endl;
}


int main()
{
    buildGraph();
    DFS(0);
    //cout << "adsffffffffffffffffff" << endl;
    // for(int i=0;i<graph.size();i++){
    //     for(int j=0;j<graph[i].size();j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
   for(int i=0;i<visited.size();i++){
       cout << visited[i]  << "  ";
       for(int j=0;j<visited[i].size();j++)
            if(visited[i][j] == '0')
            cout << names[j];
        cout << " | ";
        for(int j=0;j<visited[j].size();j++)
            if(visited[i][j] == '1')
            cout << names[j];
        cout << endl;
   }

}

// #include<iostream>
// #include<vector>
// #include<string>
// #include<unordered_map>
// using namespace std;

// vector<vector<int>> valid_status{{0,0,0,0,}, {0,0,0,1}, {0,0,1,0}, {0,1,0,0}, {0,1,0,1}, {1,0,1,0}, {1,0,1,1},  {1,1,0,1}, {1,1,1,0}, {1,1,1,1}};
// vector<vector<int>> transition_status{{1,0,0,0}, {1,1,0,0}, {1,0,1,0}, {1,0,0,1}};
// vector<vector<int>> visited;

// // class CrossRiver
// {
//     private:
//         vector<int> status;
//         bool status_valid(vector<int> &temp){       //判断当前状态是否合法
//             for(auto &it : visited)          //如果已经走过，则放弃此状态
//                 if(it == temp)
//                     return false;
//             for(auto &it : valid_status)
//                 if(it == temp)
//                     return true;
//             return false;
//         }

//          bool StatusOK(){                   //已经到达终点状态
//             if(status[0] == status[1] == status[2] == status[3] == 1)
//                 return true;
//             return false;
//         }
        
//     public:
//     void show(){
//             for(auto&it : visited){
//                 for(auto&it2 : it){
//                     cout << it2 << " ";
//                 }
//                 cout << endl;
//             }
//         }
//         CrossRiver(){
//             status.resize(4, 0);
//         }
//         void NextStatus(){       //回溯
//             if(StatusOK()){
//                 show();
//                 return;
//             }
//             for(auto &it : transition_status){
//                 vector<int> temp(4);
//                 for(int i=0;i < it.size();i++)
//                     temp[i] = status[i] ^ it[i];
//                 if(status_valid(temp) ){
//                     status = temp;
//                     visited.push_back(status);
//                     NextStatus();
//                 }
//             }
//         }
// };
// int main()
// {
//     CrossRiver crossriver;
//     crossriver.NextStatus();
//     crossriver.show();
// }