#include <iostream>
#include <unordered_map>
using namespace std;

struct TrieNode{
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool isTerminal=false;
};


class Trie{
     TrieNode* root;
    public:
        Trie() {
            root=new TrieNode();
        }

        void insert(string word) {
            TrieNode* curr=root;
            for(char ch:word){
                if(!curr->children[ch-'a']){
                    curr->children[ch-'a']=new TrieNode();
                }
                curr=curr->children[ch-'a'];
            }
            curr->isTerminal=true;
        }

        bool search(string word) {
            TrieNode* curr=root;
            for(char ch:word){
                if(!curr->children[ch-'a']) return false;
                curr=curr->children[ch-'a'];
            }
            return curr->isTerminal;
        }

        bool startsWith(string prefix) {
            TrieNode* curr=root;
            for(char ch:prefix){
                if(!curr->children[ch-'a']) return false;
                curr=curr->children[ch-'a'];
            }
            return true;
        }

};


int main(){
    string words[]={"apple","ape","no","news","not","never"};
    Trie t;

    for(auto w:words){
        t.insert(w);
    }

    int q;
    cin>>q;

    string search_word;
    while(q--){
        cin>>search_word;
        if(t.search(search_word)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }


}
