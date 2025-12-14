 int trailingZeroes(int n) {
        // count the times powers of 5 occured till n
        long long den=5;
        int zeros=0;
        while(den<=n){
            zeros+=(n/den);
            den*=5;
        }

        return zeros;
    }
