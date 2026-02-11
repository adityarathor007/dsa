vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>>htolens(101);

        for(auto rectangle:rectangles){
            htolens[rectangle[1]].push_back(rectangle[0]);
        }

        for(int i=1;i<=100;i++){
            sort(htolens[i].begin(),htolens[i].end());
        }

        vector<int>ans;
        for(auto point:points){
            int sum=0;
            for(int i=point[1];i<=100;i++){
                int ind=lower_bound(htolens[i].begin(),htolens[i].end(),point[0])-htolens[i].begin();
                int n=htolens[i].size();
                sum+=n-ind;
            }
            ans.push_back(sum);
        }

        return ans;
    }
