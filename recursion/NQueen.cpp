//  print the board for all possible combination
    


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



bool canPlace(int board[][20],int n,int x,int y){


    //coloumn check
    for(int i=0;i<x;i++){
        if(board[i][y]==1){
            return false;
        }
    }


    //for left diag
    int i=x-1;
    int j=y-1;
    while (i>=0 and j>=0)
    {
        if(board[i][j]==1){
            return false;
        }
        i--;j--;
    }




    //for right diag
    i = x - 1;
    j = y + 1;
    while (i >= 0 and j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}




void printBoard(int board[][20],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}



bool solveNQueen(int board[][20],int n,int i){

    //base case
    if(i==n){
        printBoard(board,n);
        return true;
    }


    //rec case
    for(int j=0;j<n;j++){
        if(canPlace(board,n,i,j))
        {
            board[i][j]=1;

            bool success=solveNQueen(board,n,i+1);

            if(success){
                return true;

            }
            //backtrack if false in child
            board[i][j] = 0;
        }

    }
    return false;  //if the queen cant be pladced


}



int main(){
    int board[20][20]={0};
    int n;
    cin>>n;
    int i=0;

    solveNQueen(board,n,i);

    return 0;
}
