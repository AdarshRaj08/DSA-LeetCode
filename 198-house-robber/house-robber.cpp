class Solution {
public:
    int robb(vector<int>& nums, int idx, vector<int>&dp){
        if(idx >= nums.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        // take
        int take = nums[idx] + robb(nums, idx+2, dp); 
        // skip
        int skip = robb(nums, idx+1, dp);
        return dp[idx] = max(take,skip);
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return robb(nums,0, dp);
    }
};