void merge(int s,int e,vector<int>&nums){
        int mid=(s+e)/2;
        int i=s,j=mid+1;
        int m=mid,n=e;
        vector<int>merged;
        // cout<<i<<" "<<nums[i]<<endl;
        // cout<<j<<" "<<nums[j]<<endl;
        while(i<=m and j<=n){
            int v1=nums[i];
            int v2=nums[j];
            if(v1<=v2){
                merged.push_back(v1);
                i+=1;
            }
            else{
                merged.push_back(v2);
                j+=1;
            }
        }

        while(i<=m){
            merged.push_back(nums[i]);
            i+=1;
        }

        while(j<=n){
            merged.push_back(nums[j]);
            j+=1;
        }

        int k=0;
        for(int i=s;i<=e;i++){
            nums[i]=merged[k];
            k+=1;
        }


    }


    void recSort(int s,int e,vector<int>&nums){
        if(s==e) return;
        int mid=s+(e-s)/2;
        recSort(s,mid,nums);
        recSort(mid+1,e,nums);
        merge(s,e,nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        recSort(0,n-1,nums);
        return nums;
    }
