class Solution {
    public int totalMoney(int n) {
        int start = 0, sum = 0, prev = 0;
        for(int i = 0; i < n; i++){
            if(i%7 == 0)
                prev = ++start;
            sum += prev++;
        }
        return sum;
    }
}