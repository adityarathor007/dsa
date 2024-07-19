struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution {
      public:
        // Function to construct binary tree from parent array.
        Node *createTree(vector<int> parent) {
            // Your code here
            int n=parent.size();
            unordered_map<int,Node*> s;  //created a mapping between integer and the node*  
            
            Node *r;
            for(int i=0;i<n;i++){
                if(s.find(i)==s.end()){
                    s[i]=new Node(i);
                }
                
                if(parent[i]==-1){
                    r=s[i];
                    continue;
                }
                
                if(s.find(parent[i])==s.end()){
                    s[parent[i]]=new Node(parent[i]);
                    
                }
                if(!s[parent[i]]->left){
                    s[parent[i]]->left=s[i];
                }
                else{
                    s[parent[i]]->right=s[i];
                }
                    
                    
               
        
                
                
            }
            return r;
            
        }
        
    };