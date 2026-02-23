class Solution {
    unordered_map<string,int>mp;
  public:
    string preOrder(Node* node){
        if(!node) return "";

        //root
        string s=to_string(node->data);


        for(auto child:node->children){
            s+='('+preOrder(child)+')';
        }

        mp[s]+=1;
        return s;

        //storing the string
    }

    int duplicateSubtreeNaryTree(Node *root) {
        // Code here
        preOrder(root);
        int ans=0;
        for(auto [treeStr,cnt]:mp){
            if(cnt>1) ans+=1;
        }
        return ans;
    }
};
