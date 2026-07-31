class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26,0);
        for(auto& c:word){
            v[c-'a']++;
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        long long sum=0,j=0;
        for(int i=0;i<26;i++){
            j=(8+i)/8;
            sum+=v[i]*j;
        }
        return sum;
    }
};