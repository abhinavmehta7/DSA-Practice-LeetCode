class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n==1) return costs[0]+1;
        if(n==2) return min(costs[0]+costs[1]+2,costs[1]+4);
        long long prev3= costs[0]+1;
        long long prev2 = min((long long)costs[0]+costs[1]+2,(long long)costs[1]+4);
        long long prev1=min({prev3+costs[2]+4,prev2+costs[2]+1,(long long)costs[2]+9});
        if(n==3) return prev1;
        long long ans=0;
        for(int i=3;i<n;i++){
            long long a=prev3+costs[i]+9;
            long long b=prev2+costs[i]+4;
            long long c=prev1+costs[i]+1;
            ans=min({a,b,c});
            prev3=prev2;
            prev2=prev1;
            prev1=ans;
        }
        return ans;
    }
};