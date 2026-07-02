class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<char>>& grid, int n, int m)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != '1')
            return;
        
        vis[i][j] = true;

        // all 4 direction (l,r,u,d)
        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};

        for(int x=0; x<4; x++)
        {
            int nr = i + dr[x];
            int nc = j + dc[x];

            dfs(nr, nc, vis, grid, n, m);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(i,j,vis,grid,n,m);
                    islands++;
                }
            }
        }

        return islands;
    }
};