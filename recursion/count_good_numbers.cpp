class Solution {
    int MOD=1e9+7;
public:
    long long computePow(long long base,long long p){
        if(p==0) return 1;

        if(p&1){
            return (base*computePow(base,p-1))%MOD;
        }
        long long new_base=(base*base) % MOD;
        return computePow(new_base,p/2);
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long ans = computePow(5, evenCount)%MOD;
        ans = (ans * computePow(4, oddCount)%MOD) % MOD;

        return ans;
    }
};
