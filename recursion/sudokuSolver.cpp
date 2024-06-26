#include <iostream>
#include <cmath>
using namespace std;

bool canPlace(int mat[][9],int x,int y,int n,int no){
    
    // check rows and columns 
    for(int i=0;i<n;i++){
            if(mat[i][y]==no or mat[x][i]==no){
                return false;
            }
    }
    
    //checking the subgroup
    int sx=(x/3)*3;
    int sy=(y/3)*3;
    for(int i=sx;i<sx+3;i++){
        for(int j=sy;j<sy+3;j++){
            if(mat[i][j]==no){
                return false;
            }
        }
    }
    
    
    
    
    
    return true;
}




bool solveSudoku(int mat[][9],int i,int j,int n){
    //base case
    if(i==n){
        //print the sudoku
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            cout<<mat[i][j]<<",";
            }
            cout<<endl;
        }
        
        return true;
    }
    //rec case
    if(j==n){//reaching ahead of no. of columns
        return solveSudoku(mat, i+1, 0, n);
    }
    
    if(mat[i][j]!=0){
        return solveSudoku(mat, i, j+1, n);
    }
    
    for(int no=1;no<=n;no++){
        if(canPlace(mat,i,j,n,no)){
            mat[i][j]=no;
            bool success=solveSudoku(mat, i, j+1, n);
            if(success){
                return true;
            }
        }
        
        
    }
    //if no option works then backtracking
    mat[i][j]=0;
    return false;
    
    
    
}


int main(){
    int n=9;
    int mat[9][9]=
    {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
    };
    
    int i=0;
    int j=0;
    if(!solveSudoku(mat,i,j,n)){
        cout<<"No solution exist for the given intial input sudoko problem"<<endl;
    }
    
}