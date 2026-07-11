class Solution {
public:
    void dfs(int node,vector<int>& vis,vector<int> adj[],int count){
        vis[node]=count;
        for(auto& n:adj[node]){
            if(!vis[n]) dfs(n,vis,adj,count);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //part 1:-give each conected component a no.
        vector<int> adj[n];
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,0);
        int count=1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj,count);
                count++;
            }
        }
        // we now have a each connected nodes and have to check if cyclic 
        vector<int> nodes(n+1,0);
        for(int i=0;i<n;i++){
            nodes[vis[i]]++;
        }
        for(int i=0;i<n;i++){
             
        }
        vector<bool> valid(count, true);
        for(int i = 0; i < n; i++){
           if(adj[i].size()!=nodes[vis[i]]-1) {
                valid[vis[i]] = false;
            }
        }
        int ans = 0;
        for(int c = 1; c < count; c++){
            if(valid[c]) {
            ans++;
            }
        }
        return ans;
    }
};