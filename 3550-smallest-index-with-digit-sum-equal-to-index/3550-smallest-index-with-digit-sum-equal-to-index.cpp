class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int a=nums[i],sum=0;
            while(a!=0){
                int dig=a%10;
                a/=10;
                sum+=dig;
            }
            if(sum==i) return i;
        }
        return -1;
    }
};