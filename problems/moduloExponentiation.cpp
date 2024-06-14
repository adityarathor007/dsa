#include <iostream>
#include <cmath>
using namespace std;
long long int ans=1;
#define value 10000000 


long long int powerModulo(int a, int b){
    //Write your code here. Do not modify the function or parameters. Use helper functions if needed.
    //base case
    if(b==0){
        return ans;
    }
    
    
    ans=ans*a;
    b--;
    return powerModulo(a, b);
    
    
    
}


int main(){
    int a;
    int b;
    cin>>a;
    cin>>b;
    cout<<powerModulo(a, b)<<endl;
    return 0;
    
}