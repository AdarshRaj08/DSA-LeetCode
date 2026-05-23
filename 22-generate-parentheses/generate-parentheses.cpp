class Solution {
public:
    void helper(vector<string>&s, int leftParan , int rightParan, int n, string ans)
    {
        if(leftParan == n && rightParan == n)
        {
            s.push_back(ans);
            return;
        }

        if(leftParan < n ) helper(s,leftParan+1, rightParan, n, ans + "(");
        if(rightParan < leftParan) helper(s, leftParan, rightParan+1, n, ans + ")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        helper(s,0,0,n,"");
        return s;
    }
};