class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string,int>mp;
        for(string s:nums) mp[s]++;
        int ans=0;
        for(string s:nums){
            if(target.starts_with(s)){
                string rem=target.substr(s.size());
                if(mp.count(rem)){
                    cout<<s<<" "<<rem<<endl;
                    ans+=mp[rem];
                    if(rem==s) ans--;
                }

            }
        }

        return ans;

    }
};
