long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        vector<vector<int>>points;
        int n=bottomLeft.size();
        for(int i=0;i<n;i++){
            points.push_back({bottomLeft[i][0],bottomLeft[i][1],topRight[i][0],topRight[i][1]});
        }
        sort(points.begin(),points.end());
        long long max_area=0;
        for(int i=0;i<n;i++){
            long long curr_max=0;
            for(int j=i+1;j<n;j++){
                int sx=max(points[i][0],points[j][0]);
                int sy=max(points[i][1],points[j][1]);
                int ex=min(points[i][2],points[j][2]);
                int ey=min(points[i][3],points[j][3]);
                int side=min(ex-sx,ey-sy);
                // cout<<side<<" "<<i<<" "<<j<<endl;
                if(side<0) continue;
                curr_max=max(curr_max,(long long)side*side);
            }
            // cout<<curr_max<<endl;
            max_area=max(curr_max,max_area);
        }
        return max_area;
    }
