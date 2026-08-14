class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> v(26,0);
        int len=1;
        for(int i=0,j=0;i<s.size();i++){
            v[s[i]-'a']++;
            while(j<i && v[s[i]-'a']>2){
                v[s[j]-'a']--;
                j++;
            }
            len=max(len,i+1-j);
        }
        return len;
    }
};