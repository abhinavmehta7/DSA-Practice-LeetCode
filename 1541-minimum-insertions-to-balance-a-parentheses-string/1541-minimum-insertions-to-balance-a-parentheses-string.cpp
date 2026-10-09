class Solution {
public:
    int minInsertions(string s) {
        int close=0,n=s.size(),open=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                close+=2;
                if(close%2==1){
                    open++;
                    close--;
                }
            }
            else{
                close--;
                if(close<0){
                    open++;
                    close+=2;
                }
            }
        }
        return open + close;
    }
};