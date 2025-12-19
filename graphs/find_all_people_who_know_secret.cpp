class Solution {
    vector<int> parent, rank;
public:
    int findParent(int n){
        if(parent[n]==n) return n;
        return parent[n]=findParent(parent[n]);
    }

    void unionFn(int u,int v){
        int upu=findParent(u);
        int upv=findParent(v);
        if(upu==upv) return ;

        if(rank[upu]<rank[upv]) swap(upu,upv);
        parent[upv]=upu;
        if(rank[upu]==rank[upv]) rank[upu]++;

    }


    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        // using dijkstra
        // unordered_map<int,vector<pair<int,int>>>adjList;
        // for(auto edge: meetings){
        //     adjList[edge[0]].push_back({edge[1],edge[2]});
        //     adjList[edge[1]].push_back({edge[0],edge[2]});
        // }

        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        // vector<int> earliest(n, INT_MAX);

        // pq.push({0,0});
        // pq.push({0,firstPerson});
        // earliest[0]=0;
        // earliest[firstPerson]=0;

        // while(!pq.empty()){
        //     auto [time,person]=pq.top();
        //     pq.pop();

        //     if(time>earliest[person]) continue;

        //     for(auto& [next,meetTime]:adjList[person]){
        //         if(meetTime>=time and meetTime<earliest[next]){
        //             earliest[next]=meetTime;
        //             pq.push({meetTime,next});
        //         }
        //     }

        // }

        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //     if(earliest[i]!=INT_MAX) ans.push_back(i);
        // }
        // return ans;


        //using union find
        vector<bool>knows(n,false);
        parent.resize(n);
         for (int i = 0; i < n; i++) parent[i] = i;
        rank.assign(n, 0);

        sort(meetings.begin(),meetings.end(),[](auto& a, auto& b){ return a[2]<b[2];});
        knows[0]=true;
        knows[firstPerson]=true;
        int m=meetings.size();
        int i=0;

        while(i<m){
            int current_time=meetings[i][2];
            vector<int>people;


            while(i<m and meetings[i][2]==current_time){
                unionFn(meetings[i][0],meetings[i][1]);
                people.push_back(meetings[i][0]);
                people.push_back(meetings[i][1]);
                i++;
            }

            unordered_set<int>goodRoots;
            for(int p:people){
                if(knows[p]) goodRoots.insert(findParent(p));
            }

            for(int p:people){
                if(goodRoots.count(findParent(p))) knows[p]=true;
            }

            for(int p:people){
                parent[p]=p;
                rank[p]=0;
            }
            cout<<i<<endl;
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(knows[i]) ans.push_back(i);
        }
        return ans;

    }
};
