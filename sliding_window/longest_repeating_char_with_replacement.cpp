int characterReplacement(string s, int k) {
        int i=0,j=0;
        vector<int>cnt(26,0);

        int max_freq=0;
        int n=s.size();
        int ans=0;

        while(j<n){
            // cout<<i<<" "<<j<<endl;
            cnt[s[j]-'A']+=1;
            max_freq=max(max_freq,cnt[s[j]-'A']);
            int win_size=j-i+1;
            if(win_size-max_freq<=k) ans=max(ans,win_size);
            else{
                cnt[s[i]-'A']-=1;
                i+=1;
            }
            j+=1;
        }
        return ans;
}
