class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int>ans;

        map<int,vector<int>>mp;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }

        for(auto &i : mp)
        {
            if(i.first % 2 == 0)
            {
                reverse(i.second.begin(),i.second.end());
            }
        }

        for(auto &i : mp)
        {
            for(auto j : i.second)
            {
                ans.push_back(j);
            }
        }

        return ans;
        
    }
};