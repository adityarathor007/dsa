#include<iostream>
#include<math.h>
#include <cmath>
#include <algorithm> 
#include<vector>
using namespace std;

    

int main(){
    int a,b;
    cin>>a>>b;
    // int gcd=1;
    // for(int i=1;i<=min(a,b);i++){
    //     if(a%i==0 and b%i==0){
    //         gcd=i;
    //     }
    // }
    
    // cout<<gcd<<endl;

    // using the eucledian method gcd(a%b,b) why a%b as according the eucledian algorithnm gcd(a,b)=gcd(a-b,b) and we keep on subtracting untill it becomes smaller than b and this equivalen to getting the remainder
    while(a>0 and b>0){
        if(a>b){
            a=a%b;
        }
        else{
            b=b%a;
        }

    }
    if(a==0) cout<<b<<endl;
    else cout<<a<<endl;
    



}