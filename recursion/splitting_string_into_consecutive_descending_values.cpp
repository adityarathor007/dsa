bool recCheck(int i,long long prev,string s){
        int n=s.size();
        if(i==n) return true;
        long long val=0;

        for(int j=i;j<n;j++){
            if(val==0 and s[j]=='0') continue;
            val=(val*10)+(s[j]-'0');
            if(prev==INT_MAX and recCheck(j+1,val,s) and j!=n-1) return true;  //trying all possible ways to start except if the first split is the entire string
            if(prev!=INT_MAX and val==prev-1) return recCheck(j+1,val,s);
            if(val>=prev) return false; //further adding digits wont be possible because of the decreasing condition
        }
        if(prev==1 and s[n-1]=='0') return true;
        return false;
    }

    bool splitString(string s) {
        return recCheck(0,INT_MAX,s);
    }
