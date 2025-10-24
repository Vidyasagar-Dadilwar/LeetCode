class Solution {
public:
    bool solve(int n){
        string s = to_string(n);
        vector<int> arr(10, 0);
        for(auto it: s) 
            arr[it-'0']++;
        
        for(auto it: s){
            int ind = it - '0';
            if(ind == 0 || ind != arr[ind])
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1; ; i++){
            if(solve(i))
                return i;
        }
        return -1;
    }
};