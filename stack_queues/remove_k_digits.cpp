string removeKdigits(string num, int k) {
        // ensuring to take the min digits after k removal
        stack<char>st;
        for(char ch:num){
            while(k and !st.empty() and st.top()>ch){
                st.pop();
                k-=1;
            }
            st.push(ch);
        }
        string temp="";
        while(!st.empty()){
            char ch=st.top();
            temp+=ch;
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        string ans;
        int n=temp.size();
        // remove k chars from last (as stack was in decreasing order so they didnt got removed)
        if(k){
            temp=temp.substr(0,n-k);
        }
        for(char ch:temp){
            if(ch=='0' and ans=="") continue;
            ans+=ch;
        }
        if(ans=="") return "0";
        return ans;
    }
