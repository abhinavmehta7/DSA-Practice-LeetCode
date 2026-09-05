class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> v(n);
        int maxo=nums[0],mini=nums[n-1];
        for(int i=0;i<n;i++){
            maxo=max(maxo,nums[i]);
            mini=min(mini,nums[n-1-i]);
            v[i].first=maxo;
            v[n-1-i].second=mini;
        }
        for(int i=0;i<n;i++){
            if(v[i].first-v[i].second<=k) return i;
        }
        return -1;
    }
};