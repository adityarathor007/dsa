#include <iostream>
#include <vector>
using namespace std;
// class Solution {
//   public:
    
//         int solve(vector<vector<int>> &mat,int i,int j,int &maxi, vector<vector<int>> &visited){
//         //base case
//         if(i>=mat.size() || j>= mat[0].size()){
//             return 0;
//         }
//         if(visited[i][j] != -1)
//         return visited[i][j];
        
//         //recursive case
//         int right=solve(mat,i,j+1,maxi,visited);
//         int diagonal=solve(mat,i+1,j+1,maxi,visited);
//         int down=solve(mat,i+1,j,maxi,visited);
        
//         if(mat[i][j]==1){
//             visited[i][j]=1+ min(right,min(diagonal,down));
//             maxi=max(maxi,visited[i][j]);
//             return visited[i][j];
//         }
//         else{
//             return visited[i][j]=0;
//         }
//     }
  
//     int maxSquare(int n, int m, vector<vector<int>> mat) {
//         // code here
//        int maxi=0;
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         solve(mat,0,0,maxi,dp);
//         return maxi;
//         }
    
// };


class Solution{
    public:
        int sub_check(vector<vector<int>> &mat,int i,int j,int n,int m, vector<vector<bool>> &visited,int c){
            if(i+c-1<n and j-c+1>=0){
                for(int x=i;x<i+c;x++){
                    for(int y=j;y>j-c;j--){
                        if(!visited[x][y]){
                            if(mat[i][j]==0){
                                return false;
                            }
                        }
                    }
                }
                return true;
            }
            return false;
        }

        int maxSquare(int n, int m, vector<vector<int>> mat) {

            vector<vector<bool>> visited(n,vector<bool>(m,false));
            int c=0;
            int ans=0;

                for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (!visited[i][j]){
                        visited[i][j] = true;
                        if(mat[i][j]==1){
                            c+=1;

                            if (sub_check(mat, i, j, n, m, visited, c)){
                                ans=max(ans,c);
                            }
                            else{
                                c-=1;
                            }
                        }
                    }
                        
                    
                }
            }
            return ans;
        }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int >> mat(n,vector<int>(m,0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout<<ob.maxSquare(n,m,mat)<<endl;

    }
    return 0;
}