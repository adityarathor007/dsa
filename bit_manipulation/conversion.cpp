#include<iostream>
using namespace std;
// find the number of flip required to convert a number into another number


int main(){
    int n,m;
    cin>>n>>m;
    int count=0;
    for(int i=0;i<32;i++){
        int bit1=n&1;
        int bit2=m&1;
        
        n=n>>1;
        m=m>>1;
        if(bit1^bit2==1){
            count+=1;
        }
    }
    
    cout<<count<<endl;

}