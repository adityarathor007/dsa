#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

#define M 3
#define N 4


class Node{
    public:
    char d;
    unordered_map<char,Node*> children;  //for storing the character and the node pointer of that character's node
    bool isTerminal;
    string word;

   
        Node(char c){
            d=c;
            isTerminal=false;
            word="";
        }


};


class Trie{
    
    public:
    Node* root;
    Trie(){
        root=new Node('\0');
    }

    void addWord(string s){
        Node* curr=root;
        for(char ch:s){
            if(curr->children.count(ch)==0){

                curr->children[ch]=new Node(ch);

            }
            curr=curr->children[ch];
        }
        curr->isTerminal=true;
        curr->word=s;


        return ;

    }

    bool search(string s){
        Node* curr=root;
        for(char ch:s){
            if(curr->children.count(ch)==0){
                
                return false;
            }
            curr=curr->children[ch];
        }
        return curr->isTerminal;

    }

};


void dfs(Node* n,char boogle[][N],int i,int j,unordered_set<string> &ans,bool  visited[][N]){
    // cout<<"the letter to search from the root: "<<n->d<<" in the child is : "<<boogle[i][j]<<endl;


    

    if(n->children.count(boogle[i][j])==0){
        return ;
    }
   
    visited[i][j]=true;
    n=n->children[boogle[i][j]];

    if(n->isTerminal){
        // cout<<"reached the terminal"<<n->word<<endl;
        ans.insert(n->word);
    }

    

   
    int dx[]={-1,0,1,1,1,0,-1,-1};
    int dy[]={-1,-1,-1,0,1,1,1,0};
    for(int k=0;k<8;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        
        if(ni>=0 and nj>=0 and ni<M and nj<N and !visited[ni][nj]){
            dfs(n,boogle,ni,nj,ans,visited);
        }
    }
    visited[i][j]=false; //can reach here if backtraversed here from some other path
    return ;
}



int main(){
    string words[]={"SNACKS","SNACK","GO","FOR","QUEZ","SNAKE","CAT"};

    char boogle[M][N]={{'S','E','R','T'},{'U','N','K','S'},{'T','C','A','T'}};

    Trie t;
    for(auto w:words){
        t.addWord(w);
    }

    // if(t.search("SNAC")){
    //     cout<<"wrong"<<endl;
    // }

    // if(t.search("SNACKS")){
    //     cout<<"Right"<<endl;
    // }



    unordered_set<string> ans;

    bool visited[M][N]={0};

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            // cout<<"Starting with i and j as: "<<i<<j<<endl;
            dfs(t.root,boogle,i,j,ans,visited);

        }
    }

    // printing the final output
    for(auto a:ans){
        cout<<a<<endl;
    }

return 0;
}
    