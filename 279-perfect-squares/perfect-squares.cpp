class Solution {
public:
    bool isPerfectSquare(int n){
        int root = sqrt(n);

        return root*root == n;
    }

    int helper(int n, vector<int>&dp){
        if(isPerfectSquare(n))
            return 1;
        if(dp[n] != -1)
            return dp[n];
        int ans = n;

        for(int i=1; i*i<=n/2; i++){
            int count = helper(i*i,dp) + helper(n-(i*i),dp);

            ans = min(ans,count);
        }
        
        return dp[n] = ans;
    }

    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};