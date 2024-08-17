#include <iostream>
#include <vector>
using namespace std;

double binaryExp(double x,long n){
             if(n==0){
            return 1;
            }


        if(n<0){
            return 1/binaryExp(x,-n);
        }
        else{
           

            if(n%2==0){
                return binaryExp(x*x,n/2);
            }
            else{
                return (binaryExp(x,n-1))*x;

            }
        }
        }


double myPow(double x, int n) {
        // double ans=1;
        
        // if(n<0){
        //     while(n!=0){
        //         ans/=x;
        //         n++;
        // }
        // }
        // else{
        //      while(n!=0){
        //     ans*=x;
        //     n--;
        // }
        // }
       

        // return ans;



        // return ans;
        binaryExp(x,long(n));
        
    }

int main(){
    
    cout<<myPow(2.10000,3)<<endl;
}