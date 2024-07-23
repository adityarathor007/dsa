#include<iostream>
#include<math.h>
using namespace std;

// reverse will be equal to original


int main(){
    int n;
    cin>>n;
    int num=n;
    int count=0;
    int ans=0;
    while(n!=0){
        int ld=n%10;
        n=n/10;
        ans=(ans*10)+ld;
    }
    
    
    if(ans==num){
        cout<<"Yes it is a palindrome"<<endl;
    }
    else{
        cout<<"Not a palindrome"<<endl;
    }


}