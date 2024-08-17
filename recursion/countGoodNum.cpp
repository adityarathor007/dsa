#include <iostream>
#include <vector>
using namespace std;

    // long long recFunc(long long n){
    //     cout<<n<<",";
    //     long long M = 1000000007;
    //     if(n==1){
    //         return 5;
    //     }
    //     if(((n-1)&1)==0){
    //         return (5*(recFunc(n-1)%M)%M);
    //     }
    //     return (4*(recFunc(n-1)%M)%M);
    // }

    // int countGoodNumbers(long long n) {
    //     long long M = 1000000007;
    //     long long ans=recFunc(n%M);
    //     cout<<endl;

    //     return ans%M;

    // }
    int M=1e9+7;

    long long binaryExp(long long b,long long e,long long ans){
        if(e==0) return ans;
        if(e&1) return binaryExp(b,e-1,(ans*b)%M);
        else return binaryExp((b*b)%M,e/2,ans);
    }

int main(){
    long long temp=binaryExp(20,n/2,1);
    return (n&1)?(temp*5)%M:temp;   
   
}