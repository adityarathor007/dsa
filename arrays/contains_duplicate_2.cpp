bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int>window_unique;
        int n=nums.size();
        int left=0;
        for(int right=0;right<n;right++){
            if(right-left>k){
                window_unique.erase(nums[left]);
                left+=1;
            }
            if(window_unique.count(nums[right])) return true;
            window_unique.insert(nums[right]);
        }

        return false;

}
