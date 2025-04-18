class Solution {
public:
    string rle(string s){
        char curr = s[0];
        int cnt = 0;
        string ans = "";
        for(auto c: s){
            if(c == curr)
                cnt++;
            else{
                ans += to_string(cnt) + curr;
                curr = c;
                cnt = 1;
            }
        }
        ans += to_string(cnt) + curr;
        return ans;
    }
    string countAndSay(int n) {
        string curr = "1";
        for(int i=1; i<n; i++)
            curr = rle(curr);
        return curr;
    }
};