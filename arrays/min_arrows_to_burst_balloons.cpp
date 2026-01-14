//similar to solving removing overlapping interval
int findMinArrowShots(vector<vector<int>>& points) {
    // we need to remove max number of intervals so that we require minimum numbber of arrows so we sort by starting time as we want to remove
    sort(points.begin(),points.end());
    int min_arrows=1;
    int curr_end=points[0][1];

    for(int i=1;i<points.size();i++){
        if(points[i][0]>curr_end){
            curr_end=points[i][1];
            min_arrows+=1;
        }
        else curr_end=min(curr_end,points[i][1]);
    }
    return min_arrows;
}
