class Solution {
public:
    int arrsize;
    long long memo[100001];
    int nextIndexFind(vector<vector<int>>& rides, int lef, int endOfCurrRide){
        int rig = arrsize-1;
        int res = arrsize;
        while(lef <= rig){

            int mid = lef + (rig-lef)/2;

            if(rides[mid][0] >= endOfCurrRide){
                res = mid;
                rig = mid-1;
            }
            else{
                lef = mid+1;
            }
        }
        return res;
    }
    long long solve(vector<vector<int>>& rides, int idx){
        if(idx >= arrsize){
            return 0;
        }
        if(memo[idx] != -1){
            return memo[idx];
        }
        int nextIndex = nextIndexFind(rides, idx+1, rides[idx][1]);
        long long take = (rides[idx][1]-rides[idx][0] + rides[idx][2]) + solve(rides, nextIndex);
        long long notTake = solve(rides, idx+1);

        return memo[idx] = max(take, notTake);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        arrsize = rides.size();
        memset(memo, -1 , sizeof(memo));
        // sorting based on the starting point
        sort(rides.begin(), rides.end(),[&](auto& vec1, auto& vec2){
            return vec1[0] < vec2[0];
        });

        return solve(rides, 0);
    }
};