long long countSubarrays(vector<int>& nums, long long k) {
        deque<int>max_dq;
        deque<int>min_dq;
        int n=nums.size();

        int i=0,j=0;
        long long ans=0;
        while(j<n){
            // as before smaller elements than current in the current window can be ignored
            while(!max_dq.empty() and nums[max_dq.back()]<=nums[j]){
                max_dq.pop_back();
            }
            max_dq.push_back(j);
            while(!min_dq.empty() and nums[min_dq.back()]>=nums[j]){
                min_dq.pop_back();
            }
            min_dq.push_back(j);

            // move to the right when the value is > k
            while(i<=j and 1LL*((long long) nums[max_dq.front()]-nums[min_dq.front()])*(j-i+1)>k){
                if (!max_dq.empty() && max_dq.front() == i)
                    max_dq.pop_front();
                if (!min_dq.empty() && min_dq.front() == i)
                    min_dq.pop_front();
                i++;
            }

            ans+=(j-i+1);
            j+=1;
        }

        return ans;

    }
