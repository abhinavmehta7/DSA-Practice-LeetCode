class Solution {
public:
    bool checkDivisibility(int n) {
        long long k=n,sum=0,prod=1;
        while(n!=0){
            int dig=n%10;
            sum+=dig;
            prod*=dig;
            n/=10;
        }
        sum+=prod;
        return k%sum==0;
    }
};