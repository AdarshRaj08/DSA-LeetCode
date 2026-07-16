class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n, vector<int>(m,0));

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                
                // right
                if(j+1 < m && i+1 < n){
                    dp[i][j] = min(dp[i+1][j] , dp[i][j+1]) + grid[i][j];
                }
                else if(j+1 < m){
                    dp[i][j] = dp[i][j+1] + grid[i][j];
                }
                else if(i+1 < n){
                    dp[i][j] = dp[i+1][j] + grid[i][j];
                }
                else{
                    dp[i][j] = grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
};