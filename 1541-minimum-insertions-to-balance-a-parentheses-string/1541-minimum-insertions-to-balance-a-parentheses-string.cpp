class Solution {
public:
    int minInsertions(string s) {
        int open=0,n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open+=2;
                if(open%2==1){
                    ans++;
                    open--;
                }
            }
            else{
                open--;
                if(open<0){
                    ans++;
                    open+=2;
                }
            }
        }
        return ans +open;
    }
};