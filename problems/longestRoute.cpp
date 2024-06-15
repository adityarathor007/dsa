#include <iostream>
#include <vector>
using namespace std;
int cnt;


bool place(vector<int> &ans, int n,vector< vector <int> > &c,int i,int j){
    
    // cout<<"the value of position is: " <<c[i][j]<<endl;
    // cout<<"the value of i is: "<<i<<endl;
    // cout<<"the value of j is: "<<j<<endl;
    
    //reach end;
    if(i==n-1 and j==n-1){
        ans.push_back((n*i+j)+1);
        cnt+=1;
        return true ;
    }
    
    if(i==n or j==n or i==-1 or j==-1){
        return false;
    }
    
    //if not valid position
    if(c[i][j]==0){
        return false;
    }
   
    bool success = place(ans,n,c,i,j+1); //checking child in right direction
    if(success){
        ans.insert(ans.begin(),(n*i+j)+1);
        cnt+=1;
        return true;
    }
        
    success=place(ans,n,c,i+1,j);  //checking child in down direction
    if(success){
        ans.insert(ans.begin(),(n*i+j)+1);
        cnt+=1;
        return true;
    }
    success=place(ans,n,c,i-1,j);  //checking child in left direction
    if(success){
        ans.insert(ans.begin(),(n*i+j)+1);
        cnt+=1;
        return true;
    }
    success=place(ans,n,c,i,j+1);  //checking child in up direction
    if(success){
        ans.insert(ans.begin(),(n*i+j)+1);
        cnt+=1;
        return true;
    }
    
    
    return false;
}

int findLongestPath(int m, int n, vector<vector<int> > c){
    auto check = place(n,c,0,0);
    //Complete this function. Do not modify the name or parameters. You can make a helper function if needed.
}



int main(){
    int n=3;
    vector<vector<char> > c={
    {1,1,1},
    {1,1,1},
    {0,0,1}
    };
    
}