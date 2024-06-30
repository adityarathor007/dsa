#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node{
    public:
    char ch;
    unordered_map<char,Node*> map;
    bool isTerminal;
    Node(char ch){
        this->ch=ch;
        isTerminal=false;
    }
};

class Trie{
    Node* root;
    Trie(){
        root=new Node('\0');
    }
    
    void insert(string s){
        Node* curr=root;
        for(auto x:s){
            if(curr->map.count(x)==0){
                curr->map[x]=new Node(x);
            }
            curr=curr->map[x];
        }
        curr->isTerminal=true;
    }
};

vector<string> googlyStrings(vector<string> input)
{

}

int main(){
    vector<string> input{"goo", "gle", "google", "le","googly","ly","g","googoole"};
    auto ans=googleStrings(input);
    return 0;

}
