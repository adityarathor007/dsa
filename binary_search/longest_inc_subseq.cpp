// place each number in the earliest position in tails where it can serve as a new (smaller) ending.
// A smaller ending value gives more “room” to extend the subsequence in the future.

int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        for(int num:nums){
            int gindex=lower_bound(temp.begin(),temp.end(),num)-temp.begin();
            if(gindex==temp.size()) temp.push_back(num);
            else temp[gindex]=num;
        }
        return int(temp.size());
}
