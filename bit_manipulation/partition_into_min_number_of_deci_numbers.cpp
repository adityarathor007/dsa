int minPartitions(string n) {
        int ans=0;
        for(char ch:n){
            int digit=ch-'0';
            ans=max(ans,digit);
        }
        return ans;
    }
