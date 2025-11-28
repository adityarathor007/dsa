class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(m.find(s[i])==m.end()){
                m[s[i]]=t[i];
            }
            else{
                if(m[s[i]]!=t[i]) return false;
            }
        }


        // it may be possible that unique mapping is dont from left to right but there is a possiblity that 2 chars are mapping to one thing
        unordered_map<char,char>m1;
        for(int i=0;i<n;i++){
            if(m1.find(t[i])==m.end()){
                m1[t[i]]=s[i];
            }
            else{
                if(m1[t[i]]!=s[i]) return false;
            }
        }
        return true;
    }
};
