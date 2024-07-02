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
        }

        bool search_helper(string s,bool substr){
            Node* curr=root;
            int n=s.length();
            int c=0;
            cout<<s<<endl;
            for(int i=0;i<n;i++){
                if(curr->map.count(s[i])!=0){
                    curr=curr->map[s[i]];
                }
                else{
                    // cout<<s<<endl;
                    return false;
                }
                
                if(curr->isTerminal and i!=n-1){
                   
                    if(search_helper(s.substr(i+1,n-i),true)){
                        c+=1;
                    }
                    
                }
                if(curr->isTerminal and i==n-1 and substr or c>0){
                    return true;
                }
            }
            return false;


        }
};

vector<string> googlyStrings(vector<string> input)
{

Trie t;
vector<string> ans;
for(auto x:input){
    t.insert(x);
}

for(auto x:input){
    cout<<"checking for string: "<<x<<endl;
    if(t.search_helper(x,false)){
        ans.push_back(x);
    }
}

return ans;


}

int main(){
    // vector<string> input{"goo", "gle", "google"};
    vector<string> input{"goo", "gle", "google", "le","googly","ly","g","googoole"};
    auto ans=googlyStrings(input);
    for(auto x:ans){
        cout<<x<<',';
    }
    cout<<endl;
    return 0;

}
