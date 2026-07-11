class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,long long>> adj[n];
        for(auto& x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LLONG_MAX);
        long long k=1e9+7;
        vector<long long> ways(n,0);
        ways[0]=1;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            long long d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if (d > dist[node]) continue;
            for(auto& [no,wt]:adj[node]){
                if(dist[no]>d+wt){
                    ways[no]=ways[node];
                    dist[no]=d+wt;
                    pq.push({d+wt,no});
                }
                else if(dist[no]==d+wt){
                    ways[no]=(ways[node]%k+ways[no]%k)%k;
                }
            }
        }
        return ways[n-1];
    }
};