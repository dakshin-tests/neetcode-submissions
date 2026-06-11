class Solution {
public:

    bool dfs(unordered_map<char, vector<char>>& adj,
    unordered_map<char, bool>& vis,
    unordered_map<char, bool>& rec,
    char s, 
    string& res){

        vis[s] = true;
        rec[s] = true;

        for(char nei: adj[s]){
            if(rec[nei]) return false;

            if(!vis[nei] && !dfs(adj, vis, rec, nei, res)) return false;
        }

        res += s;
        rec[s] = false;
        return true;
    }

    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        unordered_map<char, vector<char>> adj;
        unordered_map<char, bool> vis;
        unordered_map<char, bool> rec;

        for(auto& w: words){
            for(char c: w){
                adj[c];
            }
        }

        for(int i = 1; i < n; i++){
            string w1 = words[i - 1];
            string w2 = words[i];
            size_t minlen = min(w1.size(), w2.size());

            if(w1.size() > w2.size() && 
            w1.substr(0, minlen) == w2.substr(0, minlen))
                return "";
            
            for(int j = 0; j < minlen; j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]].push_back(w2[j]);
                    break;
                }

            }
            
        }

        string res = "";

        for(auto [c, _]: adj){
            if(vis[c]) continue;
            
            if(!dfs(adj, vis, rec, c, res)) return "";
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
