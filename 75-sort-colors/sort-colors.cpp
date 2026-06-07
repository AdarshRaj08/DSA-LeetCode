class Solution {
public:
    void sortColors(vector<int>& nums) {
            int n = nums.size();

            // 2,0,1,2,1,2
            int zero = 0;
            int one  = 0;
            int two  = n-1;
            while(one <= two)
            {
                if(nums[one] == 1)
                    one++;
                else if(nums[one] == 0)
                {
                    swap(nums[zero],nums[one]);
                    zero++;
                    one++;
                }
                else{
                    // 2
                    swap(nums[one],nums[two]);
                    two--;
                    // one++;
                }
            }


        }
};