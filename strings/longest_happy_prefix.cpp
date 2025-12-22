class Solution {
public:
    string longestPrefix(string s) {
        //using kmp algorithm (finding the longest prefix which is also the suffix for the entire word so we use the lps[n-1])

        int n=s.size();
        vector<int>lps(n);
        int i=0,j=1;
        while(j<n){
            if(s[i]==s[j]){
                lps[j]=i+1;
                i+=1;j+=1;
            }
            else{
                if(i==0) j+=1;
                else i=lps[i-1];
            }
        }
        return s.substr(0,lps[n-1]);
    }
};
