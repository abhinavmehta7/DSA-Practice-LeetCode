class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size(),a=0,count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') count++;
            else{
                if(count>0) count--;
                else a++;
            }
        }
        return a+count;
    }
};