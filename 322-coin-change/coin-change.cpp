class Solution {
public:
    long helper(vector<int>& coins, int amount, int idx, vector<vector<int>>&dp) {
        if(idx == coins.size()) {
            if(amount == 0)
                return 0;
            return INT_MAX;
        }
        if(dp[idx][amount] != -1)
            return dp[idx][amount];
        long skip = helper(coins, amount, idx + 1,dp);

        if(amount < coins[idx])
            return dp[idx][amount] = skip;

        long next = helper(coins, amount - coins[idx], idx,dp);

        long take = INT_MAX;
        if(next != INT_MAX)
            take = 1 + next;

        return dp[idx][amount] = min(skip, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;

        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));

        long ans = helper(coins, amount, 0,dp);

        if(ans == INT_MAX)
            return -1;

        return ans;
    }
};