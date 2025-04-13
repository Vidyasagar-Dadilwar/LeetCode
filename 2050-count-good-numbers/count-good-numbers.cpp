class Solution {
public:
    long MOD = 1000000007;
    long pow(long x , long n){
        if(n==0) return 1;
        long temp =pow(x,n/2);
        if(n%2==0) return (temp*temp)%MOD;
        else return (x*temp*temp)%MOD;
    }
    int countGoodNumbers(long long n) {
        long e=(n+1)/2, o=n/2;
        long f=pow(5,e)%MOD, s=pow(4,o)%MOD;
        return (int)((f*s)%MOD);
    }
};