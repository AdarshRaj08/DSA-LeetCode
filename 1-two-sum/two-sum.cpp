class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int findnum = target-nums[i];
            if(mp.find(findnum) != mp.end(findnum))
            {
                return {i,mp[findnum]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};