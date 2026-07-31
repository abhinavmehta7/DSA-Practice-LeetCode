class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start=0,end=arr.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int mis=arr[mid]-(mid+1);
            if(mis<k) start=mid+1;
            else end=mid-1;
        }
        return start+k;
    }
};