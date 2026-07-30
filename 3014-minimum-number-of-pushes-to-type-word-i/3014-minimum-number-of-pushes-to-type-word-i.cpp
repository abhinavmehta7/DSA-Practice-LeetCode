class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<=8) return n;
        else if(n<=16) return 2*n-8;
        else if(n<=24) return 3*n-24;
        else return 4*n -48;
    }
};