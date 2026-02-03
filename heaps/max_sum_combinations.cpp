vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here

        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        int n=a.size();

        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({a[i]+b[0],{i,0}});
        }

        vector<int>ans;
        int cnt=0;
        while(cnt<k){
            auto [csum,cp]=pq.top();
            auto [i,j]=cp;
            ans.push_back(csum);
            pq.pop();
            if(j<n-1) pq.push({a[i]+b[j+1],{i,j+1}});
            cnt+=1;
        }

        return ans;

    }
