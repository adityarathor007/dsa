#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Node{
    public:
        char c;
        unordered_map<char,Node*> m;
        bool isTerminal;
        Node(char ch){
            c=ch;
            isTerminal=false;
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
            for(char c:s){
                if(curr->m.count(c)==0){
                    curr->m[c]=new Node(c);
                }
                curr=curr->m[c];
            }
            curr->isTerminal=true;
            return ;
        }

        bool search(string s){
            Node *curr = root;
            for(char c:s){
                if(curr->m.count(c)==0){
                    return false;
                }
                curr=curr->m[c];
            }
            return curr->isTerminal;
        }
};


void checkOcc (vector <string> q,string text){
    unordered_map<string,bool> table;
    Trie t;
    

    for(auto str:q){  //inserting all queries in trie
        t.insert(str);
       
    }

  
    Node *curr = t.root;
    for(int i=0;i<text.length();i++){
        curr=t.root; //this resetting is imp as because for a particular starting letter we were not able to find the matching word so starting with next text[i]
        for(int j=i;j<text.length();j++){
            // if(t.search(text.substr(i,j-i+1))){ //!---this method is inefficient as once for a starting letter not found in the trie then we are still traversing all suffix with that letter---!
            //     table[text.substr(i, j - i + 1)]=true;  
            // }
            char ch=text[j];
            if(curr->m.count(ch)==0){
                
                break;
            }
         
            curr = curr->m[ch];

            if(curr->isTerminal){

                table[text.substr(i,j-i+1)]=true;
            }
            
        }
    }

    for (auto str : q){
        cout<<str<<" -> ";
        if(table[str]){
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
    }
}



int main(){
    // Trie t;
    // t.insert("hello");
    // t.insert("apple");
    // if(t.search("hello")){
    //     cout<<"trie code working perfectly"<<endl;
    // }
    // else{
    //     cout<<"trie not working properly"<<endl;
    // }
    
    string text="a little cute cat is roaming around";
    vector <string> q={"ttle","cute cat","roam","ze"};
    checkOcc(q,text);
    

    return 0;
}