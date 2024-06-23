#include<iostream>
using namespace std;


class Node{
    public:
        int key;
        Node* left;
        Node* right;
        
        Node(int k){
            key=k;
            left=NULL;
            right=NULL;
        }
};


Node* insert(Node* root,int x){
    if(root==NULL){
        return new Node(x);
    }
    if(x<=root->key){
       root->left= insert(root->left,x);
    }
    else{
        root->right=insert(root->right,x);
    }
    return root;
}

void printInOrderTraversal(Node* root){
    if(root->left==NULL and root->right==NULL){
        cout<<root->key<<" ";
        return ;
    }
    if(root->left){
        printInOrderTraversal(root->left);
    }
    
    cout<<root->key<<" ";
    
    if(root->right){
        printInOrderTraversal(root->right);
    }
    
    
    return ;
}

//using preorderTraversal it is just able to print the linked list but not a proper method
// Node* convertToLL(Node* root){
//     if(root->left==NULL and root->right==NULL){ // reached leaf node
//         cout<<root->key<<"->";
//         return root;
//     }
//     if(root->left){
//         Node* n1=convertToLL(root->left);
//         n1->right=root;
//         root->left=NULL;
        
//     }
    
    
//     cout<<root->key<<"->";
    
//     if(root->right){
//         Node* n2=convertToLL(root->right);
//         return n2;
//     }
    
//     return root;
    
   
//     }






class LinkedList{
    public:
        Node* head;
        Node* tail;
    };

LinkedList tree2LL(Node* root){
    LinkedList l;
    if(root==NULL){
        l.head=l.tail=NULL;
        return l;
    }
    
    //4cases
    
    //if leaf node then head and tail will be the root
    if(root->left==NULL and root->right==NULL){
        l.head=l.tail=root;
    }
    
    
    //if right node is NULL
    else if(root->left!=NULL and root->right==NULL){
        LinkedList leftLL= tree2LL(root->left);
        leftLL.tail->right=root;
        l.head=leftLL.head;
        l.tail=root;
        
    }
    
    //if left node is NULL
    else if(root->left==NULL and root->right!=NULL){
        LinkedList rightLL= tree2LL(root->right);
        root->right=rightLL.head;
        l.head=root;
        l.tail=rightLL.tail;
        
    }
    
    
    //if left and right are NULL;
    else{
        LinkedList leftLL= tree2LL(root->left);
        LinkedList rightLL= tree2LL(root->right);
        leftLL.tail->right=root;
        root->right=rightLL.head;
        l.head=leftLL.head;
        l.tail=rightLL.tail;
    }
    
    return l;
    
    
    
}




    
    
    
    int main(){
    Node* root=NULL;
    int arr[]={5,1,2,3,7,6};
    for(int x:arr){
        root=insert(root,x);
    }
    // printInOrderTraversal(root);
    // cout<<endl;

    // Node* tail=convertToLL(root);
    
    
   
    LinkedList l=tree2LL(root);
    Node * temp = l.head;
    
    while(temp!=NULL){
        cout<<temp->key<<"->";
        temp=temp->right;
    }
    
    cout<<"NULL"<<endl;
    // cout<<tail->key<<endl;

    
}