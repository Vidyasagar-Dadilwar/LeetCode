class Solution {
public:
    bool solve(int node, vector<vector<int>> &adj, int parent, vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(it == parent)
                continue;
            if(vis[it] == 1)
                return true;
            if(solve(it, adj, node, vis)){
                return true;
            }
        }    
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = edges.size();
        vector<int> ans;
        vector<vector<int>> adj(n+1);

        for(auto it: edges){
            int x = it[0], y = it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
            vector<int> vis(n+1, 0);
            if(solve(x, adj, -1, vis)){
                ans = it;
                break;
            }
        }
        return ans;
    }
};