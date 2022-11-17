#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]!=0)
            return;
        grid[i][j] = 1;
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0] == 0)
                dfs(grid, i, 0);
            if(grid[n-1][i] == 0)
                dfs(grid, n-1, i);
        }
        for(int j=0;j<n;j++){
            if(grid[0][j] == 0)
                dfs(grid, 0, j);
            if(grid[m-1][j] == 0)
                dfs(grid, m-1, j);
        }
        int ret=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
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