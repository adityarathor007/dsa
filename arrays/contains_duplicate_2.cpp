bool containsNearbyDuplicate(vector<int>& nums, int k) {

        // M1: sorting the list with indicies
        // vector<pair<int,int>>nums_w_i;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     nums_w_i.push_back({nums[i],i});
        // }

        // sort(nums_w_i.begin(),nums_w_i.end());
        // for(int i=0;i<n-1;i++){
        //     int n1=nums_w_i[i].first;
        //     int i1=nums_w_i[i].second;
        //     int n2=nums_w_i[i+1].first;
        //     int i2=nums_w_i[i+1].second;

        //     if(n1==n2 and i2-i1<=k) return true;

        // }

        // return false;


        //use a set with sliding window k;
        unordered_set<int>hashSet;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(hashSet.find(nums[i])!=hashSet.end()) return true;
            hashSet.insert(nums[i]);
            if(hashSet.size()>k){
                hashSet.erase(nums[i-k]);
            }
        }

        return false;

    }
