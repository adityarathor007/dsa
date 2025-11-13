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

    int getRandom() {
        int index=rand()%nums.size();
        return nums[index];
    }
