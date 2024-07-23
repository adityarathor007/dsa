#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int num=n;
    int count=0;
    while(n!=0){
        n=n/10;
        count+=1;
    }
    
    int ans=0;
    while(num!=0){
        int last_dig=num%10;
        ans+=last_dig*pow(10,count-1);
        num=num/10;
        count-=1;
    }

    cout<<ans<<endl;


}