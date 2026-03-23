 int countPartitionWithMaxCap(int cap,vector<int>&nums){
        int partitions=1;
        int currentSum=0;
        for(int num:nums){
            if(currentSum+num<=cap){
                currentSum+=num;
            }
            else{
                partitions+=1;
                currentSum=num;
            }
        }
        return partitions;
    }


    int splitArray(vector<int>& nums, int k) {
        int l=0,r=0;  //lower limit is max of array because we are looking for parititions with max sum value
        for(int num:nums){
            l=max(l,num);
            r+=num;
        }
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(countPartitionWithMaxCap(mid,nums)<=k){ //less than k also accepted as they can be brought to k
                ans=mid;
                r=mid-1; //moving towards the actual sum that exist
            }
            else l=mid+1; //able to create more partition so increasing the cap to decrease the number of partition
        }

        return ans;
    }
