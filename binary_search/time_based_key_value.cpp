class TimeMap {
    unordered_map<string,vector<pair<int,string>>>mp;
public:
    TimeMap() {
        mp.clear();
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }

    string get(string key, int timestamp) {
        vector<pair<int,string>>&curr=mp[key];
        int n=curr.size();
        int start=0,end=n-1;
        if(n==0 or timestamp<curr[0].first) return "";
        int ans_index=-1;

        while(start<=end){
            int mid=(start+end)/2;
            if(curr[mid].first<=timestamp){
                ans_index=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return curr[ans_index].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */ 
