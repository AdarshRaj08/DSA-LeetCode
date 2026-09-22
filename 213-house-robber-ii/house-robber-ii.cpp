class Solution {
public:

    int solve(vector<int>& nums, int idx, int end, vector<int>& dp){

        if(idx > end)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int take = nums[idx] + solve(nums, idx + 2, end, dp);

        int skip = solve(nums, idx + 1, end, dp);

        return dp[idx] = max(take, skip);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 = solve(nums, 0, n - 2, dp1);

        int case2 = solve(nums, 1, n - 1, dp2);

        return max(case1, case2);
    }
};