class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        while(stones.size() > 1){

            sort(stones.begin(), stones.end());
            int n = stones.size();

            int y = stones.back();
            stones.pop_back();
            int x = stones.back();
            stones.pop_back();

            if(x == y){
                continue;
            }
            else{
                y = y - x;
            }
            stones.push_back(y);
        }
        if(stones.size() == 1){
            return stones.back();
        }
        else{
            return 0;
        }
    }
};