// input: n and m
// output: n√m

#include <iostream>
#include <cmath>
using namespace std;

int findNthRoot(int n,int m) {
    if(n==1) return m;
    int l=0,r=m/2;
    while(l<=r){
        int mid=l+(r-l)/2;
        int curr=pow(mid,n);
        if(curr==m) return mid;
        if(curr<m) l=mid+1;
        else r=mid-1;

    }

    return -1;
}

int main() {
    int n=2;
    int m=16;
    int ans=findNthRoot(n,m);

    cout<<"Output: "<<ans<<endl;
    return 0;
}
