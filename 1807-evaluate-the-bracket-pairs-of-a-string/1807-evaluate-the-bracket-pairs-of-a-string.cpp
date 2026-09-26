class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.size(),m=knowledge.size();
        bool bracopen=0;
        map<string,string> mp;
        for(auto it:knowledge){
            mp[it[0]]=it[1];
        }
        string ans="",t="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                bracopen=1;
                t="";
                continue;
            }
            else if(s[i]==')'){
                bracopen=0;
                if(mp.find(t)!=mp.end()) ans+=mp[t];
                else ans+='?';
                continue;
            }
            if(bracopen){
                t+=s[i];
            }
            else ans+=s[i];
        }
        return ans;
    }
};