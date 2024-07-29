#include<iostream>
#include<math.h>
using namespace std;
// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// V.imp to handle
// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.
int divide(int dividend, int divisor) {
       
        long long quotient=0;
        bool add_neg=false;
        if(dividend<0 and divisor>0){
            add_neg=true;
        }
        else if(dividend>0 or divisor<0){
            add_neg=true;
        }

        long long dividend=abs(dividend);
        long long divisor=abs(divisor);

   
        while(dividend>=divisor){
            int i=0;
            int a=divisor;
            while(a<=dividend){
                i++;
                a=divisor*pow(2,i);
                
            }
            dividend-=divisor*pow(2,i-1);
            quotient+=pow(2,i-1);
        }
        if(quotient>INT_MAX){
            if(add_neg){
                return INT_MIN;
            }
            else{
                return INT_MAX;
            }
        }

        if(add_neg){
            return -quotient;
        }
        return quotient;
    }

int main(){
    int a,b;
    cin>>a>>b;
    cout<<divide(a,b)<<endl;
}