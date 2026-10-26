class Solution {
public:
    int n,m;
    int arr[5]={0,1,0,-1,0};
    vector<vector<int>> vis;
    long long dfs(vector<vector<int>>& grid,int i,int j){
        vis[i][j]=1;
        long long sum=grid[i][j];
        for(int k=0;k<4;k++){
            int ni=i+arr[k];
            int nj=j+arr[k+1];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]!=0 && !vis[ni][nj]) sum+=1LL*dfs(grid,ni,nj);
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        vis.assign(n, vector<int>(m, 0));
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 || vis[i][j]) continue;
                if(dfs(grid,i,j)%k==0) ans++;
            }
        }
        return ans;
    }
};