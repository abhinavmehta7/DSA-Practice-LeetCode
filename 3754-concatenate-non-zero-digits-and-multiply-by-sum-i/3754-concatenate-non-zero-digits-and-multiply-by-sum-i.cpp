class Solution {
public:
    long long sumAndMultiply(int n) {
        int r=0;
        long long sum=0;
        while(n!=0){
            int k=n%10;
            if(k==0){
                n/=10;
                continue;
            }
            sum+=k;
            r*=10;
            r+=k;
            n/=10;
        }
        int ans=0;
        while(r!=0){
            int t=r%10;
            ans*=10;
            ans+=t;
            r/=10;
        }
        return 1LL*ans*sum;
    }
};