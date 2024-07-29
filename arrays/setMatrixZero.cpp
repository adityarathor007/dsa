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
    int n=arr.size();
    int m=arr[0].size();
    int col_0=1;
    for (int i = 0; i < n; i++ ) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j]==0){
                if(j!=0){
                    arr[0][j]=0;
                }
                else{
                    col_0=0;
                }
                
                arr[i][0]=0;
            }
         }
    }

    for (int i = 1; i < n; i++ ) {
        for(int j = 1; j < m; j++) {
           if(arr[i][0]==0 || arr[0][j]==0){
            arr[i][j]=0;
           }
         }

    }

    if(arr[0][0]==0){
        for(int j=1;j<m;j++){
            arr[0][j]=0;
        }
    }

    if(col_0==0){
        for(int i=0;i<n;i++){
            arr[i][0]=0;
        }
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