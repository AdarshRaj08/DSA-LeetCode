class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>topKelement;
        unordered_map<int, int>mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto &p : mp)
            pq.push({p.second, p.first});

        for(int i=0; i<k; i++){
            topKelement.push_back(pq.top().second);
            pq.pop();
        }

        return topKelement;
    }
};