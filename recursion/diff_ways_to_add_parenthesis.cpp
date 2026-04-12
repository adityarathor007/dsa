vector<int> recSolve(int s,int e,string expression){
        vector<int>vec;
        bool hasOp=false;
        int num=0;
        for(int i=s;i<=e;i++){
            if(!isdigit(expression[i])){
               hasOp=true;
               auto lvec=recSolve(s,i-1,expression) ;
               auto rvec=recSolve(i+1,e,expression);
               char ch=expression[i];
               for(auto l:lvec){
                for(auto r:rvec){
                    int val;
                    if(ch=='+') val=l+r;
                    else if(ch=='*') val=l*r;
                    else val=l-r;
                    vec.push_back(val);
                }
               }
            }
            else if(!hasOp) num=num*10+(expression[i]-'0');
        }
        if(!hasOp) return {num};
        return vec;

    }
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.size();
        return recSolve(0,n-1,expression);
    }
