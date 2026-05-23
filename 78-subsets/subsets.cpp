class Solution {
public:
    void helper(vector<int>& nums, vector<int> ans, int idx, vector<vector<int>> &subsetsVect)
    {
        if(nums.size() == idx)
        {
            subsetsVect.push_back(ans);
            return;
        }

        helper(nums, ans, idx+1, subsetsVect);  
        ans.push_back(nums[idx]);        // skip
        helper(nums, ans, idx+1, subsetsVect);   // pick
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsetsVect;
        vector<int> ans;
        helper(nums, ans, 0, subsetsVect);

        return subsetsVect;
    }
};