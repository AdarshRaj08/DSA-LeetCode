class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        // Build Max-heap and insert all the piles
        priority_queue<int> maxHeap;
        int minSum = 0;

        for(auto pile : piles){
            minSum += pile;
            maxHeap.push(pile);
        }

        for(int i=0; i<k; i++){
            int num = maxHeap.top();
            maxHeap.pop();

            minSum = minSum - (num/2);
            if(num % 2 == 0)
                maxHeap.push(num/2);
            else{
                maxHeap.push((num/2)+1);
            }
        }
        return minSum;
    }
};