class Solution {
public:
    long long countCommas(long long n) {
        long long ans=(n>999)*(n-999);
        if(n>999999) ans+=abs(n-999999);
        if(n>999999999) ans+=abs(n-999999999);
        if(n>999999999999) ans+=abs(n-999999999999);
        if(n>999999999999999) ans+=abs(n-999999999999999);
        return ans;
    }
};