class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int closetSum = nums[0] + nums[1] + nums[2];

        for(int i=0; i<n-2; i++)
        {
            int left = i+1;
            int right = n-1;

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                int diff1 = abs(target - sum);
                int diff2 = abs(target - closetSum);

                if(diff2 > diff1)
                {
                    closetSum = sum;
                }
                if(target > sum)
                    left++;
                else
                    right--;
            }
        }
        return closetSum;
    }
};