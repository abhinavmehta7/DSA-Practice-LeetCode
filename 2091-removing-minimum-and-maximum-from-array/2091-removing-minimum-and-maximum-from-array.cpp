class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size(),mini=0,maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=nums[maxi]) maxi=i;
            if(nums[i]<=nums[mini]) mini=i;
        }
        int maxo=max(mini,maxi)+1,mino=n-min(maxi,mini);
        int ans=min({maxo,min(mini,maxi)+n-max(mini,maxi)+1,mino});
        return ans;
    }
};