class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>deadendSet;
        for(string deadend:deadends){
            deadendSet.insert(deadend);
        }
        if(deadendSet.count("0000")) return -1;
        queue<pair<int,string>>q;
        q.push({0,"0000"});
        unordered_set<string>visited;
        visited.insert("0000");
        int steps=0;

        while(!q.empty()){
            auto [steps,curr]=q.front();
            if(curr==target) return steps;
            q.pop();
            for(int i=0;i<4;i++){
                char ch=curr[i];
                int digit=ch-'0';
                curr[i]=((digit+1)%10)+'0';
                if(!visited.count(curr) and !deadendSet.count(curr)){
                    q.push({steps+1,curr});
                    visited.insert(curr);
                }
                int prev=digit-1;
                if(prev==-1) prev=9;
                curr[i]=prev+'0';
                if(!visited.count(curr) and !deadendSet.count(curr)){
                    q.push({steps+1,curr});
                    visited.insert(curr);  //markvisited as soon as push to remove duplicate being pushed as if we update after it pops there is a chance that many duplicates are pushed in the queue
                }
                curr[i]=ch;
            }

        }
        return -1;
    }
};
