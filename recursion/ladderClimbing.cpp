#include <climits>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int noOfWays(int n){ // f(n) represents the number of ways of reaching the level n and f(n)=f(n-1)+f(n-2)+f(n-3)
    if(n<0){
        return 0;
    }
    else if(n==0){
        return 1;
    }
    
    //recursive cases
    
        return noOfWays(n-1)+noOfWays(n-2)+noOfWays(n-3);  
}

// the complexity is O(3^n)
//      N 
// N-1 N-2 N-3
// similarly down as each has 3 options 


int main(){
    int n;
    cin>>n;
    cout<<noOfWays(n)<<endl;
    
}
