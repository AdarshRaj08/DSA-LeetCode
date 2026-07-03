class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>>& adj, int node, int col, vector<int>&colors)
    {
        colors[node] = col;

        for(int i=0; i<adj[node].size(); i++)
        {
            int neigh = adj[node][i];
            if(colors[neigh] != -1 && colors[neigh] == col)
            {
                res = false;
                return;
            }
            if(colors[neigh] == -1)
            {
                dfs(adj, neigh, 1-col, colors);
            }
        }
        return;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n,-1);

        for(int i=0; i<n; i++)
        {
            if(colors[i] == -1)
                dfs(graph,i,0,colors);
        }

        return res;
    }
};