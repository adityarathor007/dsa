 long long minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();
        int m=k-1;

        multiset<int>small;
        multiset<int>large;
        long long csum=0;

        // Initialize the first window [1, 1 + dist]
        for(int i=1;i<=dist+1;i++){
            small.insert(nums[i]);
            csum+=nums[i];
        }

        while(small.size()>m){
            int val = *small.rbegin();
            small.erase(prev(small.end()));
            csum-=val;
            large.insert(val);
        }

        long long ans=csum;
        // cout<<csum<<endl;

        for(int i=2;i + dist < n;i++){

            // prev element of the sliding window
            int out=nums[i-1];
            // cout<<out<<endl;
            if (small.find(out) != small.end()) {
                csum -= out;
                small.erase(small.find(out));
            } else {
                large.erase(large.find(out));
            }


            int in=nums[i+dist];
            small.insert(in);
            csum+=in;
            // cout<<in<<endl;


            while(small.size()<m and !large.empty()){
                int val=*large.begin();
                large.erase(large.begin());
                csum+=val;
                small.insert(val);
            }
            while(small.size()>m){
                int val=*small.rbegin();
                cout<<val<<endl;
                small.erase(prev(small.end()));
                csum-=val;
                large.insert(val);
            }

            // the new element that is added may be larger than the elements which may have been ignored before
            while(!large.empty() and *large.begin()<*small.rbegin()){
                int lv=*large.begin();
                large.erase(large.begin());
                int sv=*small.rbegin();
                small.erase(prev(small.end()));
                csum+=(lv-sv);
                small.insert(lv);
                large.insert(sv);
            }

            // cout<<small.size()<<endl;
            ans=min(ans,csum);
            // cout<<csum<<endl;

        }


        return ans+nums[0];
    }
