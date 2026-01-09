#include <iostream>
#include<vector>
using namespace std;

void setMatrixZero(vector<vector<int>>&arr){
    // using O(n+m) space and O(n^2) time complexity
    // int n=arr.size();
    // int m=arr[0].size();
    // vector<int>rows(n,0);
    // vector<int>cols(m,0);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(arr[i][j]==0){
    //             rows[i]=1;
    //             cols[j]=1;
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++ ) {
    //     for(int j = 0; j < m; j++) {
    //        if(rows[i] || cols[j]){
    //         arr[i][j]=0;
    //        }

    //      }
    // }


    // using O(1) space complexity because bringing the row and column in the first row and column of the matrix
    int m=matrix.size();
    int n=matrix[0].size();

    bool colmZero=false;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!matrix[i][j]){
                if(j==0){
                    colmZero=true;
                    matrix[i][0]=0;
                }
                else{
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
    }

    for(int i=m-1;i>0;i--){
        for(int j=n-1;j>0;j--){
            if(!matrix[i][0] or !matrix[0][j]) matrix[i][j]=0;
        }
    }

    //for the first row setting them zero now 
    for(int j=1;j<n;j++){
        if(!matrix[0][0]) matrix[0][j]=0;
    }

    if(colmZero){
        for(int i=0;i<m;i++) matrix[i][0]=0;
    }

    return ;

}



int main(){
    vector<vector<int>>input{{1,1,2,1},{0,4,0,2},{3,0,1,5}};
    setMatrixZero(input);

    int n=input.size();
    int m=input[0].size();

    for (int i = 0; i < n; i++ ) {
        for(int j = 0; j < m; j++) {
           cout<<input[i][j]<<",";
         }
         cout<<endl;
    }


}
