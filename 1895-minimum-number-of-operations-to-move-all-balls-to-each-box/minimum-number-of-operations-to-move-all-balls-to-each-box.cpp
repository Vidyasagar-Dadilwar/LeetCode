class Solution {
public:
    vector<int> minOperations(string boxes) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans;
        for(int i=0; i<boxes.size(); i++){
            int cnt = 0;
            for(int j=0; j<boxes.size(); j++){
                if(boxes[j] == '1' && i!=j){
                    cnt += abs(i-j);
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};