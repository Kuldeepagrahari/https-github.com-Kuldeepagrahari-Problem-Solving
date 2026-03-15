class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            if(i + 1 < n)
                adj[i].push_back(i + 1);
            if(i - 1 >= 0)
                adj[i].push_back(i - 1);
            
            // for(int v: mp[arr[i]]) {
            //     adj[i].push_back(v);
            // }
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<bool> vis(n, false);
        vis[0] = true;
        set<int> st;
    
        while(!q.empty()) {
            auto [u, cost] = q.front();
            q.pop();

            if(u == n - 1) return cost;

            for(int v: adj[u]) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push({v, cost + 1});
                }
            }
            if(st.find(arr[u]) == st.end())
            {    
                for(int v: mp[arr[u]]) {
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push({v, cost + 1});
                    }
                }

                st.insert(arr[u]);
            }
        }

        return -1;
    }
};