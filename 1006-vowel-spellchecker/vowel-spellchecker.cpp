class Solution {
public:
    string toLower(string s){
        for(auto& c: s) 
            c = tolower(c);
        return s;
    }

    string deVowel(string s){
        for(auto& c: s){
            char t = tolower(c);
            if(t=='a' || t=='e' || t=='i' || t=='o' || t=='u')
                c = '*';
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordList, vector<string>& queries) {
        unordered_set<string> exact(wordList.begin(), wordList.end());
        unordered_map<string, string> caseMp, vowelMp;

        for(auto it: wordList){
            string l = toLower(it);
            string d = deVowel(l);
            if(!caseMp.count(l))
                caseMp[l] = it;
            if(!vowelMp.count(d))
                vowelMp[d] = it;
        }
        vector<string> res;
        for(auto q: queries){
            if(exact.count(q))
                res.push_back(q);
            else{
                string l = toLower(q);
                string d = deVowel(l);

                if(caseMp.count(l))
                    res.push_back(caseMp[l]);
                else if(vowelMp.count(d))
                    res.push_back(vowelMp[d]);
                else
                    res.push_back("");
            }
        }
        return res;
    }
};