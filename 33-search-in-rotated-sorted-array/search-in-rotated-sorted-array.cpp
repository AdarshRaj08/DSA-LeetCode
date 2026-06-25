class Solution {
public:
    int pivot(vector<int>& nums,int n)
    {
        int l=0,r=n-1;


        while(l < r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] < nums[r])
                r = mid;
            else
                l = mid+1;
        }
        return r;
    }
    int bsearch(vector<int>& nums,int l , int r,int target)
    {
        while(l <= r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] == target) return mid;
            if(nums[mid] > target) r = mid-1;
            else
                l = mid + 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        
        // find pivot element (pivot is smallest element)
        // apply binary search to 2 parts (0,pivot-1) to (pivot to n-1)

        int n = nums.size();
        int pivot_indx = pivot(nums,n);
        int idx = bsearch(nums,0,pivot_indx-1,target);
        
        if(idx != -1)
            return idx;
        
        idx = bsearch(nums,pivot_indx,n-1,target);

        return idx;

    }
};