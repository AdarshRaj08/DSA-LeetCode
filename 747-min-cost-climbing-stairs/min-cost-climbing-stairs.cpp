class Solution {
public:
    int minfind(vector<int>& cost, int index, vector<int>&dp){
        if(index == 0 || index == 1){
            return cost[index];
        }
        if(dp[index] != -1){
            return dp[index];
        }
        return dp[index] = cost[index] + min(minfind(cost, index-1,dp), minfind(cost, index-2,dp));

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int index = cost.size();
        vector<int>dp(index,-1);
        return min(minfind(cost, index-1,dp), minfind(cost, index-2,dp));
    }
};