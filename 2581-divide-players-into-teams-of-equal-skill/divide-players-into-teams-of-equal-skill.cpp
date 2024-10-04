class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int i=0, j=n-1;
        int t = skill[i] + skill[j];
        long long pro = 0;
        while(i<j){
            if(skill[i] + skill[j] == t){
                pro += skill[i]*skill[j];
            }
            else{
                return -1;
            }
            i++; j--;
        }
        return pro;
    }
};