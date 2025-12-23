class Solution {
public:
    int upperBound(vector<vector<int>>& events, int index){
        int n=events.size();
        int l=index+1,r=events.size()-1,nxt_index=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(events[mid][0]>events[index][1]){
                nxt_index=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return nxt_index;
    }

    int recHelper(int i,int cnt,vector<vector<int>>&events,vector<vector<int>>&dp){
        int n=events.size();
        if(i==n or cnt==2) return 0;
        if(dp[i][cnt]!=-1) return dp[i][cnt];

        int exclude=recHelper(i+1,cnt,events,dp);
        int nxt_index=upperBound(events,i);
        int include=events[i][2]+recHelper(nxt_index,cnt+1,events,dp);


        return dp[i][cnt]=max(exclude,include);

    }
    int maxTwoEvents(vector<vector<int>>& events) {
        //M1: using dp+binary_search
        // sort(events.begin(),events.end());  //sorting by start time as for we are using upper bound to find the next start time for the current end time
        // int n=events.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return recHelper(0,0,events,dp);

        // M2: Using line sweep algorithm
        vector<pair<int,pair<bool,int>>>timePoints;
        for(auto event:events){
            int start=event[0],end=event[1],value=event[2];
            timePoints.push_back({start,{true,value}});
            timePoints.push_back({end+1,{false,value}});
        }

        sort(timePoints.begin(),timePoints.end());

        int maxSum=0,maxFinishedValue=0;
        for(int i=0;i<timePoints.size();i++){
            int curr=timePoints[i].first;
            int isStart=timePoints[i].second.first;
            int curr_value=timePoints[i].second.second;
            if(isStart){
                maxSum=max(maxSum,maxFinishedValue+curr_value);
            }
            else {
                maxFinishedValue=max(maxFinishedValue,curr_value);
            }
        }

        return maxSum;

    }
};
