#include <iostream>
#include <vector>
using namespace std;



double myPow(double x, int n) {

       // iterative method (not optimized)
    //    double ans=1;
    //     if(n<0){
    //         x=1/x;
    //         n*=-1;
    //     }
    //     for(int i=0;i<n;i++){
    //         ans*=x;
    //     }
    //     return ans;

    //binary exponentitation method
        if(n==0) return 1;
        if(n<0) {
            if(n==INT_MIN) return 1/x*myPow(x,n+1);
            return 1/myPow(x,-n);
        }

        if(n&1){
            return myPow(x,n-1)*x;
        }
        return myPow(x*x,n/2);

    }

int main(){

    cout<<myPow(2.10000,3)<<endl;
}
