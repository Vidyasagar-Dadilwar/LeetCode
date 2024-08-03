#include<map>
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int, int>mp1;
        map<int, int>mp2;

        for (int num : target) {
            mp1[num]++;
        }

        for (int num : arr) {
            mp2[num]++;
        }

        return mp1 == mp2;
    }
};