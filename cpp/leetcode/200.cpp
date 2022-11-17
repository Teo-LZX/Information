#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public: 
    int n, m;
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n)
            return;
        if(grid[i][j] == '0')
            return;
        grid[i][j] = 0;
        dfs(grid, i+1, j);  //下
        dfs(grid, i, j+1);  //右
        dfs(grid, i-1, j);  //上
        dfs(grid, i, j-1); //左
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ret = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                dfs(grid, i, j);
                ret++;
            }
        }
        return ret;
    }
};
int main()
{}