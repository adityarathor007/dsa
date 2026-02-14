int countPrimes(int n) {
        if(n<=2) return 0;

        vector<int>isPrime(n,1);
        for(int i=2;i<sqrt(n);i++){
            if(isPrime[i]){
                for(int j=i*i;j<n;j+=i){
                    isPrime[j]=0;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]) cnt+=1;
        }

        return cnt;
    }
