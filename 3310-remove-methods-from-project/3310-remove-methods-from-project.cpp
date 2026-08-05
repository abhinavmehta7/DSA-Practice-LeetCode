class Solution {
public:
    void dfs(vector<int> adj[],vector<int>& vis,int node){
        vis[node]=1;
        for(auto& it:adj[node]){
            if(!vis[it])
                dfs(adj,vis,it);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> node[n];
        for (auto& inv : invocations) {
            node[inv[0]].push_back(inv[1]);
        }
        vector<int> vis(n,0);
        dfs(node,vis,k);
        bool rm=true;
        for (auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!vis[u] && vis[v]) {
                rm = false;
                break;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!rm || !vis[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};