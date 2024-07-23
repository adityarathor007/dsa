#include<iostream>
#include<math.h>
#include <cmath>
#include <algorithm> 
#include<vector>
using namespace std;

// exact defination of prime number: a number which has exact 2 factors 1 and itself


int main(){
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            count+=1;
            if((n/i)!=i){
                count+=1;
            }
        }
        if(count>2){
            break;
        }
    }
    if(count!=2){ //count==1 for n=1 which also not a prime
        cout<<"Not a prime"<<endl;
    }
    else{
        cout<<"Yes it is prime"<<endl;
    }
}
