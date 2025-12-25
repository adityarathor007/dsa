struct TrieNode{
    vector<TrieNode*> children{26,nullptr};
    bool isEnd;
};

class Trie{
    public:
        TrieNode* root=new TrieNode();
        void insert(string word){
            TrieNode* temp=root;
            for(char ch:word){
                if(!temp->children[ch-'a']){
                    temp->children[ch-'a']=new TrieNode();
                }
                temp=temp->children[ch-'a'];
            }
            temp->isEnd=true;
        }
};

class Solution {
    vector<vector<int>>dirn{{-1,0},{0,1},{1,0},{0,-1}};
    bool isValid(int x,int y,int m,int n){
        if(x>=0 and x<m and y>=0 and y<n) return true;
        return false;
    }
    void dfs(int i,int j,TrieNode*&node,string curr,unordered_set<string>&ansSet,vector<vector<char>>&board){
        char curr_char=board[i][j];
        if(board[i][j]=='#' or !node->children[curr_char-'a']) return;

        int m=board.size();
        int n=board[0].size();

        TrieNode* prev_node=node;
        node=node->children[curr_char-'a'];
        board[i][j]='#';
        curr+=curr_char;

        if(node->isEnd) ansSet.insert(curr);

        for(int k=0;k<4;k++){
            int nx=i+dirn[k][0];
            int ny=j+dirn[k][1];

            if(isValid(nx,ny,m,n)){
                dfs(nx,ny,node,curr,ansSet,board);
            }
        }

        board[i][j]=curr_char;
        node=prev_node;
        curr.pop_back();
        return ;

    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie=Trie();
        for(string word:words){
            trie.insert(word);
        }
        TrieNode* root=trie.root;

        int m=board.size();
        int n=board[0].size();
        unordered_set<string>ansSet;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(i,j,root,"",ansSet,board);
            }
        }
        vector<string>ans(ansSet.begin(),ansSet.end());
        return ans;
    }
};
