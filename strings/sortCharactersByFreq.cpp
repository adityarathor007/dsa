class Solution {
public:
    struct CustomComparator {
    bool operator()(const pair<int, char>& a, const pair<int, char>& b) {

        return a.first < b.first;  //max num given more priority
    }
    };
    string frequencySort(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>,CustomComparator>pq;
        map<char,int>m;
        string ans;
        for(char x:s){
            m[x]++;
        }
        for(auto it=m.begin();it!=m.end();it++){
            pq.push({it->second,it->first});
        }

        while(!pq.empty()){
            auto p=pq.top();
            while(p.first!=0){
                ans+=p.second;
                p.first--;
            }
            pq.pop();

        }

        return ans;

    }

};