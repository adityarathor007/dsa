vector<string>ans;
        queue<pair<string,pair<int,int>>>q;
        q.push({"(",{1,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            string cs=p.first;
            int curr_open=p.second.first;
            int curr_close=p.second.second;
            if((curr_close+curr_open)/2==n){
                ans.push_back(cs);
                continue;
            }
            if(curr_open<n) q.push({cs+'(',{curr_open+1,curr_close}});
            if(curr_open>curr_close) q.push({cs+')',{curr_open,curr_close+1}});
        }
        return ans;
