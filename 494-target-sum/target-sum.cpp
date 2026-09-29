class Solution {
public:
    int helper(vector<int>& nums,int& target, int idx, int sum, vector<vector<int>>&dp){
        if(idx == nums.size()){
            if(sum == target){
                return 1;
            }
            else{
                return 0;
            }
        }

        // if(dp[idx][target-sum] != -1){
        //     return dp[idx][target-sum];
        // }

        int minus = helper(nums, target, idx+1, sum-nums[idx], dp);
        int add   = helper(nums, target, idx+1, sum+nums[idx], dp); 
        // dp[idx][sum] = minus + add;
        return minus + add;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        vector<vector<int>>dp(n, vector<int>(sum+1,-1));
        return helper(nums,target,0,0,dp);
    }
};