class Solution {
public:
    void bfs(vector<vector<char>>& grid,int r,int c,int m,int n){
        const int dir[]={0,1,0,-1,0};
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c]='0';
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dir[i];
                int nc=c+dir[i+1];
                if(nc>=0 && nc<m && nr>=0 && nr<n && grid[nr][nc]=='1'){
                    grid[nr][nc]='0';
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};