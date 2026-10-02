class Solution {
public:
    long long f(int index, int parity, vector<int>& nums, int &x, vector<vector<long long>>&dp){
        // base condition
        if(index == nums.size())
            return 0;
        
        // already calculated
        if(dp[index][parity] != -1){
            return dp[index][parity];
        }

        // pick
        long long pick = 0;
        if(nums[index] % 2 == parity)
            pick = nums[index] + f(index+1, parity, nums, x, dp);
        else
            pick = nums[index] - x + f(index+1, !parity, nums, x, dp);
        
        // not pick
        long long notPick = f(index+1, parity, nums, x, dp);

        return dp[index][parity] = max(pick, notPick);
    }

    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2,-1));
        return nums[0] + f(1,nums[0]%2, nums, x, dp);
    }
};