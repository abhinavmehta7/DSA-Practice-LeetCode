class Solution {
public:
    int maxProduct(int n) {
        int d1=-1,d2=-1;
        string s=to_string(n);
        for(int i=0;i<s.size();i++){
            int dig=s[i]-'0';
            if(dig>=d1){
                d2=d1;
                d1=dig;
            }
            else if(d2==-1 || dig>d2) d2=dig;
        }
        return d1*d2;
    }
};