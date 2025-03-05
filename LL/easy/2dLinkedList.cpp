    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // code Here
        int n=mat.size();
        vector<Node*>start; 
        Node* head;
        for(int i=0;i<n;i++){
            Node* temp=new Node(mat[i][0]);
            if(i==0){
                head=temp;
            }
            start.push_back(temp);
            for(int j=1;j<n;j++){
              Node* n=new Node(mat[i][j]);  
              temp->right=n;
              temp=temp->right;
            }
            
        }
        
        
        for(int i=1;i<n;i++){
                Node* t1=start[i-1];
                Node* t2=start[i];
            for(int j=0;j<n;j++){
               
                t1->down=t2;
                t1=t1->right;
                t2=t2->right;
            }
        }
        
        return head;
        
        
    }