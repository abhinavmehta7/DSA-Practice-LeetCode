class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int sme=INT_MAX,smo=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0) sme=min(sme,nums1[i]);
            else smo=min(smo,nums1[i]);
        }
        return (smo==INT_MAX || sme==INT_MAX || sme>smo);
    }
};