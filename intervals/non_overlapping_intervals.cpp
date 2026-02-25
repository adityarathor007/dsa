int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // M2: Removing min intervals to make non overlapping means keep the maximum number of non overlapping intervals
        // So if sorted by the end time then we keep maximum room for the further intervals
        sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });

        int min_remove=0,curr_end=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<curr_end) min_remove+=1;
            else curr_end=intervals[i][1];
        }
        return min_remove;

        // M2: Sorting by start time
        sort(intervals.begin(),intervals.end());

        int prevStart=INT_MIN,prevEnd=INT_MIN;
        int cnt=0;
        for(auto interval:intervals){
            int cs=interval[0],ce=interval[1];
            if(cs>=prevEnd){
                prevStart=cs;
                prevEnd=ce;
            }
            else{
                if(cs!=prevStart){  //removing the interval which has the larger end time so that we have more room for the other intervals
                    if(prevEnd>=ce){
                        prevStart=cs;
                        prevEnd=ce;
                    }
                }
                cnt+=1;
            }

        }

        return cnt;


}
