class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && (i==0 || i==n-1 || j==0 || j==m-1)){
                    q.push({i,j});
                    board[i][j]='1';
                }
            }
        }
        int rd[]={0,-1,0,1};
        int cd[]={1,0,-1,0};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+rd[i];
                int nc=c+cd[i];
                if(nr<n && nr>=0 && nc<m && nc>=0 && board[nr][nc]=='O'){
                    board[nr][nc]='1';
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='1'){
                    board[i][j]='O';
                } 
            }
        }
    }
};