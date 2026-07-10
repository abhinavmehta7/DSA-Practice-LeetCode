class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int dir[5]={0,1,0,-1,0};
        pq.push({0,{0,0}});
        int ans=INT_MAX;
        while(!pq.empty()){
            auto [wt,cord]=pq.top();
            auto [r,c]=cord;
            pq.pop();
            if(r==n-1 && c==m-1) ans=min(ans,wt);
            if(wt>dist[r][c]) continue;
            for(int i=0;i<4;i++){
                int nr=r+dir[i];
                int nc=c+dir[i+1];
                if(nr>=0 && nc>=0 && nr<n && nc<m ){
                    int nw=max(abs(heights[nr][nc]-heights[r][c]),wt);
                    if(dist[nr][nc]>nw){
                        dist[nr][nc]=nw;
                        pq.push({nw,{nr,nc}});
                    }
                }
            }
        }
        return ans;
    }
};