struct TrieNode{
    vector<TrieNode*>children{26,nullptr};
    bool isEnd=false;
};


class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root=new TrieNode();
    }

    void addWord(string word) {
        TrieNode* temp=root;
        for(char ch:word){
            if(!temp->children[ch-'a']){
                temp->children[ch-'a']=new TrieNode();
            }
            temp=temp->children[ch-'a'];
        }
        temp->isEnd=true;
    }

    bool recSearch(int i, TrieNode* temp, string word){
        if(i==word.size()){
            return temp->isEnd;
        }

        // cout<<word[i]<<endl;

        if(word[i]!='.'){
            if(!temp->children[word[i]-'a']) return false;
            return recSearch(i+1,temp->children[word[i]-'a'], word);
        }

        for(int ch='a';ch<='z';ch++){
            if(temp->children[ch-'a']){
                if(recSearch(i+1,temp->children[ch-'a'],word)){
                    return true;
                }
            }

        }
        return false;
    }

    bool search(string word) {
        TrieNode* temp=root;
        return recSearch(0,temp,word);
    }
};
