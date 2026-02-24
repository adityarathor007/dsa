
    string customSortString(string order, string s) {
        unordered_map<char,int>freq;
        for(char ch:s) freq[ch]+=1;
        string ans="";

        for(char ch:order){
            if(freq.count(ch)){
                int cnt=freq[ch];
                ans += string(cnt, ch);
                freq.erase(ch);
                cout<<ans<<endl;
            }
        }

        for(auto [ch,cnt]:freq){
            ans += string(cnt, ch);
        }

        return ans;
    }
