#include<iostream>
#include<unordered_set>
using namespace std;
class Node{
    public:
    char ch;
    unordered_map<char,Node*> map;
    string s;
    bool isTerminal;
    Node(char ch){
        this->ch=ch;
        isTerminal=false;
        s="";
    }
};

class Trie{
    public:
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
            curr->s=s; //to store the word reached untill this terminal node
        }

};

vector<string> keypad{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


void validWords(Node* root,string phoneNumber,int i,unordered_set<string>&valid_words){
    if(root->isTerminal){
        valid_words.insert(root->s);
    }
    if(i==phoneNumber.length()){
        return ;
    }
    
    int d=phoneNumber[i]-'0';
    
    for(char ch:keypad[d]){
        if(root->map.count(ch)!=0){
                validWords(root->map[ch],phoneNumber,i+1,valid_words);
            }
            
        }
    return;
            
}



vector<string>  filterNames(string phoneNumber, vector<string> words){
    
    Trie t;
    for(auto w:words){
        t.insert(w);
    }

    
    
    unordered_set <string> ans;
    

    for(int i=0;i<phoneNumber.size();i++){
        
       validWords(t.root,phoneNumber,i,ans);
        
    }
    
    
    return vector<string>(ans.begin(),ans.end());
}

int main(){
    string phoneNum="666";
    vector<string> words={"mom","om","mo"};
    auto ans=filterNames(phoneNum,words);
    for(auto x:ans){
        cout<<x<<",";
    }
    cout<<endl;
}