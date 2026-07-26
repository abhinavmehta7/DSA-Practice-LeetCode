class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long prod1=nums[n-1]*nums[n-2]*nums[n-3];
        long long prod2=nums[0]*nums[1]*nums[n-1];
        return max(prod1,prod2);
    }
};