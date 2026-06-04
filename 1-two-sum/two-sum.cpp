class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int remaining = target-nums[i];
            if(mp.find(remaining) != mp.end(remaining))
            {
                return {i,mp[remaining]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};