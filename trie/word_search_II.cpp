class Solution{
    vector<vector<int>>dirn{{-1,0},{0,1},{1,0},{0,-1}};
    bool isValid(int x,int y, int m, int n){
        if(x<0 or x>=m or y<0 or y>=n) return false;
        return true;
    }

    void dfs(int i,int j,string cs,TrieNode* node,vector<vector<int>>&visited,vector<vector<char>>&board,unordered_set<string>&ansSet){
        if(!node->children[board[i][j]-'a']) return;
        int m=board.size();
        int n=board[0].size();

        TrieNode* prevNode=node;
        node=node->children[board[i][j]-'a'];
        visited[i][j]=1;
        cs=cs+board[i][j];

        if(node->isEnd) ansSet.insert(cs);

        for(int k=0;k<4;k++){
            int nx=i+dirn[k][0];
            int ny=j+dirn[k][1];
            if(isValid(nx,ny,m,n) and !visited[nx][ny]){
                dfs(nx,ny,cs,node,visited,board,ansSet);
            }
        }

        visited[i][j]=0;
        cs.pop_back();
        node=prevNode;
        return;

    }

    public:
    vector<string>findWords(vector<vector<char>>&board,vector<string>&words){
        Trie trie=Trie();
        for(string word:words){
            trie.insert(word);
        }
        int m=board.size();
        int n=board[0].size();
        TrieNode* root=trie.root;
        unordered_set<string>ansSet;
        vector<vector<int>>visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(i,j,"",root,visited,board,ansSet);
            }

        }
        // if(m>2 and n>1){
        //     vector<vector<int>>visited(m,vector<int>(n,0));
        //     string start="";
        //     dfs(2,1,start+board[2][1],visited,board,trie,ansSet);
        // }


        vector<string>ans(ansSet.begin(),ansSet.end());
        return ans;
    }
};
