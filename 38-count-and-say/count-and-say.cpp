class Solution {
public:
    string rle(string s){
        int cnt = 0;
        char curr = s[0];
        string res = "";
        for(auto c: s){
            if(c == curr)
                cnt++;
            else{
                res += to_string(cnt) + curr;
                curr = c;
                cnt = 1;
            }
        }
        res += to_string(cnt) + curr;
        return res;
    }
    string countAndSay(int n) {
        string curr = "1";
        for(int i=1; i<n; i++){
            curr = rle(curr);
        }
        return curr;
    }
};