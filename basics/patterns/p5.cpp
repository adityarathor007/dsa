#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

// 4 4 4 4 4 4 4 
// 4 3 3 3 3 3 4 
// 4 3 2 2 2 3 4 
// 4 3 2 1 2 3 4 
// 4 3 2 2 2 3 4 
// 4 3 3 3 3 3 4 
// 4 4 4 4 4 4 4 

    int s=(2*n)-1;
    
    // vector<vector<int>> arr(s,vector<int>(s,0));
    // int k=1;
    // using the idea of padding
    // while(k<=n){
    
    //     for(int i=s/2-(k-1);i<=s/2+(k-1);i++){
    //     if(i==s/2-(k-1) or i==s/2+(k-1)){
    //         for(int j=s/2-(k-1);j<=s/2+(k-1);j++){
    //             arr[i][j]=k;
    //         }
    //     }
    //     else{
    //         arr[i][s/2-(k-1)]=k;
    //         arr[i][s/2+(k-1)]=k;
    //     }
    // }
    //     k++;
        
    // }

    // for(int i=0;i<s;i++){
    //     for(int j=0;j<s;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


// solved for this 
// 0 0 0 0 0 0 0 0 0 
// 0 1 1 1 1 1 1 1 0 
// 0 1 2 2 2 2 2 1 0 
// 0 1 2 3 3 3 2 1 0 
// 0 1 2 3 4 3 2 1 0 
// 0 1 2 3 3 3 2 1 0 
// 0 1 2 2 2 2 2 1 0 
// 0 1 1 1 1 1 1 1 0 
// 0 0 0 0 0 0 0 0 0 



// 5 5 5 5 5 5 5 5 5 
// 5 4 4 4 4 4 4 4 5 
// 5 4 3 3 3 3 3 4 5 
// 5 4 3 2 2 2 3 4 5 
// 5 4 3 2 1 2 3 4 5 
// 5 4 3 2 2 2 3 4 5 
// 5 4 3 3 3 3 3 4 5 
// 5 4 4 4 4 4 4 4 5 
// 5 5 5 5 5 5 5 5 5 



    // simpler method
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            int top=i;
            int left=j;
            int bottom=s-1-i;
            int right=s-1-j;
            int k=min(min(top,left),min(bottom,right));
            cout<<k<<" ";


        }
        cout<<endl;
    }


    
return 0;
}