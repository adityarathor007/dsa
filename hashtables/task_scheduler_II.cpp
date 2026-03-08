long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long>prev_day_mp;
        long long cday=1;
        for(int task:tasks){
            if(!prev_day_mp.count(task)){
                prev_day_mp[task]=cday;
                cday+=1;
            }
            else{
                long long prev_day=prev_day_mp[task];
                if(cday-prev_day-1<space){
                    cday=(long long) space+prev_day+1;
                }
                prev_day_mp[task]=cday;
                cday+=1;
            }
        }
        return cday-1; //because after alloting we move to the next day
    }
