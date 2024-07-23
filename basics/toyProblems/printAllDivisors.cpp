#include<iostream>
#include<math.h>
#include <cmath>
#include <algorithm> 
#include<vector>
using namespace std;

// brute force is going from [1,N] and checking if divides or not 
// optimised method is that go till sqrt(N) as after this you are just checking the reverse like for 6 it is 2*3 and 3*2


int main(){
     int n;
    cin>>n;
   vector<int>v;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            v.push_back(i);
            if((n/i)!=i){
                 v.push_back(n/i);
            }
           
        }
    }
    sort(v.begin(),v.end());
    for(auto x:v){
        cout<<x<<",";
    }
}