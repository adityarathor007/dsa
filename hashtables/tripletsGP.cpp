#include <iostream>
#include <unordered_map>
using namespace std;

int findTripletsGP(vector<int> a,int r){
    unordered_map<int, int> freqLeft;
    unordered_map<int, int> freqRight;
    for(int x:a){
        freqRight[x]+=1;
        
    }
    
    
    int count=0;
    for(int x:a){
        freqRight[x]-=1; //freqRight will get dec by the element count on which element we are standing
        int x_r=x/r;
        int xr=x*r;
        

        if(freqLeft[x_r]==0 or freqRight[xr]==0){
            
            freqLeft[x]+=1; //dont forget this
            continue;
        }
        
        count+=freqLeft[x_r]*freqRight[xr];
        freqLeft[x]+=1; // as we move to the next element current element in the freqLeft will inc
    }
    
    

    return count;
}


int main(){
    vector<int> arr={1,16,4,16,64,16};
    int r=4;
    cout<<findTripletsGP(arr,r)<<endl;
    
    
}