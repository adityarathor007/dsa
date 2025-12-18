int n=nums.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            int start_i=i;
            while(i+1<n and nums[i]==nums[i+1]-1) i+=1;
            if(i==start_i) ans.push_back(to_string(nums[i]));
            else{
                string temp=to_string(nums[start_i])+"->";
                temp+=to_string(nums[i]);
                ans.push_back(temp);
            }
        }

        return ans;
