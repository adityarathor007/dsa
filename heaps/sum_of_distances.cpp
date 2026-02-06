vector<long long> distance(vector<int>& nums) {
        unordered_map<int,long long>cnt_l,sum_l,cnt_r,sum_r;
        int n=nums.size();
        vector<long long>ans(n,0);

        for(int i=0;i<n;i++){
            ans[i] = cnt_l[nums[i]] * i - sum_l[nums[i]];
            sum_l[nums[i]] += i;
            ++cnt_l[nums[i]];
        }

        for(int i=n-1;i>=0;i--){
            ans[i] += sum_r[nums[i]] - cnt_r[nums[i]] * i;
            sum_r[nums[i]] += i;
            ++cnt_r[nums[i]];
        }


        return ans;
    }
