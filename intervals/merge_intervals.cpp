 vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // M1 merging if in the answer the time is greater then the current start time
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


        // M2: Line sweep algorithm
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,bool>>timeline;
        int n=intervals.size();

        for(auto interval:intervals){
            timeline.push_back({interval[0],true});
            timeline.push_back({interval[1]+1,false});
        }

        sort(timeline.begin(),timeline.end());

        int startCnt=0;
        int stime=-1;
        vector<vector<int>>ans;

        for(auto [time,isStart]:timeline){
            if(isStart){
                if(stime==-1) stime=time;
                startCnt+=1;
            }
            else{
                startCnt-=1;
                if(!startCnt){
                    ans.push_back({stime,time-1});
                    stime=-1;
                }
            }
        }

        return ans;
    } 
    }
