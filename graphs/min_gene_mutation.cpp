int countMutation(string startGene ,string&endGene,unordered_set<string>&bankSet){
        queue<string>q;
        q.push(startGene);
        if(bankSet.count(startGene)) bankSet.erase(startGene);
        int cnt=0;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string cw=q.front();
                if(cw==endGene) return cnt;
                q.pop();
                for(int i=0;i<8;i++){
                    char org_char=cw[i];
                    string new_word=cw;
                    for(int k=0;k<4;k++){
                        if(org_char!=possibleChars[k]){
                            new_word[i]=possibleChars[k];
                            if(bankSet.count(new_word)){
                                bankSet.erase(new_word);
                                q.push(new_word);
                            }
                            new_word[i]=org_char;
                        }
                    }
                }
            }
            cnt+=1;
        }
        return -1;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>bankSet;

        for(string word:bank){
            bankSet.insert(word);
        }

        if(!bankSet.count(endGene)) return -1;

        return countMutation(startGene,endGene,bankSet);
    }
