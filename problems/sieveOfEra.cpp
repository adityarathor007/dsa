//find all prime numbers till that number
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n){
    vector<bool> isPrime (n+1,true);
    for(int i=2;i<n+1;i++){
        if(isPrime[i]){
            for(int j=i*i;j<n+1;j+=i){  // as will be marked false by other primes that occured before
                isPrime[j]=false;  //avoid checking multiples of prime
            }
            cout<<"the prime number is"<<i<<endl;
        }
        
    }
}




int main(){
    int n;
    cin>>n;
    sieve(n);
}