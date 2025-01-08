class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        if (n1 > n2) 
            return false;
        if (str2.substr(0, n1) != str1) 
            return false;
        if (str2.substr(n2 - n1, n1) != str1) 
            return false;

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for(int i = 0; i<words.size(); i++){
            for(int j = i+1; j<words.size(); j++){
                cnt += (isPrefixAndSuffix(words[i], words[j])) ? 1 : 0;
            }
        }
        return cnt;
    }
};