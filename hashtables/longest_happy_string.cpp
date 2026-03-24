 string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});

        string ans="";
        while(!pq.empty()){
            auto [cnt1,ch1]=pq.top();
            pq.pop();
            int n=ans.size();
            if(n<2 or ans.back()!=ch1 or ans[n-2]!=ch1){
                ans+=ch1;
                if(cnt1>1) pq.push({cnt1-1,ch1});
            }
            else{ //collision happening
                if(!pq.empty()){
                    auto [cnt2,ch2]=pq.top();
                    pq.pop();
                    ans+=ch2;  //this character wont collide
                    pq.push({cnt1,ch1});
                    if(cnt2>1) pq.push({cnt2-1,ch2});
                }
            }
        }

        return ans;
    }
