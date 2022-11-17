#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int n, m, num;
    int flag;
    void dfs(vector<vector<int>>& image, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n)
            return;
        if(image[i][j] != flag)
            return;
        image[i][j] = num;
        dfs(image, i+1, j);
        dfs(image, i-1, j);
        dfs(image, i, j-1);
        dfs(image, i, j+1);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size(), n = image[0].size();
        num = newColor;
        flag = image[sr][sc];
        dfs(image, sr, sc);
        return image;
    }
};
int main()
{}