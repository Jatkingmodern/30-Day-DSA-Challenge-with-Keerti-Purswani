class Solution {
public:
    void dfs(int i,int j, int m, int n,vector<vector<int>>& matrix,vector<vector<bool>>& vis){
        vis[i][j] = true;
        for(int row = 0;row<m;row++){
            if(matrix[row][j] != 0){
                matrix[row][j] =0;
                vis[row][j] = true;
            }
        }
        for(int col = 0;col<n;col++){
            if(matrix[i][col] != 0){
                matrix[i][col] =0;
                vis[i][col] = true;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(matrix[i][j] == 0 && vis[i][j] == false){
                    dfs(i,j,m,n,matrix,vis);
                }
            }
        }
    }
};
