class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int sp=image[sr][sc];
        if(sp==color) return image;
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        int rd[4]={0,-1,0,1};
        int cd[4]={1,0,-1,0};
        q.push({sr,sc});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+rd[i];
                int nc=c+cd[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==sp){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};