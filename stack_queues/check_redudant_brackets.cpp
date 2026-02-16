bool isOp(char ch){
        if(ch=='+' or ch=='-' or ch=='*' or ch=='/') return true;
        return false;
    }

    bool checkRedundancy(string &s) {
        // code here
        stack<char>st;
        for(char ch:s){
            if(ch=='(') st.push('(');
            else if(isOp(ch)){
                if(st.empty() or st.top()=='(') st.push('ch');
            }

            else if(ch==')'){
                if(st.empty() or st.top()=='(') return true;
                st.pop();
                st.pop();
            }

        }

        return false;
    }
