struct TrieNode{
    vector<TrieNode*>children{26,nullptr};
    bool isEnd;
};

class WordDictionary {
    TrieNode* root=new TrieNode();
public:
    WordDictionary() {

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

    bool recSearch(int i,TrieNode* node,string word){
        if(i==word.size()){
            return node->isEnd;
        }
        char ch=word[i];
        if(ch!='.'){
            if(!node->children[ch-'a']) return false;
            return recSearch(i+1,node->children[ch-'a'],word);
        }

        for(int j=0;j<26;j++){
            if(node->children[j]){
                if(recSearch(i+1,node->children[j],word)) return true;
            }
        }

        return false;
    }

    bool search(string word) {
        TrieNode* temp=root;
        return recSearch(0,root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
