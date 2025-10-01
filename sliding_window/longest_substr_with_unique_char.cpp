class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int n=s.size();
        unordered_map<int,int>mp;
        int max_len=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                i=max(i,mp[s[j]]+1);
            }
            max_len=max(max_len,i-j);
            mp[s[j]]=j;
            j+=1;
        }

        return ans;
    }
};
