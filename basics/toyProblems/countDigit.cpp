#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    while(n!=0){
        n=n/10;
        ans+=1;
    }
    cout<<ans;

}