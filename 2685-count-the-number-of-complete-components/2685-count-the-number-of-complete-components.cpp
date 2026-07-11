class Solution {
public:
    void dfs(int u, int &num_vert, int &num_edges, vector<bool> &vis, vector<vector<int>> &adj) {
        vis[u] = true;
        num_edges += adj[u].size();
        num_vert++;

        for(int v: adj[u]) {
            if(vis[v] == false) {
                dfs(v, num_vert, num_edges, vis, adj);
            }
        }
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);
        int num_connected_comp = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i] == false) {
                int num_vert = 0, num_edges = 0;
                dfs(i, num_vert, num_edges, vis, adj);
                
                if(num_vert * (num_vert - 1) == num_edges) {
                    num_connected_comp++;
                }
            }
        }

        return num_connected_comp;
    }
};