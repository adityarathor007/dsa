#include <iostream>
using namespace std;

// instead of taking O(N) it will take O(logN)
int fastExpon(int b,int n){
    int ans=1;
    while(b>0){
        int lastBit=n&1;
        if(lastBit){
            ans=ans*b;
        }
        b=b*b;
        n=n>>1;
        
        
    }
    
    
    return ans;
}



int main(){
    int n;
    int b;
    cin>>b;
    cin>>n;
    cout<<fastExpon(b,n)<<endl;
    
    return 0;
    
}