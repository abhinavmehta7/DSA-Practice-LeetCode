class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size(),mlen=1;
        map<int,int> mp;
        for(int i=0,j=0;j<n;j++){
            mp[nums[j]]++;
            while(mp[nums[j]]>k && i<=j){
                mp[nums[i]]--;
                i++;
            }
            mlen=max(mlen,j-i+1);
        }
        return mlen;
    }
};