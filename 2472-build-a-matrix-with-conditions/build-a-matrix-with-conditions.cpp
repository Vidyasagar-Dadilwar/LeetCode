class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>vertical = getTopologicalOrder(rowConditions,k);
        vector<int>horizontal = getTopologicalOrder(colConditions,k);
        if(vertical.size()==0 || horizontal.size()==0){
            vector<vector<int>>ans1;
            return ans1;
        }
        vector<vector<int>>ans = findMatrix(horizontal,vertical,k);
        return ans;
    }

    vector<vector<int>> findMatrix(vector<int>horizontal,vector<int>vertical,int k){
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(vertical[i]==horizontal[j]){
                    ans[i][j] = vertical[i];
                }
            }
        }
        return ans;
    }
    vector<int> getTopologicalOrder(vector<vector<int>>graph,int k){
        vector<int>indegree(k+1,0);
        vector<vector<int>>adjList(k+1);
        for(auto it : graph){ 
          indegree[it[1]]++;
          adjList[it[0]].push_back(it[1]);
        }
        queue<int>q;
        bool check=false;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0){
               q.push(i);
               check=true;
            }
        }
        if(!check){
            return {};
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(int child:adjList[node]){
                indegree[child]--;
                if(indegree[child]==0){
                    q.push(child);
                }
            }
        }
        if(ans.size()!=k){
            return {};
        }
        return ans;
    }
};