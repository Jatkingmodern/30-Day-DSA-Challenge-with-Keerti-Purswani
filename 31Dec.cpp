class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& vec) {
        int n=vec.size();
        int m=vec[0].size();
       // Make a dp of size M*N to store the minimum cost. 
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        // Simple bottom up approach.
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int x=0;
                if(i==n-1&&j==m-1)
                    x=vec[i][j];
               else if(i==n-1)
                    x=vec[i][j]+dp[i][j+1];
                else if(j==m-1)
                    x=vec[i][j]+dp[i+1][j];
                else
                    x=max(dp[i+1][j],dp[i][j+1])+vec[i][j];
                dp[i][j]=x>0?0:x;
            }
        }
        return abs(dp[0][0])+1;
    }
};
