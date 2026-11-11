class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        if(cost1+cost2>=costBoth){
            ans=1LL*min(need1,need2)*costBoth;
            if(need1<=need2 ){
                if(cost2 > costBoth) ans+=1LL*abs(need2-need1)* costBoth;
                else ans+=1LL*abs(need2-need1)* cost2;
            }
            else{
                if(cost1 > costBoth) ans+=1LL*abs(need2-need1)* costBoth;
                else ans+=1LL*abs(need2-need1)* cost1;
            }
        }
        else ans=1LL*need1*cost1+ 1LL*need2*cost2;
        return ans;
    }
};