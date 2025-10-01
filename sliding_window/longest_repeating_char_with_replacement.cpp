class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>freq;
        int i=0,j=0;
        int n=int(s.size());
        int max_freq=0;


        while(j<n){
            freq[s[j]]+=1;
            max_freq=max(max_freq,freq[s[j]]);
            if((j-i+1)-max_freq>k){
                freq[s[i]]-=1;
                i+=1;

            }

            if((j-i+1)-max_freq<=k){
                int l=j-i+1;
                max_len=max(max_len,l);
            }

            j+=1;
        }

        return max_len;
    }
};
