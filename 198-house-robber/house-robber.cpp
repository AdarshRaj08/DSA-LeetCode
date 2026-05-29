class Solution {
public:
    int amount(vector<int>&nums,int i, vector<int>&dp)
    {
        if(i >= nums.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        int take = nums[i] + amount(nums,i+2,dp);
        int skip = amount(nums,i+1,dp);

        return dp[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n,-1);

        return amount(nums,0,dp);
    }
};