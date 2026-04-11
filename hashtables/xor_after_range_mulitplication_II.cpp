long long power(long long base,long long exp){
        long long res=1;
        while(exp){
            if(exp&1) res=(res*base)%mod;
            base=(base*base)%mod;
            exp>>=1;
        }
        return res;
    }

    long long modInv(long long n){
        return power(n, mod - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int limit=sqrt(n);

        unordered_map<int,vector<vector<int>>>lightK;
        for(auto& query:queries){
            int l = query[0], r = query[1], k = query[2], v = query[3];
            if(k>=limit){
                for(int i=l;i<=r;i+=k) nums[i] = (1LL * nums[i] * v) % mod;
            }
            else{
                lightK[k].push_back(query);
            }
        }

        for(auto& [k,queries]:lightK){
            vector<long long>diff(n,1);
            // for all queries with the given k
            for(auto& q:queries){
                int l=q[0],r=q[1],v=q[3];

                // multiply starting position
                diff[l]=(diff[l]*v)%mod;
                int steps=(r-l)/k;
                int next=l+(steps+1)*k;
                if(next<n){
                    diff[next]=(diff[next]*modInv(v))%mod;
                }
            }

            // propagate the multipliers with a step size of k
            for(int i=0;i<n;i++){
                if(i>=k) diff[i] = (diff[i] * diff[i-k]) % mod;
                nums[i]=(1LL*nums[i]*diff[i])%mod;
            }
        }

         int ans = 0;
        for(auto& num : nums) ans ^= num;

        return ans;

    }
