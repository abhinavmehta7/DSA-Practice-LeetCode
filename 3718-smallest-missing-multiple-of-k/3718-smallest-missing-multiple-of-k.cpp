class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int t=k;
        for(int i=0,j=2;i<nums.size();i++){
            if(nums[i]==t){
                t+=k;
            }
        }
        return t;
    }
};