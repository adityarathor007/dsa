 long long numberOfWeeks(vector<int>& milestones) {
        unordered_map<int,int>mp;
        int max_milestone=0;
        long long max_time=0;
        for(int milestone:milestones){
            mp[milestone]+=1;
            max_milestone=max(max_milestone,milestone);
            max_time+=milestone;
        }
        int max_milestone_cnt=mp[max_milestone];

        long long o1=0;
        for(auto [milestone,cnt]:mp){
            if(milestone==max_milestone) continue;
            o1+=(milestone*cnt);
        }
        if(max_milestone_cnt==1) return min(max_time,2*o1+1);
        return max_time;

    }
