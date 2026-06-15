class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result;

        for(int i=0; i<n-2; i++)
        {
            vector<int>p;
            for(int j=0; j<n-2; j++)
            {
                int max=INT_MIN;
                for(int r=i; r<=i+2; r++)
                {
                    for(int c=j; c<=j+2; c++)
                    {
                        if(grid[r][c] > max)
                            max = grid[r][c];
                    }
                }
                p.push_back(max);
            }
            result.push_back(p);
        }

        return result;

    }
};