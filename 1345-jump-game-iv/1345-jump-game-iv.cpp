class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
  
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<bool> vis(n, false);
        vis[0] = true;
    
        while(!q.empty()) {
            auto [u, cost] = q.front();
            q.pop();

            if(u == n - 1) return cost;

            for(int i = 0; i < 2; i++) {
                int v;
                i == 0 ? v = u - 1 : v = u + 1;

                if(v < n && v >= 0) {
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push({v, cost + 1});
                    }
                }
            }
                
            for(int v: mp[arr[u]]) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push({v, cost + 1});
                }
            }

            mp[arr[u]].clear();

        }

        return -1;
    }
};