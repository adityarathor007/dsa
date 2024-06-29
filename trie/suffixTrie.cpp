#include <iostream>
#include <unordered_map>
using namespace std;


class Node{
    public:
        char ch;
        unordered_map<char, Node*> m;
        bool isTerminal;
        Node(char c){
            ch=c;
            isTerminal=false;
        }
};

class SuffixTrie{
    public:
        Node* root;
        SuffixTrie(){
            root=new Node('\0');
        }
        
        void insert_helper(string s){
            Node* curr=root;
            for(char x:s){
                if(curr->m.count(x)==0){
                    curr->m[x]=new Node(x);
                }
                curr=curr->m[x];
            }
            curr->isTerminal=true;
        }
        
        bool search(string s){
            Node* curr=root;
            for(char x:s){
                if(curr->m.count(x)==0){
                    return false;
                }
                curr=curr->m[x];
            }
            return curr->isTerminal;
            
        }
        
        void insert(string s){
            int n=s.size();
            
            for(int i=0;i<n;i++){
                insert_helper(s.substr(i,n-i));
            }
        }
        
};


int main(){
    string s="apple";
    int n=s.size();
    SuffixTrie t;
    
    t.insert(s);
 
    if(t.search("pple")){
        cout<<"suffix tree formed"<<endl;
    }
    else{
        cout<<"not formed"<<endl;
    }
    return 0;
}