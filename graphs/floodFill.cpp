class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>> q;
        int target_color=image[sr][sc];
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>>ans=image;
        q.push({sr,sc});
        visited[sr][sc]=1;
        ans[sr][sc]=color;
        

       
        while(!q.empty()){
            auto p=q.front();
            int x=p.first;
            int y=p.second;
            
            q.pop();
            int dx[]={-1,0,1,0};
            int dy[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and ny>=0 and nx<m and ny<n and image[nx][ny]==target_color and visited[nx][ny]==0){
                    q.push({nx,ny});
                    visited[nx][ny]=1;  
                    ans[nx][ny]=color;

                }
            }
        }

        return ans;
    }
};