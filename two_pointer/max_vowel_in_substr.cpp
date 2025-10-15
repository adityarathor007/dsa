 bool checkVowel(char ch){
        switch(ch){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
        }
    }

    int maxVowels(string s, int k) {
        int i=0,j=0;
        int n=s.size();
        int max_vowel=0;
        int curr_cnt=0;
        while(j<n){
            if(checkVowel(s[j])) curr_cnt+=1;
            j+=1;
            if(j-i==k){
                max_vowel=max(max_vowel,curr_cnt);
                if(checkVowel(s[i])) curr_cnt-=1;
                i+=1;
            }
        }

        return max_vowel;
    }
