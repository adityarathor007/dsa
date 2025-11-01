 string reverseWords(string s) {
        string ans="";
        string cWord="";
        int i=0;
        while(s[i]==' ') i+=1; //remove the front space

        int n=s.size();

        for(int j=n-1;j>=i;j--){
            if(s[j]==' ' and cWord=="") continue; //back and inbetween extra space
            if(s[j]!=' '){
                cWord+=s[j];
            }
            else{
                reverse(cWord.begin(),cWord.end());
                ans+=cWord;
                cWord="";
                ans+=" ";
            }
        }

        reverse(cWord.begin(),cWord.end());
        ans+=cWord;
        return ans;

    }
