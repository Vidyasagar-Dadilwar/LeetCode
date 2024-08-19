class Solution {
public:
    int search(vector<int>& arr, int k) {
        auto it = find(arr.begin(), arr.end(), k);
        if(it == arr.end()){
            return -1;
        }
        return distance(arr.begin(),it);
    }
};