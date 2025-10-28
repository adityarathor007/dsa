vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());

        string curr_word="";
        vector<vector<string>>ans;

        for(char ch:searchWord){
            curr_word+=ch;
            auto it=lower_bound(products.begin(),products.end(),curr_word);  //first element that is >= curr_word
            int cnt=0;
            vector<string>retrievedWords;
            while(it!=products.end() and cnt!=3){
                string s=*it;
                if(s.find(curr_word)) break;  //if the curr_word is not the prefix of s so it wont continue for further words
                retrievedWords.push_back(*it);
                cnt+=1;
                it+=1;
            }
            ans.push_back(retrievedWords);

        }

        return ans;
    }
