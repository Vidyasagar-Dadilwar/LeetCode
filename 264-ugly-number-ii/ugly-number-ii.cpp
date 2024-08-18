class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr(n+1);
        int i2, i3, i5;
        i2=i3=i5=1;
        arr[1]=1;

        for(int i=2;i<=n;i++){
            int t2=arr[i2]*2;
            int t3=arr[i3]*3;
            int t5=arr[i5]*5;
            
            int mini=min(t2,min(t3,t5));
            
            arr[i]=mini;
            
            if(mini==t2)    
                i2++;
            if(mini==t3) 
                i3++;
            if(mini==t5) 
                i5++;
        }
        return arr[n];
    }
};