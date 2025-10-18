bool isVowel(char ch){
        char lower_ch=tolower(ch);
        switch(lower_ch){
            case 'a':
                return true;
            case 'e':
                return true;
            case 'i':
                return true;
            case 'o':
                return true;
            case 'u':
                return true;
            default:
                return false;
            
        }
        return false;
    }
    
string reverseVowels(string s) {
        string vowelString="";
        for(char ch:s){
            if(isVowel(ch)) vowelString+=ch;
        }
        int size=s.size();
        int j=0;

        for(int i=size-1;i>=0;i--){
            if(isVowel(s[i])){
                s[i]=vowelString[j];
                j+=1;
            }
        }

        return s;
    }
