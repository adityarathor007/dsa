 bool canComplete(long long time,int mountainHeight,vector<int>& workerTimes){
        int n=workerTimes.size();
        for(int workerTime:workerTimes){
            int cnt=1;
            long long ct=workerTime*cnt;
            while(ct<=time){
                mountainHeight-=1;
                cnt+=1;
                ct+=(long long)workerTime*cnt;
            }
            if(mountainHeight<=0) return true;
        }
        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l=1;
        int min_time=INT_MAX;
        for(int workerTime:workerTimes){
            min_time=min(min_time,workerTime);
        }
        int temp=mountainHeight,cnt=1;
        long long r=0;
        while(temp){
            temp-=1;
            r+=(long long)min_time*cnt;
            cnt+=1;
        }
        long long ans=-1;
        while(l<=r){
            long long mid=(l+r)/2;
            if(canComplete(mid,mountainHeight,workerTimes)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
