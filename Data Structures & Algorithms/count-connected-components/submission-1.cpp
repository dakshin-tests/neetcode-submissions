class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n);

        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int c = 0;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            dfs(adj, vis, i);
            c++;
        }

        return c;
    }

    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int s){
        if(vis[s]) return;

        vis[s] = true;
        
        for(int nei: adj[s]){
            dfs(adj, vis, nei);
        }
    }
};
