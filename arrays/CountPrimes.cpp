   #include<iostream>
   #include<vector>
   using namespace std;
//    count the number of primes less than a particular number n
   
   bool isPrime(int num){
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                return false;
            }
        }

        return true;
    }

    int countPrimes(int n) {
     int c=0;
    // //  O(N*sqrtN) Brute force
    //  for(int i=2;i<n;i++){
    //     if(isPrime(i)) c+=1;
    //  }


    //  O(N) using sieve of eratosthenes(O(N));
    vector<int>arr(n,1);
    for(int i=2;i<sqrt(n);i++){  //rather than kepping n it should be sqrt of N as we are going and making everything 0 till N 
    // and starting from k=i so after sqrt(N) the check are unescessary
        if(arr[i]==1){
            c+=1;
            int num=i;
            int k=i;  //not starting from 2 as before 2 and other prime factors marked it
            // making multiples of prime not a possible candidate of prime nums
            while(num<n){
                arr[num]=0;
                num=i*k;
                k+=1;
            
            }

        }
        // now seeing which nums left 1 
        for(int x:arr){
            if(x==1) print(x);
        }
        
    }
     return c;
    }