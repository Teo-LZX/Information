#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    vector<int> dir_x{1, -1, 0, 0};
    vector<int> dir_y{0, 0, -1, 1};
    int n,m;
    void dfs(vector<vector<int>> &grid, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n)
            return;
        if(grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        for(int k=0;k<4;k++){
            dfs(grid, i+dir_x[k], j+dir_y[k]);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ret=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                     dfs(grid, i, j);
                     ret++;
                }
            }
        }
        return ret;
    }
};
int main()
{}