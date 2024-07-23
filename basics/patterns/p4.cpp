#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********

// divide the pattern into 4 parts like a quadrant
// for(int i=0;i<n;i++){
//         for(int j=0;j<n-i;j++){
//             cout<<"*";
//         }
//         // for space in between 
//         for(int j=0;j<2*i;j++){
//             cout<<" ";
//         }
//         for(int j=0;j<n-i;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<"*";
//         }
//         for(int j=0;j<2*(n-i-1);j++){
//             cout<<" ";
//         }

//         for(int j=0;j<=i;j++){
//             cout<<"*";
//         }

//         cout<<endl;
//     }




// *        *
// **      **
// ***    ***
// ****  ****
// **********
// **********
// ****  ****
// ***    ***
// **      **
// *        *


// for(int i=0;i<n;i++){
//     for(int j=0;j<=i;j++){
//         cout<<"*";
//     }
//     for(int j=0;j<2*(n-i-1);j++){
//         cout<<" ";
//     }
//     for(int j=0;j<=i;j++){
//         cout<<"*";
//     }

//     cout<<endl;

// }
// for(int i=0;i<n;i++){
//     for(int j=0;j<(n-i);j++){
//         cout<<"*";
//     }

//     for(int j=0;j<2*i;j++){
//         cout<<" ";
//     }

//     for(int j=0;j<(n-i);j++){
//         cout<<"*";
//     }

//     cout<<endl;

// }

// ‘N’*’N’ matrix corresponding to the given star pattern.
// **********
// *        *
// *        *
// *        *
// **********
// for(int i=0;i<n;i++){
//     if(i==0 or i==n-1){
//         for(int j=0;j<2*n;j++){
//             cout<<"*";
//         }
//     }
//     else{
//         cout<<"*";
//         for(int j=0;j<2*(n-1);j++){
//             cout<<" ";
//         }
//         cout<<"*";
//     }

//     cout<<endl;
// }


    // return 0;

}