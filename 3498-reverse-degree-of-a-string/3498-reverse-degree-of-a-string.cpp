class Solution {
public:
    int reverseDegree(string s) {
        long long sum=0;
        for(int i=0;i<s.size();i++){
            int prod=(i+1)*(26-(s[i]-'a'));
            sum+=prod;
        }
        return sum;
    }
};