#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

// 1      1
// 12    21
// 123  321
// 12344321

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i+1;j++){
    //         cout<<j+1;
    //     }
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }

    //     for(int j=i+1;j>0;j--){
    //         cout<<j;
    //     }
    //     cout<<endl;

    // }

// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10 
    // int c=1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<c<<" ";
    //         c+=1;
    //     }
    //     cout<<endl;
    // }



// Good for handling ascii and char
// A 
// A B 
// A B C 
// A B C D 

    // for(int i=0;i<n;i++){
    //     char ch='A';
    //     int ascii=int(ch);
    //     for(int j=0;j<=i;j++){
            
    //         cout<<char(ascii+j);
            
    //     }
    //     cout<<endl;
    // }


// A B C D 
// A B C 
// A B 
// A 



    // for(int i=0;i<n;i++){
    //     char ch='A';
    //     int ascii=int(ch);
    //     for(int j=0;j<(n-i);j++){
            
    //         cout<<char(ascii+j);
            
    //     }
    //     cout<<endl;
    // }


// A
// BB
// CCC
// DDDD

    // for(int i=0;i<n;i++){
    //     char ch='A';
    //     int ascii=int(ch)+i;
    //     for(int j=0;j<=i;j++){
            
    //         cout<<char(ascii);
            
    //     }
    //     cout<<endl;
    // }



    // A    
//    ABA   
//   ABCAB  
//  ABCDABC 

// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i;j++){
//         cout<<" ";
//     }
//     char ch='A';
//     int ascii=int(ch);
//     int j=0;
//     for(j=0;j<i;j++){
//         cout<<char(ascii+j);
//     }
//     cout<<char(ascii+j);

    
//     for(int j=0;j<i;j++){
//         cout<<char(ascii+j);
//     }


//     for(int j=0;j<n-i;j++){
//         cout<<" ";
//     }
//     cout<<endl;
// }


// E 
// E D 
// E D C 
// E D C B 
// E D C B A 

char ch='A';
int ascii=int(ch)+(n-1);
for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
        cout<<char(ascii-j)<<" ";
        }
        cout<<endl;
    }


}