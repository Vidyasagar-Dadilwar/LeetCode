class Solution {
public:
    string largestGoodInteger(string num) {
        int largest = INT_MIN;
        for(int i=0; i<num.size()-2; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2])
                largest = max(largest, stoi(num.substr(i, 3)));
        }
        return (largest == INT_MIN) ? "" : (largest == 0) ? "000" : to_string(largest);
    }
};