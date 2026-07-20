class Solution {
public:
    // dp[i] stores maximum money that can be robbed till index i
    // WITHOUT robbing adjacent houses.
    
    // int amount(vector<int>&nums,int i, vector<int>&dp)
    // {
    //     if(i >= nums.size())
    //         return 0;
        
    //     if(dp[i] != -1)
    //         return dp[i];
    //     int take = nums[i] + amount(nums,i+2,dp);
    //     int skip = amount(nums,i+1,dp);

    //     return dp[i] = max(take,skip);
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<int>dp(n,-1);

    //     return amount(nums,0,dp);
    // }


    // **TABULATION METHOD** 
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        vector<int> t(n+1,0);
        // t[i] : denotes max stolen money till i house;

        // no house
        t[0] = 0;

        t[1] = nums[0];

        for(int i=2; i<=n; i++){
            int steal = nums[i-1] + t[i-2];
            int skip  = t[i-1];

            t[i] = max(steal,skip);
        }

        return t[n];
       
    }
};