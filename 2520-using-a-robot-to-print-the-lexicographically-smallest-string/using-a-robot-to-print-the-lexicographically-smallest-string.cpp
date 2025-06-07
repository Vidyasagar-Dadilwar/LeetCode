class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> mp;
        for(auto it: s)
            mp[it]++;
        
        stack<char> st;
        string ans;
        char mini = 'a';

        for(auto it: s){
            st.push(it);

            mp[it]--;
            while(mini != 'z' && mp[mini] == 0){
                mini++;
            }
            while(!st.empty() && st.top() <= mini){
                ans.push_back(st.top());
                st.pop();
            }
        } 
        return ans;
    }
};