class Solution {
    unordered_set<string>bankSet;
    vector<char>possibleChar{'A','C','G','T'};
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bankSet.clear();
        for(string gene:bank) bankSet.insert(gene);

        queue<string>q;
        int level=0;
        q.push(startGene);
        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                string curr=q.front();
                q.pop();
                if(curr==endGene) return level;
                for(int i=0;i<8;i++){
                    char oc=curr[i];
                    for(char ch:possibleChar){
                        if(ch==oc) continue;
                        curr[i]=ch;
                        if(bankSet.count(curr)){
                            bankSet.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[i]=oc;
                }
            }
            level+=1;
        }

        return -1;
    }
};
