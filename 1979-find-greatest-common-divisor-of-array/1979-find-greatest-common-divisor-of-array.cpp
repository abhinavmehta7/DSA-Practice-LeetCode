class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mine=INT_MAX,maxe=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(mine>=nums[i]) mine=nums[i];
            if(maxe<=nums[i]) maxe=nums[i];
        }
        return __gcd(mine,maxe);
    }
};