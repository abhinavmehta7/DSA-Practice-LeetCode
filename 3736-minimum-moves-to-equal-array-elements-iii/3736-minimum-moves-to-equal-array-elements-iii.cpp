class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0,n=nums.size();
        int y = *max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            ans+=(y-nums[i]);
        }
        return ans;
    }
};