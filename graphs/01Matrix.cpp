#include<iostream>
#include <vector>
#include<queue>
using namespace std;


vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));

        vector<vector<int>>visited(m,vector<int>(n,0));

        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                 q.push({{i,j},0});
                 visited[i][j]=1;
            }
               
                
            }
        }
        

        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
       
    
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.first.first;
            int y=p.first.second;
            int cd=p.second;
            cout<<x<<y<<cd<<endl;
            ans[x][y]=cd;
            
            
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 and ny>=0 and nx<m and ny<n and visited[nx][ny]==0){
                    cout<<nx<<","<<ny<<","<<cd+1<<endl;
                    q.push({{nx,ny},cd+1});
                    visited[nx][ny]=1;
                }
            }
        }

        return ans;
}


int main(){
    vector<vector<int>>matrix{{0,0,0},{0,1,0},{0,0,0}};
    auto ans=updateMatrix(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<ans[i][j]<<",";
        }
        cout<<endl;
    }
}