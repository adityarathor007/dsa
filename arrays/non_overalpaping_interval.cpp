 bool customSort(const pair<int,int>&a, const pair<int,int>&b){
        return a.second<b.second;  //sorting by end time rather than start time to avoid bringing large interval in the ans as that would cause a lot of intervals to be removed
    }

//it is about erasing the interval rather than merging so if collision happens then we remove the colliding interval with respect to the current interval
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>>meetingInfo;
        for(auto interval :intervals){
            meetingInfo.push_back({interval[0],interval[1]});
        }

        sort(meetingInfo.begin(),meetingInfo.end(),customSort);

        int cStart, cEnd;

        int cnt=0;
        for(int i=0;i<meetingInfo.size();i++){
            // cout<<meetingInfo[i].first<<" "<<meetingInfo[i].second<<endl;
            if(i!=0 and meetingInfo[i].first<cEnd){
                cnt+=1;
            }
            else{
                cStart=meetingInfo[i].first;
                cEnd=meetingInfo[i].second;
            }
        }

        return cnt;

    }
