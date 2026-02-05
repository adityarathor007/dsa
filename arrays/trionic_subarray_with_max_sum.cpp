long long maxSumTrionic(vector<int>& nums) {
        long long maxSum=LLONG_MIN;
        int n=nums.size();
        long long csum=0;
        bool isStart=false;
        int r=0,p=-1,q=-1;

        while(r<n-1){
            if(!isStart){
                if(nums[r]<nums[r+1]){
                    isStart=true;
                    csum+=nums[r];
                }
            }
            else{
                if(p==-1){
                    if(nums[r]==nums[r+1]){
                        csum=0;
                        isStart=false;
                    }
                    else{
                        if(nums[r]>nums[r+1]){
                            p=r;
                            csum+=nums[r];
                        }
                        else{
                            // cout<<nums[r]<<endl;
                            csum=max(csum+nums[r],(long long) nums[r]);
                        }
                    }

                }
                else if(q==-1){
                    if(nums[r]==nums[r+1]){
                        csum=0;
                        isStart=false;
                        p=-1;
                    }
                    else{
                        if(nums[r]<nums[r+1]){
                            q=r;
                            csum+=nums[r];
                            csum+=nums[r+1]; //because the next element has be to take even if it decreases the csum as it greater then previous element
                        }
                        else csum+=nums[r];

                    }
                }
                else{
                    maxSum=max(maxSum,csum);
                    if(nums[r]==nums[r+1]){
                        csum=0;
                        isStart=false;
                        p=-1;
                        q=-1;
                    }
                    else if(nums[r]<nums[r+1]){
                        csum+=nums[r+1];
                    }
                    else{
                        r=q-1;
                        isStart=false; //starting again
                        csum=0;
                        p=-1;
                        q=-1;
                    }
                }
            }
            // cout<<r<<" "<<isStart<<" "<<p<<" "<<q<<" "<<csum<<endl;
            r+=1;
        }
        if(p!=-1 and q!=-1){
            maxSum=max(maxSum,csum);
        }

        return maxSum;
    }
