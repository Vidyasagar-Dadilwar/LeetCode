class Solution {
public:
    int bfs(vector<vector<int>> &g, int k, int root){
        queue<int> q;
        q.push(root);
        vector<int> vis(g.size(), 0);
        vis[root] = 1;
        int res = 0;
        for(int j=0; j<=k; j++){
            int n = q.size();
            res += n;
            for(int i=0; i<n; i++){
                int node = q.front();
                q.pop();
                for(auto it: g[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1, m = edges2.size()+1;
        vector<vector<int>> g1(n), g2(m);

        for(auto v: edges1){
            g1[v[0]].push_back(v[1]);
            g1[v[1]].push_back(v[0]);
        }
        
        for(auto v: edges2){
            g2[v[0]].push_back(v[1]);
            g2[v[1]].push_back(v[0]);
        }

        int ans = 0;
        for(int i=0; i<m; i++)
            ans = max(ans, bfs(g2, k-1, i));

        vector<int> res(n, 0);
        for(int i=0; i<n; i++)
            res[i] = ans + bfs(g1, k, i);
        
        return res;
    }
};