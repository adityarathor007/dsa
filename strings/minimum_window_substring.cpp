bool allCovered(unordered_map<char,int>&freq){
        for(auto [key,val]:freq){
            if(val>0) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char,int>freq;
        for(char ch:t) freq[ch]+=1;

        int i=0,j=0,n=s.size();
        int minLen=INT_MAX;
        // string ans="";  //instead of updating the ans maintain the ans pointers, as it requires less space
        int ai=-1,aj=-1;

        while(j<n){
            if(freq.find(s[j])!=freq.end()) freq[s[j]]-=1;
            // cout<<s.substr(i,j-i+1)<<endl;
            while(allCovered(freq)){
                if(j-i+1<minLen){
                    minLen=j-i+1;
                    ai=i,aj=j;
                }
                if(freq.find(s[i])!=freq.end()) freq[s[i]]+=1;
                i+=1;
            }
            j+=1;
        }

        string ans;
        if(minLen==INT_MAX) return ans;
        ans=s.substr(ai,aj-ai+1);
        return ans;
    }
