unordered_map<int,int>hashMap;
    vector<int>nums;

    RandomizedSet() {

    }

    bool insert(int val) {
        if(hashMap.count(val)) return false;
        int n=nums.size();
        nums.push_back(val);
        hashMap[val]=n;
        return true;
    }

    bool remove(int val) {
        if (!hashMap.count(val)) return false;

        int loc = hashMap[val];
        int lastVal = nums.back();

        nums[loc] = lastVal;
        hashMap[lastVal] = loc;

        nums.pop_back();
        hashMap.erase(val);

        return true;

    }

    //alternate method for removing
    // bool remove(int val) {
    //     if(!hashMap.count(val)) return false;

    //     int target_i=hashMap[val];
    //     int lastIndex=vec.size()-1;
    //     int lastNum=vec[lastIndex];

    //     swap(vec[lastIndex],vec[target_i]);

    //     vec.pop_back();
    //     hashMap.erase(val);

    //     //updating the hashmap
    //     if(lastIndex!=target_i) hashMap[lastNum]=target_i;

    //     return true;
    // }

    int getRandom() {
        int index=rand()%nums.size();
        return nums[index];
    }
