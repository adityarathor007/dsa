bool canRepair(long long maxTime,vector<int>& ranks,int& cars){
        int cnt=0;
        for(int rank:ranks){
            long long div=maxTime/rank;
            long long cc=sqrt(div);
            cnt+=cc;
            if(cnt>=cars) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long ans=-1;
        long long l=1,r=1000;
        for(int rank:ranks){
            r=min(r,(long long) rank);
        }
        r*=((long long) cars*cars);
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(canRepair(mid,ranks,cars)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;

    }
