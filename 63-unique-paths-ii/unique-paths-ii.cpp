class Solution {
public:
    int solve(int& m, int& n, int row, int col, vector<vector<int>>&dp, vector<vector<int>>&obstacle){
        if(row == m-1 && col == n-1)
            return 1;
        
        if(row == m || col == n)
            return 0;
        
        if(obstacle[row][col] == 1)
            return 0;
        
        if(dp[row][col] != -1){
            return dp[row][col];
        }

        return dp[row][col] = solve(m,n,row+1, col, dp, obstacle) + solve(m,n,row,col+1, dp, obstacle);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1] == 1)
            return 0;

        vector<vector<int>>dp(m, vector<int>(n,-1));

        return solve(m,n,0,0,dp,obstacleGrid);
    }
};