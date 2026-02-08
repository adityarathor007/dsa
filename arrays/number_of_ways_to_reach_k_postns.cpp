long long inv(long long a) {
        if (a == 1) return 1;
        return (p - p / a) * inv(p % a) % p;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        if(abs(endPos-startPos)>k) return 0;
        if((endPos-startPos-k)%2) return 0;
        long long res=1L;
        for(int i=0;i<(endPos-startPos+k)/2;i++){
            res=(res*(k-i))%p;
            res=(res*inv(i+1))%p;
        }
        return res;
    }
