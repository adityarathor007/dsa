#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

// *
// **
// ***
// ***
// **
// *

// for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }

// for(int i=0;i<n;i++){
//         for(int j=0;j<n-i;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }

// 1 
// 0 1 
// 1 0 1 
// 0 1 0 1 
// 1 0 1 0 1 
// 0 1 0 1 0 1 
// 1 0 1 0 1 0 1 

bool isOne;

for(int i=0;i<n;i++){
    if(i%2==0){
        isOne=true;
    }
    else{
        isOne=false;
    }
    for(int j=0;j<=i;j++){
        if(isOne){
        cout<<"1"<<" ";
        isOne=false;
        }
        else{
            cout<<"0"<<" ";
            isOne=true;
        }
    }
    cout<<endl;
}





}