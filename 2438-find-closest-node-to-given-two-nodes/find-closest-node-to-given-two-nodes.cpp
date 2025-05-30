class Solution {
public:
    void getDistance(vector<int> & edges, int node, vector<int>& dist){
        vector<int> vis(edges.size(), 0);
        int d = 0;
        while(node != -1 && !vis[node]){
            dist[node] = d++;
            vis[node] = 1;
            node = edges[node];
        }
    }    

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);

        getDistance(edges, node1, dist1);
        getDistance(edges, node2, dist2);

        int minDist = INT_MAX, res = -1;

        for(int i=0; i<n; i++){
            if(dist1[i] != -1 && dist2[i] != -1){
                int maxDist =  max(dist1[i], dist2[i]);
                if(maxDist < minDist){
                    minDist = maxDist;
                    res = i;
                }
            }
        }
        return res;
    }
}; 