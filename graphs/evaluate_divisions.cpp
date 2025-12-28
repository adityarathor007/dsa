class Solution {
public:
    double findPrd(string src,string target,unordered_map<string,vector<pair<string,double>>>&adjList){
        queue<pair<double,string>>q;
        unordered_set<string>visited;
        q.push({1,src});

        while(!q.empty()){
            auto [cwt,cn]=q.front();
            visited.insert(cn);
            q.pop();
            if(cn==target) return cwt;
            for(auto [neighbour,wt]:adjList[cn]){
                if( !visited.count(neighbour)) q.push({cwt*wt,neighbour});
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adjList;


        for(int i=0;i<equations.size();i++){
            string n1=equations[i][0],n2=equations[i][1];
            double wt=values[i];
            adjList[n1].push_back({n2,1/wt});
            adjList[n2].push_back({n1,wt});
        }

        vector<double>ans;
        for(auto query:queries){
            string n1=query[0],n2=query[1];
            if(adjList.find(n1)==adjList.end() or adjList.find(n2)==adjList.end()) ans.push_back(-1);
            else if(n1==n2) ans.push_back(1);
            else ans.push_back(findPrd(n2,n1,adjList));
        }

        return ans;
    }
