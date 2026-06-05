class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>result;

        int n = strs.size();
        for(int i=0; i<n; i++)
        {
            string s = strs[i];
            sort(s.begin(),s.end());

            mp[s].push_back(strs[i]);
        }
        for(auto &hii : mp)
        {
            result.push_back(hii.second);
        }
        return result;
    }
};