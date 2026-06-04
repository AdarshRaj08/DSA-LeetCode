class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    int temp = nums[i] + nums[j] + nums[k];
                    int diff1 = abs(temp - target);
                    int diff2 = abs(ans - target);

                    if(diff1 < diff2)
                        ans = temp;
                }
            }
        }
        return ans;
    }
};