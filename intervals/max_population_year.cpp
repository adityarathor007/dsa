class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,bool>>timePoints;
        for(vector<int> log:logs){
            int birth=log[0],death=log[1];
            timePoints.push_back({birth,true});
            timePoints.push_back({death,false});
        }
        sort(timePoints.begin(),timePoints.end());
        int maxPopulation=0,current_cnt=0,start_year=-1,n=timePoints.size();
        for(int i=0;i<n;i++){
            int year=timePoints[i].first;
            int isBirth=timePoints[i].second;
            // cout<<year<<" "<<isBirth<<endl;
            if(isBirth) current_cnt+=1;
            else current_cnt-=1;
            if(current_cnt>maxPopulation){
                maxPopulation=current_cnt;
                start_year=year;
            }
        }
        return start_year;

    }
};
