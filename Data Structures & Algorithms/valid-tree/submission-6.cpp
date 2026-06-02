class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        queue<pair<int, int>> q;
        q.push({0, -1});
        while(!q.empty()){
            auto [cur, par] = q.front();
            vis[cur] = true;
            q.pop();

            for(int nei: adj[cur]){
                if(!vis[nei]) q.push({nei, cur});
                else {
                    if(nei != par) return false;
                }
            }
        }

        for(bool v: vis){
            if(!v) return false;
        }
        
        return true;
    }
};