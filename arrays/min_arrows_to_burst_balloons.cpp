  static bool customSort(const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    }
    //similar to solving removing overlapping interval
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),customSort);
        int cEnd=-1;
        int cnt=0;

        for(vector<int> point:points){
            if(cEnd!=-1 and point[0]<=cEnd){
                cnt+=1;
            }
            else cEnd=point[1];
        }
        return points.size()-cnt;
    }
