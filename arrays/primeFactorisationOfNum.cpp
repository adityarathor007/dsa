   #include<iostream>
   #include<math.h>
   #include<algorithm>
   #include<vector>
   using namespace std;

  vector<int> findPrimeFactors(int N) {
        vector<int>ans;
        vector<int>sieve(N+1);
        for(int i=2;i<=N;i++){
            sieve[i]=i;
        }
        
        
        for(int i=2;i<=sqrt(N);i++){
            if(N%i==0){
                for(int j=i*i;j<=N;j+=i){
                    if(sieve[j]==j){
                      
                        sieve[j]=i;  //updating the sieve with the prime factor
                    }
                    
                }
                
            }
        }
        
    
        
        while(N!=1){
            ans.push_back(sieve[N]);
            N=N/sieve[N];
        }
        
        
        
        return ans;

  }

int main(){
    findPrimeFactors(30);
}