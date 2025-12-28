class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n - i; j++) {
                dfs(i, j, i, j, matrix);
            }
        }
    }

    void dfs(int i, int j, int li, int lj, vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ni = j;
        int nj = n - 1 - i;

        if (ni != li || nj != lj) {
            dfs(ni, nj, li, lj, matrix);
            
            int temp = matrix[i][j];
            matrix[i][j] = matrix[ni][nj];
            matrix[ni][nj] = temp;
        }
    }
};
