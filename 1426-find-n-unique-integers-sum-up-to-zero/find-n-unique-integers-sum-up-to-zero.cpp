class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr(n);
        for(int i=0; i<n/2; i++){
            arr[i] = i+1;
            arr[n-i-1] = -(i+1);
        }
        if(n%2 == 1)
            arr[n/2] = 0;
        return arr; 
    }
};