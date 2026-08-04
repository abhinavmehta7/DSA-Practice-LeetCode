class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),s=nums[n-1]-nums[0]+1;
        vector<int> v;
        for(int i=0,j=nums[0];i<n;i++){
            while(nums[i]>j){
                v.push_back(j);
                j++;
            }
            j++;
        }
        return v;
    }
};