class Solution {
public:

    vector<int> p;

    int find(int v){
        if(p[v] == v) return v;
        return p[v] = find(p[v]);
    }

    bool uni(int a, int b){
        int x = find(a);
        int y = find(b);

        if(x == y) return false;

        p[y] = x;
        return true;
    }
    

    bool validTree(int n, vector<vector<int>>& edges) {
        p.resize(n + 1);

        for(int i = 0; i <= n; i++){
            p[i] = i;
        }

        int c = n;
        for(auto& e: edges){
            int u = e[0], v = e[1];
            if(find(u) != find(v)){
                uni(u, v);
                c--;
            }
            else if(find(u) == find(v)) return false;
        }

        return c > 1 ? false : true;
    }
};
