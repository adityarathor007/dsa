int longestContinuousSubstring(string s) {
        int max_len=1,curr_len=1;
        char prev_char=s[0];
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]-1==prev_char) curr_len+=1;
            else curr_len=1;
            max_len=max(max_len,curr_len);
            prev_char=s[i];
        }

        return max_len;

    }
