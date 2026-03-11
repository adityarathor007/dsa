// IMPORTANT: Only hashmap and binary search can be used for finding the unique pairs (uniquness based on the indicies)
// 2 pointer approach wont be able to find all pairs, it wont be able to decide how to move pointers in case of duplicate values

class Solution {
    int MOD=1e9+7;
public:
    int countPairs(vector<int>& deliciousness) {
        int n=deliciousness.size();
        unordered_map<int,int>mp;
        long long ans=0;

        for(int num:deliciousness){
            int target=1;
            for(int power=0;power<=21;power++){ //there are just 22 power
                int rem=target-num;
                target=target<<1;
                if(mp.count(rem)) ans=(ans+mp[rem])%MOD;
            }
            mp[num]+=1;
        }

        return ans;
    }
};
