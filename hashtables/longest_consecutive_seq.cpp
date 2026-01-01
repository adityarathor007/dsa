 int longestConsecutive(vector<int>& nums) {

        // TC: O(n) as it visits each num once 

        int n=nums.size();
        if(n==0) return 0;
        int long_cnt=1;
        unordered_set<int>st;

        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        for(int num:st){
            if(st.count(num+1) and !st.count(num-1)){
                int cnt=0;
                int cn=num;
                while(st.count(cn)){
                    cnt+=1;
                    cn+=1;
                }
                long_cnt=max(long_cnt,cnt);
            }

        }

        return long_cnt;
    }
