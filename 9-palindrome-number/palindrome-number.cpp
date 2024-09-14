class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long int n=0,a=x;
        while(a!=0){
            int temp=a%10;
            n=n*10+temp;
            a/=10;
        }
        return (n==x);
    }
};