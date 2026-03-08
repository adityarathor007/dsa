class RandomizedCollection {
    unordered_map<int,vector<int>>hashMap;
    vector<pair<int,int>>vec;
public:
    RandomizedCollection() {

    }

    bool insert(int val) {
        bool check=true;
        if(hashMap.count(val)) check=false;
        int n=vec.size();
        hashMap[val].push_back(n);
        vec.push_back({val,hashMap[val].size()-1});
        return check;
    }

    bool remove(int val) {
        if(!hashMap.count(val)) return false;

        // cout<<"starting remove for val: "<<val<<endl;

        int target_i=hashMap[val].back();
        int n=vec.size();
        int lastInd=n-1;
        auto lastPair=vec[n-1];

        // cout<<target_i<<" "<<lastInd<<endl;

        swap(vec[target_i],vec[lastInd]);
        hashMap[val].pop_back();

        if(hashMap[val].size()==0) hashMap.erase(val);
        vec.pop_back();

        if(target_i!=lastInd){
            // cout<<lastPair.first<<" "<<lastPair.second<<endl;
            hashMap[lastPair.first][lastPair.second]=target_i;
        }


        return true;
    }

    int getRandom() {
     int n=vec.size();
     int rand_ind=rand()%n;
     return vec[rand_ind].first;
    }
};


