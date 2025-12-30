class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>postn;
        int n=s.size();
        int i=0,j=0,max_len=0;
        while(j<n){
            char ch=s[j];
            if(postn.find(ch)!=postn.end()){
                i=max(i,postn[ch]+1); //because of some previous character coming in it may be shifted behind the current position of i
            }
            postn[ch]=j;
            max_len=max(max_len,j-i+1);
            j+=1;
        }
        return max_len;

    }
};
