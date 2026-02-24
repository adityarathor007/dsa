vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int>ans;
        sort(sums.begin(),sums.end());

        while(sums.size()>1){
            int n=sums.size();
            map<int,int>excluding,including; // For subset sums that do NOT contain num and which contains num
            int diff=sums[n-1]-sums[n-2];
            unordered_map<int,int>freq;

            for(int sum:sums) freq[sum]+=1;

            for(int sum:sums){
                if(freq[sum]>0){
                    int inc_sum=sum+diff;
                    int exc_sum=sum;
                    freq[inc_sum]-=1;
                    freq[exc_sum]-=1;
                    excluding[exc_sum]+=1;
                    including[inc_sum]+=1;
                }
            }
            vector<int>nsums;
            if(excluding.count(0)){
                for(auto [key,cnt]:excluding){
                    while(cnt>0){
                        nsums.push_back(key);
                        cnt-=1;
                    }
                }
                ans.push_back(diff);
            }
            else{
               for(auto [key,cnt]:including){
                    while(cnt>0){
                        nsums.push_back(key);
                        cnt-=1;
                    }
                }
                ans.push_back(-1*diff);
            }
            sums=nsums;
        }

        return ans;
    }
