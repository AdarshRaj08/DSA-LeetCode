class Solution {
public:
    int helper(vector<int>& nums,int& target, int idx, int res,int& sum, vector<vector<int>>&dp){
        if(idx == nums.size()){
            if(res == target){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[idx][res + sum] != -1){
            return dp[idx][res+sum];
        }

        int minus = helper(nums, target, idx+1, res-nums[idx],sum, dp);
        int add   = helper(nums, target, idx+1, res+nums[idx],sum, dp); 
        dp[idx][res + sum] = minus + add;
        return minus + add;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }   
        vector<vector<int>>dp(n, vector<int>(2*sum+1,-1));
        return helper(nums,target,0,0,sum,dp);
    }
};