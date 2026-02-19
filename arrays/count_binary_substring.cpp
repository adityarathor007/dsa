int countBinarySubstrings(string s) {
        int ans=0;
        int cnt_0=0,cnt_1=0;
        int n=s.size();
        int i=0;
        while(i<n){
            if(i!=0 and s[i]==s[i-1]){
                if(s[i]=='0') cnt_0+=1;
                else cnt_1+=1;
            }
            else{
                ans+=min(cnt_0,cnt_1);
                if(s[i]=='0') cnt_0=1;
                else cnt_1=1;
            }
            i+=1;
        }
        ans+=min(cnt_0,cnt_1);
        return ans;

    }
