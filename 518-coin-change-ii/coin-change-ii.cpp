class Solution {
public:
    int t[301][5001];
    int solve(int amount, int index, vector<int>& coins){
        if(amount == 0){
            return 1;
        }

        if(index == coins.size()){
            return 0;
        }

        if(t[index][amount] != -1){
            return t[index][amount];
        }

        if(amount < coins[index]){
            return solve(amount, index+1, coins);
        }

        int take = solve(amount-coins[index], index, coins);
        int skip = solve(amount             , index+1, coins);

        return t[index][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        memset(t, -1, sizeof(t));
        return solve(amount, 0, coins);
    }
};