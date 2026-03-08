 bool isAnagram(string s, string t) {
        unordered_map<char,int>freqTable;
        for(auto x:s){
            freqTable[x]+=1;
        }
        for(auto x:t){
            freqTable[x]-=1;
            if(freqTable[x]<0) return false;
        }

        for(auto [key,cnt]:freqTable){
            if(cnt!=0) return false;
        }

        return true;        
    }