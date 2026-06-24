class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        if(nums[0] < nums[n-1]) return nums[0];

        int l = 0,r = n-1;
        int num = INT_MAX;

        while(l <= r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] > nums[r]) l = mid + 1;
            else
            {
                num = min(num,nums[mid]);
                r = mid-1;
            }
        }

        return num;
    }
};