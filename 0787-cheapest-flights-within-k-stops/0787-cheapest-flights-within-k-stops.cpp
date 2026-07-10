class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto& x:flights){
            int n1=x[0],n2=x[1],wt=x[2];
            adj[n1].push_back({n2,wt});
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<int,int>> pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty() && k>=0){
            int t=pq.size();
            for(int i=0;i<t;i++){
                int d=pq.front().first;
                int node=pq.front().second;
                pq.pop();
                for(auto& it:adj[node]){
                    if(dist[it.first]>d+it.second){
                        dist[it.first]=d+it.second;
                        pq.push({d+it.second,it.first});
                    }
                }
            }
            k--;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};