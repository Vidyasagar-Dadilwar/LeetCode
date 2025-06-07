class Solution {
public:
    string clearStars(string s) {
        priority_queue<char, vector<char>, greater<>> heap;
        vector<bool> del(s.size(), false);
        unordered_map<char, stack<int>> mp;
        int i = 0;
        for(auto it: s){
            if(it == '*'){
                char top = heap.top();
                heap.pop();

                int ind = mp[top].top();
                mp[top].pop();

                del[ind] = true;
            }
            else{
                heap.push(it);
                mp[it].push(i);
            }
            i++;
        }

        string res = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] != '*' && del[i] != true)
                res.push_back(s[i]);
        }
        return res;
    }
};