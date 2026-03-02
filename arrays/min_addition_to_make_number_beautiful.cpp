int calc(long long num){
        int digit_sum=0;
        while(num){
            int digit=num%10;
            num/=10;
            digit_sum+=digit;
        }
        return digit_sum;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        long long x=0;
        int i=0;
        // taking each digit to zero starting from rightmost because the middle numbers between that will be increasing the sum only
        while(calc(n+x)>target){
            long long curr=pow(10,i);
            x=curr-(n%curr);
            i+=1;
        }
        return x;
    }
