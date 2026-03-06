// NO DP just matching the template
int minOperations(string s) {
        int o1=0,o2=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i&1){
                if(s[i]=='0') o1+=1;
                else o2+=1;
            }
            else{
                if(s[i]=='1') o1+=1;
                else o2+=1;
            }

        }

        return min(o1,o2);
    }
