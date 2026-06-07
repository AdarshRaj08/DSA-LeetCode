class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int pivotIndex = -1;
        for(int &num : nums)
        {
            sum += num;
        }

        int left = 0;
        int right = 0;
        for(int i=0; i<n; i++)
        {
            right = sum - left - nums[i];
            if(left == right)
            {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};