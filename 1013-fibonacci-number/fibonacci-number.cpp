class Solution {
public:
    vector<int> dp; 
    int fib(int n) {
        // // create dp only once 
        // if(dp.empty())
        //     dp.resize(n+1,-1);
        // if(n == 0 || n == 1)
        //     return n;
        
        // if(dp[n] != -1)
        //     return dp[n];
        // return dp[n] = fib(n-1) + fib(n-2);

        if(n==0)
            return 0;
        vector<int> dpp(n+1);
        dpp[0] = 0; dpp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            dpp[i] = dpp[i-1] + dpp[i-2];
        }
        return dpp[n];
    }
};