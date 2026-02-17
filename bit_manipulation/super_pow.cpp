 int mod=1337;

public:
    int modPow(int base,int exp){
        int res=1;
        base%=mod;

        while(exp>0){
            if(exp&1) res=(res*base)%mod;
            base=(base*base)%mod;
            exp>>=1; //dividing by 2
        }

        return res;
    }

    int superPow(int a, vector<int>& b) {
        int res=1;
        for(int d:b){
            res=modPow(res,10);
            res=(res*modPow(a,d))%mod;
        }

        return res;
    }
};
