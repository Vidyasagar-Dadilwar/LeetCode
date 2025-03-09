class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int cnt = 1, ans = 0;
        for(int i=0; i<k-1; i++)
            colors.push_back(colors[i]);

        for(int i=1; i<colors.size(); i++){
            if(colors[i] != colors[i-1]){
                cnt++;
            }
            else{
                if(cnt >= k)
                    ans += (cnt-k+1);
                cnt = 1;
            }
        }
        if(cnt >= k)
            ans += (cnt-k+1);
        return ans;
    }
};