class Solution {
    unordered_map<string,vector<string>>adjList;
    vector<string>ans;
public:
    void dfs(string from){

        while(!adjList[from].empty()){
            string dest=adjList[from].back();
            adjList[from].pop_back();
            dfs(dest);
        }

        ans.push_back(from);
        return ;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        adjList.clear();
        ans.clear();

        for(auto ticket:tickets){
            adjList[ticket[0]].push_back(ticket[1]);
        }

        for (auto& [_, destinations] : adjList) {
            sort(destinations.rbegin(), destinations.rend());
        }

        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;


    }
};
