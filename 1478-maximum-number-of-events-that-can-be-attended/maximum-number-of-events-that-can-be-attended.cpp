class Solution {
public:
    int maxEvents(vector<vector<int>>& arr) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(arr.begin(), arr.end());
        int curr_d=arr[0][0];
        pq.push(arr[0][1]);
        int next_i=1;
        int ans=0;
        while(next_i<n){
            while(next_i<n && curr_d>=arr[next_i][0]){
                pq.push(arr[next_i][1]);
                next_i++;
            }
            if(!pq.empty()){
                if(curr_d<=pq.top()){
                    ans++;
                    curr_d++;
                }
                pq.pop();
            }    
            if(pq.empty() && next_i<n){
                curr_d = arr[next_i][0];
                pq.push(arr[next_i][1]);
                next_i++;
                continue;
            }
        }
        while(!pq.empty()){
            if(curr_d<=pq.top()){
                ans++;
                curr_d++;
            }
            pq.pop();
        }
        return ans;
    }
};