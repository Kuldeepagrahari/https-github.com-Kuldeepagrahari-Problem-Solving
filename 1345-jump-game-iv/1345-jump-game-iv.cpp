class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
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

            int v1 = u + 1;
            int v2 = u - 1;
            if(v1 < n) {
                if(!vis[v1]) {
                    vis[v1] = true;
                    q.push({v1, cost + 1});
                }
            } 
            if(v2 >= 0) {
                if(!vis[v2]) {
                    vis[v2] = true;
                    q.push({v2, cost + 1});
                }
            } 
                
            for(int v: mp[arr[u]]) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push({v, cost + 1});
                }
            }

            mp.erase(arr[u]);
            
        }

        return -1;
    }
};