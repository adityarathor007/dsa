
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> setOfVectors;
        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++){
            //fixing one number so the problem boils down to two sum problem
            int target=-nums[i];
            int k=i+1,l=n-1;
            while(k<l){
                int csum=nums[k]+nums[l];
                if(csum==target){
                    setOfVectors.insert({-target,nums[k],nums[l]});
                    k+=1;l-=1;
                }
                else if(csum<target) k+=1;
                else if(csum>target) l-=1;
            }

        }

        vector<vector<int>>ans;
        for (auto& vec : setOfVectors) {
            ans.push_back(vec);
        }
        return ans;
    }
