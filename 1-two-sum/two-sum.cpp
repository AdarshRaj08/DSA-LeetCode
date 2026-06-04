class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        int n = nums.size();
        int firstIndex = -1;
        int secondIndex = -1;
        bool breakLoop = false;
        for(int i=0; i<n; i++)
        {
            firstIndex = i;
            for(int j=i+1; j<n; j++)
            {
                if(target == (nums[i] + nums[j]))
                {
                    secondIndex = j;
                    breakLoop = true;
                    break;
                }
            }
            if(breakLoop == true)
                break;
        }
        result.push_back(firstIndex);
        result.push_back(secondIndex);

        return result;
    }
};