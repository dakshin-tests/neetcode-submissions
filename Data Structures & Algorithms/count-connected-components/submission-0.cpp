class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        } 

        vector<int> vis(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
            dfs(adj, i, vis);
            count++;
            }
        }

        return count;
    }

    void dfs(vector<vector<int>>& adj, int s, vector<int>& vis){
        if(vis[s]) return;

        vis[s] = 1;

        for(auto& nei: adj[s]){
            dfs(adj, nei, vis);
        }
    }
};
