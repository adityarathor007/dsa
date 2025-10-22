vector<vector<char>>digit_to_char;
    vector<string> append_char_from_digit(char digit, vector<string>ans){
        if(ans.empty()){
            for(char letter:digit_to_char[digit-'2']){
                string s(1, letter); 
                ans.push_back(s);
            }
            return ans;
        }
        else{
            vector<string>a2;
            for(string temp:ans){
                for(char letter:digit_to_char[digit-'2']){
                    a2.push_back(temp+letter);
                }
            }
            return a2;
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        digit_to_char={{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

        for(char digit:digits){
            ans=append_char_from_digit(digit,ans);
        }
        return ans;
    }