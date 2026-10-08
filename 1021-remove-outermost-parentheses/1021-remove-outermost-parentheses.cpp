class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string k;
        int flag=0;
        for(int i=0,j=0;i<n;i++){
            
            if(s[i]==')'){
                flag--;
                if(flag>0){
                    k+=s[i];
                }
            }
            else{
                if(flag>0){
                    k+=s[i];
                }
                flag++;
            }
        }
        return k;
    }
};