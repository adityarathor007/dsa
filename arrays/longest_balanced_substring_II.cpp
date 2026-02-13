int mono(string s){
        int cnt=1;
        int ans=1;
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) cnt+=1;
            else cnt=1;
            ans=max(ans,cnt);
        }
        return ans;
    }

    int duo(string s,char c1,char c2){
        unordered_map<int,int>pos;
        int delta=0;
        int n=s.size();
        int ans=0;
        pos[0]=-1;

        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch!=c1 and ch!=c2){
                pos.clear();
                delta=0;
                pos[0]=i;
            }
            else if(ch==c1) delta+=1;
            else delta-=1;

            if(pos.count(delta)){
                ans=max(ans,i-pos[delta]);
            }
            else pos[delta]=i;
        }


        return ans;
    }

    int trio(string s){
        map<vector<int>,int>mp;
        vector<int>cnt(3,0);
        int n=s.size();
        int ans=0;
        mp[{0,0}]=-1;

        for(int i=0;i<n;i++){
            cnt[s[i]-'a']+=1;
            vector<int>key={cnt[2]-cnt[0],cnt[1]-cnt[0]};
            if(mp.count(key)) ans=max(ans,i-mp[key]);
            else mp[key]=i;
        }

        return ans;
    }

    int longestBalanced(string s) {
        int ans=max({mono(s),duo(s,'a','b'),duo(s,'a','c'),duo(s,'b','c'),trio(s)});
        return ans;
    }
