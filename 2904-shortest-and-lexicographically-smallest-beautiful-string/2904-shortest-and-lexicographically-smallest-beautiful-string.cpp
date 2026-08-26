class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size(),count=0;
        string ans="";
        for(int i=0,j=0;i<n;i++){
            if(s[i]=='1') count++;
            while(count==k){
                while(s[j]=='0'){
                    j++;
                }
                string curr=s.substr(j,i-j+1);
                if(ans.empty() || curr.size()<ans.size() || (curr.size()==ans.size() && curr<ans)) ans=curr;
                if(s[j]=='1') count--;
                j++;
            }
        }
        return ans;
    }
};