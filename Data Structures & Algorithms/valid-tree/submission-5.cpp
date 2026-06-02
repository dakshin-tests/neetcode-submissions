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

        if (!dfs(adj, vis, 0)) return false;

        for (bool v : vis) {
            if (!v) return false;
        }

        return true;
    }

    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int cur, int par = -1){

        vis[cur] = true;

        for(int nei: adj[cur]){
            if(!vis[nei]){
                if(!dfs(adj, vis, nei, cur)) return false;
            }
            else {
                if(nei != par) return false;
            }
        }

        return true;
    }
};