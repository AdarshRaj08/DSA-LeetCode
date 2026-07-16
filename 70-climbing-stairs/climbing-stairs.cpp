class Solution {
public:
    int waysfind(int n, vector<int>& bank){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 0;
        }

        if(bank[n] != -1){
            return bank[n];
        }
        int step1 = waysfind(n-1,bank);
        int step2 = waysfind(n-2,bank);
        // int step3 = waysfind(n-3,bank);
        int totalWays = step1 + step2;
        bank[n] = totalWays;
        return totalWays;
    }

    int climbStairs(int n) {
        vector<int> bank(n+1, -1);
        return waysfind(n,bank);
    }
};