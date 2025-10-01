/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(!root) return ans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();

                if(!current){
                    ans+="#,";
                    continue;
                }

                ans+=to_string(current->val);
                ans+=",";


                q.push(current->left);
                q.push(current->right);


            }
        }

        cout<<ans<<endl;

        return ans;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        int it=0;

        string numStr="";
        bool neg=false;
        while(data[it]!=','){
            if(data[it]=='-'){
                neg=true;
            }
            else{
                    numStr+=data[it];
                }
                it+=1;

            }

        it+=1;

        int root_val=stoi(numStr);
        if(neg) root_val*=-1;

        TreeNode* root=new TreeNode(root_val);
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();

                int start=it;
                neg=false;

                numStr="";
                while(data[it]!=','){
                    if(data[it]=='-'){
                        neg=true;
                    }
                    else{
                        numStr+=data[it];
                    }
                    it+=1;

                }
                it+=1;

                if(numStr!="#"){
                    cout<<numStr<<endl;
                    int num=stoi(numStr);
                    if(neg) num*=-1;
                    current->left=new TreeNode(num);
                    q.push(current->left);
                }

                neg=false;
                numStr="";

                while(data[it]!=','){
                    if(data[it]=='-'){
                        neg=true;
                    }
                    else{
                        numStr+=data[it];
                    }
                    it+=1;

                }
                it+=1;

                if(numStr!="#"){
                    cout<<numStr<<endl;
                    int num=stoi(numStr);
                    if(neg) num*=-1;
                    current->right=new TreeNode(num);
                    q.push(current->right);
                }

            }
        }

        return root;


    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
