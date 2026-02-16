bool isValid(string s) {
        stack<char>st;
        for(char ch:s){
            if(ch=='a' or ch=='b') st.push(ch);
            else{
                if(st.empty() or st.top()!='b') return false;
                st.pop();
                if(st.empty() or st.top()!='a') return false;
                st.pop();
            }
        }
        return st.empty();
    }
