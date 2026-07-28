class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n;
        int i = 1;

        while(i < n){

            if(ratings[i-1] == ratings[i]){
                i++;
                continue;
            }

            int peak = 0;
            while(ratings[i-1] < ratings[i]){
                peak++;
                candy += peak;
                i++;

                if(i == n){
                    return candy;
                }
            }

            int dip = 0;
            while(i < n && ratings[i-1] > ratings[i]){
                dip++;
                candy += dip;
                i++;
            }

            candy -= min(peak,dip);
        }
        return candy;

    }
};