 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(const vector<int> interval:intervals){
            int cst=interval[0];
            int cet=interval[1];
            if(ans.empty() or ans.back()[1]<cst){
                ans.push_back({cst,cet});
            }
            else{
                ans.back()[1]=max(cet,ans.back()[1]);
            }

        }

        return ans;
    }