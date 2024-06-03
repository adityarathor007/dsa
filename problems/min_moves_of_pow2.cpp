#include <iostream>
using namespace std;

int earthLevel(int k)
{
    int ans=0;
    while(k>0){
        int out=(k&1);
            if(out==1){
                 ans+=1;
            }
            k=k>>1;
       
    }
    return ans;
    
}


int main(){
    int n=2; 
    cout<<earthLevel(n)<<endl;
}