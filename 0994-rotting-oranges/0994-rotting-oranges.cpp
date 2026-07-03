class Solution {
public:
    void bfs(queue<pair<int,int>>& q,int& time,vector<vector<int>>& grid){
        int t=q.size();
        if(t==0) return;
        queue<pair<int,int>> que;
        while(t--){
            int i=q.front().first,j=q.front().second;
            q.pop();
            if(i+1<grid.size() && grid[i+1][j]==1){
                grid[i+1][j]=2;
                que.push({i+1,j});
            }
            if(i-1>=0 && grid[i-1][j]==1){
                grid[i-1][j]=2;
                que.push({i-1,j});
            }
            if(j-1>=0 && grid[i][j-1]==1){
                grid[i][j-1]=2;
                que.push({i,j-1});
            }
            if(j+1<grid[i].size() && grid[i][j+1]==1){
                grid[i][j+1]=2;
                que.push({i,j+1});           
            }
        }
        if (!que.empty()) {
            time++;
        }
        bfs(que,time,grid);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        bfs(q,time,grid);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};