// chaining method
    vector<vector<pair<int,int>>> table;
    int size=1000;
public:
    MyHashMap(){
        table.resize(size);
    }

    int hash(int key){
        return key%size;
    }

    void put(int key, int value) {
        int idx=hash(key);
        for(auto &[k,v]:table[idx]){
            if(k==key){
                v=value;
                return ;
            }
        }
        table[idx].push_back({key,value});

    }

    int get(int key) {
        int idx=hash(key);
        for(auto [k,v]:table[idx]){
            if(k==key) return v;
        }
        return -1;
    }

    void remove(int key) {
        int idx=hash(key);
        auto &bucket=table[idx];
        for(int i=0;i<bucket.size();i++){
            if(bucket[i].first==key){
                bucket.erase(bucket.begin()+i);
                return ;
            }
        }
    }
