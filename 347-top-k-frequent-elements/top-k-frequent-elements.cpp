// PLEASE ALSO SEE THE LAST SUBMISSION

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>result;
        int n = nums.size();

        unordered_map<int,int>mp;

        for(int &num : nums){
            mp[num]++;
        }

        vector<vector<int>> bucket(n+1);
        // Index = Freq
        // Value = elements
        // bucket[i] = element having ith freuquency

        for(auto &it : mp){

            int elem = it.first;
            int freq = it.second;

            bucket[freq].push_back(elem);
        }

        for(int i=n; i>0; i--){

            if(bucket[i].size() == 0){
                continue;
            }

            while(bucket[i].size() > 0 && k > 0){
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }
};