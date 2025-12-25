bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<pair<int,pair<int,int>>>trip_pts;

        for(auto trip:trips){
            int passengers=trip[0],start=trip[1],end=trip[2];
            trip_pts.push_back({start,{true,passengers}});
            trip_pts.push_back({end,{false,passengers}});
        }

        int curr_cap=0;
        int n=trip_pts.size();
        sort(trip_pts.begin(),trip_pts.end());

        for(int i=0;i<n;i++){
            int isStart=trip_pts[i].second.first;
            int passengers=trip_pts[i].second.second;
            if(isStart){
                curr_cap+=passengers;
                if(curr_cap>capacity) return false;
            }
            else  curr_cap-=passengers;
        }
        return true;



    }
