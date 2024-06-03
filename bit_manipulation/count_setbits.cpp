#include <iostream>
using namespace std;

int countSetBits(int n){
    int count=0;
    // while(n>0){
    //     int last_bit=n&1;
    //     count+=last_bit;
    //     n=n>>1;
        
        
    // }  // will go logN i.e through each bit of the number  as a number N has atmost LogN bits 
    
    // shorter method is that in each iteration you move that position and remove the set bit
    while(n>0){
        n=n&n-1;
        count+=1;
    }
    
    
    
    return count;
    
    
    
}


int main(){
    int n;
    cin>>n;
    cout<<countSetBits(n)<<endl;
}