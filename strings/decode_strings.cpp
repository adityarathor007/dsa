string decodeString(string s) {
    // M1 (without passing index to recursion)
        string ans="";
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            while(i<n and isalpha(s[i])){
                ans+=s[i];
                i+=1;
            }
            if(i==n) break;

            int num=0;
            while(s[i]!='[' and isdigit(s[i])){
                num=num*10+(s[i]-'0');
                i+=1;
            }
            st.push('[');
            i+=1;
            string curr="";
            while(isalpha(s[i])){
                curr+=s[i];
                i+=1;
            }

            string internal=""; //constructing the internal string if present
            while(!st.empty()){
                if(s[i]==']' and st.size()==1){
                    st.pop();
                }
                else{
                    if(s[i]=='[') st.push('[');
                    else if(s[i]==']') st.pop();
                    internal+=s[i];
                }

                i+=1;
            }

            string dec_internal=decodeString(internal);
            for(int j=0;j<num;j++){
                ans+=(curr+dec_internal);
            }

            i-=1;

        }


        return ans;

        // M2
        int i=0;
        return decode(s,i);
    }

    string decode(const string&s, int& i){  //index also passed by reference
        string result="";
        int curr_reps=0;
        while(i<s.size()){
            char ch=s[i];
            if(isdigit(ch)){
                curr_reps=curr_reps*10+(ch-'0');
                i+=1;
            }
            else if(ch=='['){
                i+=1;
                string inner=decode(s,i);
                for(int k=0;k<curr_reps;k++){
                    result+=inner;
                }
                curr_reps=0;
            }
            else if(ch==']'){
                i+=1;
                return result;
            }
            else{
                result+=ch ;
                i+=1;
            }
        }
        return result;
    }
