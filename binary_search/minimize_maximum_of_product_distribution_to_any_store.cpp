bool canAllocate(int max_cnt,int n,vector<int>&quantities){
        int store_cnt=0;
        for(int quantity:quantities){
            store_cnt+=(quantity/max_cnt);
            if(quantity%max_cnt) store_cnt+=1;
            // cout<<store_cnt<<endl;
            if(store_cnt>n) return false;
        }
        // cout<<max_cnt<<" "<<store_cnt<<endl;
        return store_cnt<=n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1,r=0;
        for(int quantity:quantities){
            if(r>INT_MAX-quantity){
                r=INT_MAX;
                break;
            }
            else r+=quantity;
        }
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canAllocate(mid,n,quantities)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;

    }
