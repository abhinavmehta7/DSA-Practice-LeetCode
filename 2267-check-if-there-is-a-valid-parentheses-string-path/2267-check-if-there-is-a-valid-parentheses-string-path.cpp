class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        //will have to use bfs algo with counting the open and close 
        int n=grid.size(),m=grid[0].size();
        queue<tuple<int,int,int>> q;
        if(grid[0][0]==')' || grid[n-1][m-1]=='(' || (m+n-1)%2==1) return false;
        bool vis[100][100][100]={false};
        q.push({0,0,1});
        int arr[]={0,1,0};
        while(!q.empty()){
            auto [i,j,count]=q.front();
            q.pop();
            if(i==n-1 && j==m-1 && count==0) return true;
            for(int k=0;k<2;k++){
                int ni=i+arr[k];
                int nj=j+arr[k+1];
                if(ni<n && nj<m){
                    int nc = count + (grid[ni][nj] == '(' ? 1 : -1);
                    if(nc>=0 && nc<=(n+m)/2 && !vis[ni][nj][nc]){
                        q.push({ni,nj,nc});
                        vis[ni][nj][nc]=true;
                    }
                }
            }
        }
        return false;
    }
};