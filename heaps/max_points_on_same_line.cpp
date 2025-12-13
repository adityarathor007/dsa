double find_slope(vector<int>p1,vector<int>p2){
        if(p2[0]-p1[0]==0) return INT_MAX;
        return ((double)(p2[1]-p1[1]))/(p2[0]-p1[0]);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        unordered_map<double,int>slope_counts;
        for(int i=0;i<n;i++){
            int cmax_cnt=0;
            for(int j=i+1;j<n;j++){
                double cs=find_slope(points[i],points[j]);
                slope_counts[cs]+=1;
                cmax_cnt=max(cmax_cnt,slope_counts[cs]);
            }
            slope_counts.clear();
            ans=max(cmax_cnt+1,ans);
        }
        return ans;
    }
