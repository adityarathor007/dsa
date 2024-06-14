#include <iostream>
using namespace std;

bool canPlace(vector <vector<int > > &input,int n,int x,int y){
    //check for column
    for(int i=0;i<x;i++){
        if(input[i][y]==1){
            return false;
        }
    }
    
    //check for left diagonal
    int i=x-1;
    int j=y-1;
    while(i>=0 and j>=0){
        if(input[i][j]==1){
            return false;
        }
        i--;
        j--;
    }
    
    // checking the right diagonal
    i=x-1;
    j=y+1;
    while(i>=0 and j<n){
        if(input[i][j]==1){
            return false;
        }
        i--;
        j++;
    }
    
    return true;
    
}


bool placeNQueen(vector <vector<int > > &input,int n,int i){
    if(i==n){
        return true;
    }
    
    for(int j=0;j<9;j++){
        if(canPlace(input,n,i,j)){
            input[i][j]=1;
            bool successChild=placeNQueen(input, n, i+1);
            if(successChild){
                return true;
            }
            input[i][j]=0;
        }
    }
    
    return false;
}


int nQueen(int n){
//Write your code below. Do not modify this function or parameters. You can use helper function if needed.    
int i=0;
vector <vector <int> > input;
placeNQueen(input, n, i);
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<input[i][j]<<" ";
    }
    cout<<endl;
}
return n;

}

int main(){
    int n;
    cin>>n;
    cout<<nQueen(n)<<endl;
}