string removeDuplicateLetters(string s) {
        vector<int>lastOccur(26,-1);
        int n=s.size();

        for(int i=0;i<n;i++){
            lastOccur[s[i]-'a']=i;
        }

        stack<char>st;
        unordered_set<char>visited;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(visited.count(ch)) continue;

            while (!st.empty() and st.top()>ch and lastOccur[st.top()-'a']>i){ //removing from stack if prev larger occurs again
                    visited.erase(st.top());
                    st.pop();
                }
            st.push(ch); //inserting after the previous char are smaller or prev char is occuring once
            visited.insert(ch);
        }


        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
