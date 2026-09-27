class Solution {
public:
    // applying recursion from (0,0) to goal

    int helper(int& m, int& n, vector<vector<int>>&dp, int row, int col){
        if(row == m-1 || col == n-1){
            return 1;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }


        return dp[row][col] = helper(m,n,dp, row+1, col) + helper(m,n,dp, row, col+1);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));

        return helper(m,n,dp, 0, 0);

    }
};