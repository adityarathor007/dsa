class Fancy {
    vector<long long>nums;
    long long ga=0;
    long long gm=1;
    long long MOD=1e9+7;
public:
    Fancy() {

    }

     long long modInverse(long long x) {
        long long res = 1, p = MOD - 2;
        while(p){
            if(p & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            p >>= 1;
        }
        return res;
    }

    void append(int val) {
        //rollback
       long long v=((val - ga + MOD) % MOD * modInverse(gm)) % MOD;
       nums.push_back(v);
    }

    void addAll(int inc) {
        ga+=inc;
    }

    void multAll(int m) {
        gm=(gm*m)%MOD;
        ga=(ga*m)%MOD; //adjusting the cumlative add value
    }

    int getIndex(int idx) {
        if(idx>=nums.size()) return -1;
        return (nums[idx] * gm % MOD + ga) % MOD;
    }
};
