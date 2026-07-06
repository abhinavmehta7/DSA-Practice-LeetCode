class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int dir[]={0,1,0,-1,0};
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (i==0 || i==n-1 || j==0 || j==m-1)){
                    q.push({i,j});
                    grid[i][j]=5;
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dir[i];
                int nc=c+dir[i+1];
                if(nc>=0 && nc<m && nr>=0 && nr<n && grid[nr][nc]==1){
                    grid[nr][nc]=5;
                    q.push({nr,nc});
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};