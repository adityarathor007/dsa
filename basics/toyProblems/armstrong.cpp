#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int num=n;
    int sum=0;
    int count=0;
    while(n!=0){
        n=n/10;
        count+=1;
    }
    n=num;
    while(n!=0){
        int ld=n%10;
        sum+=pow(ld,count);
        n=n/10;
    }
    if(sum==num){
        cout<<"Yes it is a Armstrong Number"<<endl;
    }
    else{
        cout<<"Not a armstrong number"<<endl;
    }

}