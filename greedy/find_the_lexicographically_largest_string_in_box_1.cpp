string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        char largest='a';

        for(char ch:word) largest=max(largest,ch);

        string ans="";
        int n=word.size();
        for(int i=0;i<n;i++){
            if(word[i]!=largest) continue;
            else{
                int friendsLeft=max(0,numFriends-i-1);
                int possible_len=n-friendsLeft-i;
                string cs=word.substr(i,possible_len);
                ans=max(ans,cs); //there would be multiple possible starting chars which are largest so need to consider that case also
            }
        }
        return ans;
    }
