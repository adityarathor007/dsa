    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {

        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());

        priority_queue<tuple<int, int, int>> maxHeap;

        set<pair<int,int>>visited;
        int n=a.size();
        int m=b.size();

        maxHeap.push(make_tuple(a[0]+b[0],0,0));
        visited.insert({0,0});

        vector<int>result;

        while(k-- && !maxHeap.empty()){
            auto top = maxHeap.top();
            int sum = get<0>(top);
            int i   = get<1>(top);
            int j   = get<2>(top);


            maxHeap.pop();

            result.push_back(sum);

            if(i+1<n && !visited.count({i+1,j})){
                maxHeap.push(make_tuple(a[i + 1] + b[j], i + 1, j));
                visited.insert({i+1,j});
            }
            if(j+1<m && !visited.count({i,j+1})){
                maxHeap.push(make_tuple(a[i] + b[j+1], i, j+1));
                visited.insert({i,j+1});
            }


        }

        return result;

    }
