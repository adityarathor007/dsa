vector<int>scount,pcount;
public:
    bool isAnagram(){
        for(int i=0;i<26;i++){
            if(scount[i]!=pcount[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int m=s.size();
        int n=p.size();
        if(m<n) return {};
        scount.assign(26,0);
        pcount.assign(26,0);

        for(char ch:p) pcount[ch-'a']+=1;
        vector<int>ans;

        int i=0,j=0;
        while(j<n-1){
            scount[s[j]-'a']+=1;
            j+=1;
        }

        while(j<m){
            scount[s[j]-'a']+=1;
            if(isAnagram()) ans.push_back(i);
            scount[s[i]-'a']-=1;
            i+=1;
            j+=1;
        }

        return ans;
    }
