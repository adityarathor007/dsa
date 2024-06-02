#include <iostream>
using namespace std;


int getIthbit(int n,int i){
    int x=(1<<i);
    if(n&x){
        return 1;
    }
    else{
        return 0;
    }
    
}

void setIthBit(int &n,int i){  //means making the ith bit one
     int x=(1<<i);
     n=n|x;
}

void clearIthBit(int &n,int i){  //means making the ith bit zero
     int x=(1<<i);
     n=n&(~x);
}

void updateIthBit(int &n,int i,int b){
    // if(b==1){
    //     setIthBit(n, i);
    // }
    // else{
    //     clearIthBit(n, i);
    // }
    // alternative
    clearIthBit(n, i);
    int mask=(b<<i);
    n=n|mask;
}


int clearlastIthBits(int n,int l){
    int mask=(-1<<l);
    int ans;
    ans=n&mask;
    return ans;
}


int main(){
    
    int n=13;
    // int i;
    // cin>>i;
    
    // cout<<getIthbit(n,i)<<endl;
    // setIthBit(n, i);
    // clearIthBit(n,i);
    // updateIthBit(n, i, 0);
    int l=3;
    cout<<clearlastIthBits(n,l)<<endl;
    // cout<<n<<endl;
    
    return 0;
}