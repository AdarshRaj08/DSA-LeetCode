class Solution {
public:
    string numToBinary(int num)
    {
        string result = "";
        while(num > 0)
        {
            int rem = num % 2;
            result = to_string(rem) + result;
            num = num / 2;
        }
        return result;
    }

    string sizeCheck(string result,int n)
    {
        int rem = n - result.length();

        for(int i=1; i <= rem; i++)
        {
            result = "0" + result;
        }
        return result;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        // string result = "";
        unordered_set<string>st;

        for(int i=0; i<n; i++)
        {
            st.insert(nums[i]);
        }

        for(int i=0; i <= n; i++)
        {
            string s = numToBinary(i);
            s = sizeCheck(s,n);

            if(st.find(s) == st.end())
                return s;
        }
        return "";
    }
};