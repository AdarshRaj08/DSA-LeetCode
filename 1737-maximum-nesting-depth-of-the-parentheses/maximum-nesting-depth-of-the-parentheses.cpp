class Solution {
public:
    int maxDepth(string s) {

        // ********** STACK APPROACH **********

        int result = 0; 
        stack<char>st;

        for(char &ch : s)
        {
            if(ch == '(')
                st.push(ch);
            else if(ch == ')')
                st.pop();

            result = max(result,(int)st.size());
        }


        return result;




        // ******** NORMAL APPRAOCH ************************
        
        // int n = s.length();
        // int ans = 0;
        // int count = 0;

        // for(int i=0; i<n; i++)
        // {
        //     if(s[i] == '(')
        //         count++;
        //     if(s[i] == ')')
        //         count--;
            
        //     ans = max(ans,count);
        // }

        // return ans;
    }
};