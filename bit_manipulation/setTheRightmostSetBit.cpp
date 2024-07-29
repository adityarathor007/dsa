#include<iostream>
using namespace std;

int setBit(int n) {
        // Write Your Code here
        int f_unset_bit;
        int t=n;
        for(int i=0;i<32;i++){
            
            if((t&1)==0){
                f_unset_bit=i;
                break;
            }
            t=t>>1;
            
        }
        
        int mask=1<<f_unset_bit;
        return (n|mask);
    }

int main(){
    cout<<setBit(15)<<endl;
}