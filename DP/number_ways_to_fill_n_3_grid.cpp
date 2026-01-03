class Solution {
    int MOD=1e9+7;
public:
    int numOfWays(int n) {
        long long same=6;
        long long diff=6;
        for(int i=2;i<=n;i++){
            long long next_same=(3*same+2*diff)%MOD;
            long long next_diff=(2*same+2*diff)%MOD;
            same=next_same;
            diff=next_diff;
        }
        return (same+diff)%MOD;
    }
};
