class Solution {
public:
    int helper(int& m, int&n,vector<vector<int>>&grid, vector<vector<int>>&dp, int row, int col){
        if(row == m-1 && col == n-1){
            return grid[row][col];
        }
        if(row == m || col == n){
            return INT_MAX;
        }
        

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        dp[row][col] = grid[row][col] + min(helper(m,n,grid,dp,row+1,col), helper(m,n, grid,dp, row,col+1));

        return dp[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));


        

        return helper(m,n,grid,dp,0,0);
    }
};