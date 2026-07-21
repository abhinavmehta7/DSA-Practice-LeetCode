class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for(char c : s)
            if(c == '1')
                ones++;

        s = "1" + s + "1";
        int n = s.size();
        int i = 0;
        int ans = ones;
        while(i < n && s[i] == '1')  i++;
        int l0 = 0;
        while(i < n && s[i] == '0'){
            l0++;
            i++;
        }
        while(i < n){
            int m1 = 0;
            while(i < n && s[i] == '1'){
                m1++;
                i++;
            }
            if(m1 == 0)  break;
            int r0 = 0;
            while(i < n && s[i] == '0'){
                r0++;
                i++;
            }
            if(r0 == 0)  break;
            ans = max(ans, ones + l0 + r0);
            l0 = r0;
        }
        return ans;
    }
};