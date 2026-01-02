bool checkLeftToRightIso(string s,string t){
        int i=0;
        int n=s.size();
        unordered_map<char,char>mp_st;

        while(i<n){
            char c1=s[i], c2=t[i];
            if(mp_st.find(c1)==mp_st.end()){
                mp_st[c1]=c2;
            }
            else{
                if(mp_st[c1]!=c2) return false;
            }
            i+=1;
        }
        return true;
    }

bool isIsomorphic(string s, string t) {
    return checkLeftToRightIso(s,t) and checkLeftToRightIso(t,s);
}
