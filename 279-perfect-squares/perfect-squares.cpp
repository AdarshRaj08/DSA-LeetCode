class Solution {
public:
    bool isPerfectSquare(int n){
        int root = sqrt(n);

        return root*root == n;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,0);

        for(int i=1; i<=n; i++){
            int minn = i;
            if(isPerfectSquare(i)){
                dp[i] = 1;
            }
            else{
                for(int j=1; j*j<=i/2; j++){
                    int count = dp[j*j] + dp[i-(j*j)];
                    minn = min(count,minn);
                }
                dp[i] = minn;
            }
        }
        return dp[n];

    }
};