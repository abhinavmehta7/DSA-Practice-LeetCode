class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        int dist=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},dist});
                    vis[i][j]=1;
                }
            }
        }
        int rd[]={0,-1,0,1};
        int cd[]={1,0,-1,0};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+rd[i];
                int nc=c+cd[i];
                if(nr<n && nr>=0 && nc<m && nc>=0 && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    mat[nr][nc]=d+1;
                    q.push({{nr,nc},d+1});
                }
            }
        }
        return mat;
    }
};