
int minFlips(string s) {
    int n=s.size();
    s+=s;
    int op1=0; //starting with 0
    int op2=0;
    int ans=INT_MAX;
    for(int i=0;i<2*n;i++){
        char p1 = (i%2)?'1':'0';
        char p2 = (i%2)?'0':'1';
        if(s[i]!=p1) op1+=1;
        if(s[i]!=p2) op2+=1;
        if(i>=n){
            int pi=i-n;
            p1=(pi%2)?'1':'0';
            p2 = (pi%2)?'0':'1';
            if(s[pi]!=p1) op1-=1;
            if(s[pi]!=p2) op2-=1;
        }
        if(i>=n-1){
            ans=min({ans,op1,op2});
        }

    }

    return ans;
}
