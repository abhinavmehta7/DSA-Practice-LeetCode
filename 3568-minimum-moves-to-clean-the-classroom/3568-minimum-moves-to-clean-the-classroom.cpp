class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n=classroom.size(),m=classroom[0].size();
        vector<vector<int>> litt(n,vector<int>(m,-1));
        int lit=0;
        queue<tuple<int,int,int,int,int>> q;//x,y,hlth,moves,mask;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j]=='L'){
                    litt[i][j]=lit++;
                }
                else if(classroom[i][j]=='S') q.push({i,j,energy,0,0});
            }
        }
        vector<vector<vector<int>>> vis(
            n, vector<vector<int>>(m, vector<int>(1 << lit, -1))
        );
        int target = (1 << lit) - 1;
        int dirx[]={-1,0,1,0};
        int diry[]={0,-1,0,1};
        while(!q.empty()){
            auto [x,y,hlth,moves,mask]=q.front();
            if (mask == target) {
                return moves;
            }
            q.pop();
            if (hlth == 0) continue;
            for(int i=0;i<4;i++){
                int nx=x+dirx[i];
                int ny=diry[i]+y;
                if(nx>=0 && ny>=0 && nx<n && ny<m && classroom[nx][ny]!='X' ){
                    int nm=mask;
                    int nhlth=hlth-1;
                    if(classroom[nx][ny]=='R') nhlth=energy;
                    if(litt[nx][ny]!=-1) nm |= (1 << litt[nx][ny]);
                    if (nhlth > vis[nx][ny][nm]) {
                        vis[nx][ny][nm] = nhlth;
                        q.push({nx,ny,nhlth,moves+1,nm});
                    }
                }
            }
        }
        return -1;
    }
};