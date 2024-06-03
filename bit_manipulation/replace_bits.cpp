#include <iostream>
using namespace std;

// 2 32 bit numbers are given N and M, and 2 bit positions i and j.
// Write a method to set all bits between i and j in N equal to M.
// M(becomes a substring of N locationed at and starting at j)
// Example:
// N=10000000000;  (1024)
// M=10101;(21)
// i=2 j=6;
// Output: 10001010100; (1108)




void clearBitsInRange(int &n,int i,int j){
    int mask1=(-1<<(j+1));
    int mask2=~(-1<<(i));
    cout<<"the mask2: "<<mask2<<endl;
    int mask_range=mask1|mask2;
    cout<<mask_range<<endl;
    n=n&mask_range;
    
}

int replaceBits(int n,int m,int i, int j){
    clearBitsInRange(n,i,j);
    cout<<n<<endl;
    int mask_m=(m<<i);
    int ans=n|mask_m;
    return ans;
    
}


int main(){
    
    int n=1024;
    int m=21;
    int i=2;
    int j=6;
    cout<<replaceBits(n,m,i,j)<<endl;
    return 0;
}