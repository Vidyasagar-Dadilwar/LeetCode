class Solution {
    public int reverse(int n){
        int tmp = 0;
        while(n>0){
            tmp = tmp*10 + (n%10);
            n /= 10;
        }
        return tmp;
    }
    public int mirrorDistance(int n) {
        return Math.abs(n-reverse(n));
    }
}