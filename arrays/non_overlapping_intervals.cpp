int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // end faster then you have to remove less intervals
        // than giving priority based on start_time as then there will be a lot of interval in between which are small
        sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });

        int min_remove=0,curr_end=intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<curr_end) min_remove+=1;
            else curr_end=intervals[i][1];
        }
        return min_remove;


}
