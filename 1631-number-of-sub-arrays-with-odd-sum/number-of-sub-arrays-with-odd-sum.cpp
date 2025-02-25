class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MODULE = 1000000007;
        int e = 1, sum = 0, o = 0, ans = 0;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            if(sum%2 == 1){
                ans = (ans + e)%MODULE;
                o++;
            }
            else{
                ans = (ans + o)%MODULE;
                e++;
            }
        }
        return ans;
    }
};