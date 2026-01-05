class Solution {
private:
    int dfs(vector<vector<int>>& grid , int i , int col){
        if(i == grid.size()) return col;
        int next = col + grid[i][col];
        if (next < 0 || next == grid[0].size() || grid[i][col] != grid[i][next]) return -1;
        return dfs(grid , i + 1 , next);
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n, -1);
        for (int j = 0; j < n; ++j) res[j] = dfs(grid , 0 , j);
        return res;
    }
};
