class Solution {
public:
    int helper(vector<int>& nums,int target, int idx, int sum, vector<vector<int>>&dp){
        if(idx == nums.size()){
            if(target == 0){
                return 1;
            }
            else{
                return 0;
            }
        }

        // if(dp[idx][(target-sum) + sum] != -1){
        //     return dp[idx][target-sum];
        // }

        int minus = helper(nums, target-nums[idx], idx+1, sum, dp);
        int add   = helper(nums, target+nums[idx], idx+1, sum, dp); 
        // dp[idx][sum] = minus + add;
        return minus + add;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }   
        vector<vector<int>>dp(n, vector<int>(2*sum,-1));
        return helper(nums,target,0,sum,dp);
    }
};