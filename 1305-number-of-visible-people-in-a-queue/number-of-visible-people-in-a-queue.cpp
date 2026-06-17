class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        st.push(heights[n-1]);

        // answer vector
        vector<int>result(n,-1);
        result[n-1] = 0;

        for(int i=n-2; i>=0; i--)
        {
            int count = 0;
            while(!st.empty() && st.top() <= heights[i])
            {
                count++;
                st.pop();
            }
            if(!st.empty()) count++;
            result[i] = count;
            st.push(heights[i]);
        }
        return result;
    }
};