class Solution {
public:
    bool isVowel(char it){
        it = static_cast<char>(tolower(it));
        if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u')
            return true;
        return false;
    }
    string sortVowels(string s) {
        vector<char> arr;
        for(auto it: s){
            if(isVowel(it))
                arr.push_back(it);
        }
        sort(arr.begin(), arr.end());
        int j=0;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i]))
                s[i] = arr[j++];
        }
        return s;
    }
};