int expandAroundCenter(int l,int r,string &s){
        while(l>=0 and r<s.size()){
            if(s[l]==s[r]){
                l-=1;
                r+=1;
            }
            else break;
        }
        return r-l-1;

    }

    string longestPalindrome(string s) {
        int n=s.size();
        int start=0,end=0;
        for(int i=0;i<n;i++){
            int odd=expandAroundCenter(i,i,s);
            int even=expandAroundCenter(i,i+1,s);
            int max_len=max(odd,even);
            if(max_len>end-start+1){
                start=i-(max_len-1)/2;
                end=i+max_len/2;
            }
        }
        return s.substr(start,end-start+1);
    }
