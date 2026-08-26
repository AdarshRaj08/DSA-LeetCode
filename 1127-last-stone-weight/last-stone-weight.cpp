class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        // priority_queue<int>pq;

        // for(int i=0; i<n; i++){
        //     pq.push(stones[i]);
        // }

        // method2 for building max-heap
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size() > 1){
            
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x == y){
                continue;
            }
            else{
                pq.push(y-x);
            }
        }
        if(pq.size() == 1){
            return pq.top();
        }
        else{
            return 0;
        }
    }
};