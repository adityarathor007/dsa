class Solution {
public:
    int MOD=1e9+7;

    int cntBitsLen(int num){
        int last_set=-1;
        int i=0;
        while(num){
            int bit=num&1;
            if(bit) last_set=i;
            num=num>>1;
            i+=1;
        }
        return last_set+1;
    }

    int concatenatedBinary(int n) {
        long long ans=0;
        for(int i=1;i<=n;i++){
            int bit_len=cntBitsLen(i);
            ans = ((ans << bit_len) % MOD + i) % MOD;
        }

        return ans;
    }
};
