class Solution {
public:
    void transverse(int node,vector<vector<int>>& v,vector<int>& ans){
        ans[node]=1;
        for(auto& x:v[node]){
            if(!ans[x]){
                transverse(x,v,ans);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        vector<int> ans(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!ans[i]){
                transverse(i,v,ans);
                count++;
            }
        }
        return count;
    }
};