class Solution {
    int MOD=1e9+7;
public:
    long long computePow(long long base,long long exp){
        if(exp==0) return 1;
        if(exp&1){
            return (base*computePow(base,exp-1))%MOD;
        }
        return computePow((base*base)%MOD,exp/2)%MOD;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long ans = computePow(5, evenCount)%MOD;
        ans = (ans * computePow(4, oddCount)%MOD) % MOD;

        return ans;
    }
};
