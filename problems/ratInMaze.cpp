#include <iostream>
#include <vector>
using namespace std;
int cnt;

bool place(vector<int> &ans, int n,vector< vector <char> > &c,int i,int j){
    
    // cout<<"the value of position is: " <<c[i][j]<<endl;
    // cout<<"the value of i is: "<<i<<endl;
    // cout<<"the value of j is: "<<j<<endl;
    
    //reach end;
    if(i==n-1 and j==n-1){
        ans.push_back((n*i+j)+1);
        cnt+=1;
        return true ;
    }
    
    //if not valid position
    if(c[i][j]=='X'){
        return false;
    }
   
    if(j!=n-1){
    bool success = place(ans,n,c,i,j+1); //checking child in row direction
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
    }
    else{
        bool success=place(ans,n,c,i+1,j);  //checking child in down direction
        if(success)
        {
            ans.insert(ans.begin(),(4*i+j)+1);
            cnt+=1;
            return true;
        }
    }
    return false;
}


vector<int> findPath(int n, vector< vector <char> > c){
    vector<int> ans;
    cnt=0;
    auto check=place(ans,n,c,0,0);
   cout<<"the number of steps required to reach destination: "<<cnt<<endl;
    return ans; 
}


int main(){ 
    int n=3;
    // vector<vector<char> > c={
    // {'O','O','O','O'},
    // {'O','X','O','O'},
    // {'O','O','O','X'},
    // {'O','O','O','O'},
    // };
    vector<vector<char> > c={
    {'O','O','X'},
    {'O','X','O'},
    {'O','O','O'}
    };
   auto ans=findPath(n,c);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout <<endl;
    
}