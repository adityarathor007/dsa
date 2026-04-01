string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber){
            int rem=columnNumber%26;
            if(!rem) rem+=26;
            ans+='A'+(rem-1);
            columnNumber/=26;
            if(rem==26) columnNumber-=1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
