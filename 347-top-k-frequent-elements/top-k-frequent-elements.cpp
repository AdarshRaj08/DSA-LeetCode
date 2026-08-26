class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>topKelement;
        unordered_map<int, int>mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // OR
        // priority_queue<P, vector<P>, greater<P>> pq;

        for(auto &p : mp){
            pq.push({p.second, p.first});


            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            topKelement.push_back(pq.top().second);
            pq.pop();
        }

        return topKelement;
    }
};