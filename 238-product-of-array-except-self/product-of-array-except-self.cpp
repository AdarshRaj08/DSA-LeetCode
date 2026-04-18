class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        // vector<int> pre(n);
        // vector<int> suf(n);
        vector<int> ans(n);


        int prefix = 1;
        int suffix = 1;
        for(int i=0; i<n; i++)
        {
            if(i==0)
                ans[i] = 1;
            else
            {
                prefix = prefix * nums[i-1];
                ans[i] = prefix;
            }
        }
        
        for(int i=n-1; i>=0; i--)
        {
            if(i == n-1)
                ans[i] = 1 * ans[i];
            else
            {
                suffix = suffix * nums[i+1];
                ans[i] = suffix * ans[i];
            }
        }

        

        return ans;
    }
};