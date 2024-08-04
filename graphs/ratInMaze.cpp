class Solution {
  public:
    
    void findPaths(vector<vector<int>> &mat,int n,vector<vector<int>>&visited,int i,int j,string &s,vector<string>&ans){
        if(i==n-1 and j==n-1){
            ans.push_back(s);
            return ;
        }
        else{
            visited[i][j]=1;
            int dx[]={-1,0,1,0};
            int dy[]={0,-1,0,1};
            string dirn[]={"U","L","D","R"};
            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=0 and nx<n and ny>=0 and ny<n and !visited[nx][ny] and mat[nx][ny]==1){
    
                    s+=dirn[k];

                    findPaths(mat,n,visited,nx,ny,s,ans);
                    s.pop_back();
    
                    
                }
            }
            visited[i][j]=0;
            
            
        }
        return ;
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n=mat.size();

        vector<vector<int>>visited(n,vector<int>(n,0));
        vector<string>ans;
        if(mat[0][0]==0){
            return ans;
        }
        string s="";
        findPaths(mat,n,visited,0,0,s,ans);
        return ans;
        
    }
};