TrieNode* children[26];
    bool isEnd=false;
    TrieNode(){
        for(int i=0;i<26;i++) children[i]=nullptr;
    }

};

class Solution {
    TrieNode* root=new TrieNode();
public:
    void insert(string word){
        TrieNode* node=root;
        for(char ch:word){
            if(!node->children[ch-'a']){
                node->children[ch-'a']=new TrieNode();
            }
            node=node->children[ch-'a'];
        }
        node->isEnd=true;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        for(string word:dictionary){
            insert(word);
        }
        int n=s.size();
        vector<int>dp(n+1,INT_MAX); //dp[i] denotes the min extra characters from i to end
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            dp[i]=1+dp[i+1]; //if ith character is considered extra
            TrieNode* node=root;
            for(int j=i;j<n;j++){
                char ch=s[j];
                if(!node->children[ch-'a']) break;

                node=node->children[ch-'a'];

                if(node->isEnd){
                    dp[i]=min(dp[i],dp[j+1]); //checking which is min either the curr or the one starting with j+1 as from i till j we have found the word
                }
            }
        }

        return dp[0];

    }
