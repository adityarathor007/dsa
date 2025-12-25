struct TrieNode{
    vector<TrieNode*>children{2,nullptr};
};

class Trie{
public:
    TrieNode* root=new TrieNode();

    void add(int num){
        TrieNode* temp=root;

        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!temp->children[bit]){
                temp->children[bit]=new TrieNode();
            }
            temp=temp->children[bit];
        }
    }

    int getMaxXOR(int num){
        TrieNode* temp=root;
        int val=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(temp->children[1-bit]){
                temp=temp->children[1-bit];
                val+=(1<<i);
            }
            else temp=temp->children[bit];
        }

        return val;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie=Trie();

        for(int num:nums){
            trie.add(num);
        }

        int max_val=0;
        for(int num:nums){
            int curr_xor=trie.getMaxXOR(num);

            if(curr_xor>max_val){
                t
                max_val=curr_xor;
            }
        }
        return max_val;
    }
};
