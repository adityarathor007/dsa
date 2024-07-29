#include<iostream>
using namespace std;
// you can flip exactly one bit from 0 to 1 write code to find the length of the longest seq of 1s you can get

int main(){
    int n;
    cin>>n;
    int count=0;
    int k=-1;
    int ans=0;
    for(int i=0;i<32;i++){
        int bit=n&1; //get the bit
        n=n>>1;
        cout<<bit<<",";
        if(bit==0 and k==-1){
            count+=1;
            k=count; //count when replacement happened
        }
        else if(bit==0 and k!=-1){
            ans=max(ans,count);
            count=count-k;
            count+=1;
            k=count;
        }
        else if(bit==1){
            count+=1;
        }
    }
    cout<<endl;
    ans=max(ans,count);
    cout<<ans<<endl;
}