class Solution {
public:
     double find_weight(const string& start,
                       const string& end,
                       const unordered_map<string, vector<pair<string, double>>>& adj) {
        if (start == end) return 1.0;

        queue<pair<string, double>> q;
        unordered_set<string> visited;

        q.push({start, 1.0});
        visited.insert(start);

        while (!q.empty()) {
            auto [node, curVal] = q.front();
            q.pop();

            if (node == end) return curVal;

            auto it = adj.find(node);
            if (it == adj.end()) continue;

            for (const auto& [nbr, wt] : it->second) {
                if (!visited.count(nbr)) {
                    visited.insert(nbr);
                    q.push({nbr, curVal * wt});
                }
            }
        }

        return -1.0; // no path
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj_list;
        int edges=equations.size();

        for(int i=0;i<edges;i++){
            string n1=equations[i][0];
            string n2=equations[i][1];
            double wt=values[i];
            adj_list[n1].push_back({n2,wt});
            double rev_wt=1/wt;
            adj_list[n2].push_back({n1,rev_wt});
        }

        vector<double>ans;
        for(auto query:queries){
            string n1=query[0];
            string n2=query[1];
            if(adj_list.find(n1)==adj_list.end() or adj_list.find(n2)==adj_list.end()){
                ans.push_back(-1.0);
                continue;
            }
            ans.push_back(find_weight(n1,n2,adj_list));
        }

        return ans;

    }
};
