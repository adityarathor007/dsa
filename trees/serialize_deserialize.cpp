    string serialize(TreeNode* root) {
        string data="";
        if(!root) return data;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            data+='[';

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->val==1001) data+='N';
                else{
                    data+=to_string(node->val);
                    if(node->left) q.push(node->left);
                    else q.push(new TreeNode(1001));
                    if(node->right) q.push(node->right);
                    else q.push(new TreeNode(1001));

                }
                if(i!=size-1) data+=',';
            }
            data+=']';
        }
        cout<<data<<endl;
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        int i=1;

        int root_val=0;
        bool neg=false;
        while(data[i]!=']'){
            if(data[i]=='-') neg=true;
            else root_val=root_val*10+(data[i]-'0');
            i+=1;
        }

        i+=1;

        if(neg) root_val*=-1;
        TreeNode* root=new TreeNode(root_val);
        queue<TreeNode*>q;
        q.push(root);

        while(i<data.size()){
            int size=q.size();
            i+=1;

            for(int j=0;j<size;j++){

                TreeNode* cn=q.front();
                q.pop();
                int left_val=0;
                neg=false;
                while(data[i]!=','){
                    if(data[i]=='-') neg=true;
                    else if(data[i]!='N') left_val=left_val*10+(data[i]-'0');
                    i+=1;
                }
                if(data[i-1]!='N'){
                    if(neg) left_val*=-1;
                    cn->left=new TreeNode(left_val);
                    q.push(cn->left);
                }

                i+=1; //move next to the comma

                int right_val=0;
                neg=false;

                while(data[i]!=',' and data[i]!=']'){
                    if(data[i]=='-') neg=true;
                    else if(data[i]!='N') right_val=right_val*10+(data[i]-'0');
                    i+=1;
                }
                if(data[i-1]!='N'){
                    if(neg) right_val*=-1;
                    cn->right=new TreeNode(right_val);
                    q.push(cn->right);
                }
                // cout<<left_val<<" "<<right_val<<endl;
                if(data[i]==',') i+=1;

            }
            i+=1;
        }

        return root;
    }
