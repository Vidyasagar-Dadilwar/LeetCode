class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(auto p: pre){
            adj[p[0]].push_back(p[1]);
        }

        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        for(int i=0; i<numCourses; i++){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(auto it: adj[curr]){
                    if(!reachable[i][it]){
                        reachable[i][it] = true;
                        q.push(it);
                    }
                }
            }
        }
        vector<bool> ans;
        for(auto q: queries){
            ans.push_back(reachable[q[0]][q[1]]);
        }
        return ans;
    }
};