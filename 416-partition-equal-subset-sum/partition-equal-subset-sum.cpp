class Solution {
public:
    bool helper(vector<int>& nums, int idx, int sum, int& totalsum,
                vector<vector<int>>& dp) {

        if (idx == nums.size()) {
            return (totalsum - sum == sum);
        }

        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }

        bool skip = helper(nums, idx + 1, sum, totalsum, dp);

        if (skip) {
            return dp[idx][sum] = true;
        }

        bool take = helper(nums, idx + 1, sum + nums[idx], totalsum, dp);

        return dp[idx][sum] = take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;

        for (int x : nums) {
            totalsum += x;
        }

        // Odd total cannot be divided into two equal subsets
        if (totalsum % 2 != 0) {
            return false;
        }

        vector<vector<int>> dp(n, vector<int>(totalsum + 1, -1));

        return helper(nums, 0, 0, totalsum, dp);
    }
};