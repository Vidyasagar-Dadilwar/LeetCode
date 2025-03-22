class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int m = edges.size();

        for(int i=0; i<m; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                queue<int> q;
                int nn = 0, ne = 0;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    nn++;
                    for(auto it: adj[node]){
                        ne++;
                        if(!vis[it]){
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
                if((nn*(nn-1)) / 2 == (ne/2))
                    ans++;
            }
        }
        return ans;
    }
};