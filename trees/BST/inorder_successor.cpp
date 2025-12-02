#include <cstddef>
#include <iostream>
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


Node* insert(Node* root,int k){
    if(root==NULL){
        return new Node(k);
    }


        if(k<root->key){
            root->left=insert(root->left,k);
        }
        else{
            root->right=insert(root->right,k);
        }
        return root;
    }


void findInOrderSuccessor(Node* root,int k,Node*& ans){
    if(root==NULL){
        return ;
    }



    if(root->key>k){
        ans=root;  //update succ as found a greater value than k so can be a possible successor
        findInOrderSuccessor(root->left, k,ans);
    }
    else if(root->key<k){

        findInOrderSuccessor(root->right, k,ans);
    }
    else{
        findInOrderSuccessor(root->right, k,ans); //as from the target the succ will be in the rightsubtree
    }

    return;

}

void printInOrderTraversal(Node* root){
    if(root==NULL){
        return ;
    }

    printInOrderTraversal(root->left);


    cout<<root->key<<",";

    printInOrderTraversal(root->right);


    return ;
}






int main(){
    int arr[]={8,3,10,1,6,14,4,7,13};
    Node* root=NULL;

    for(int x:arr){
         root=insert(root,x);
    }
    // printInOrderTraversal(root);

    Node* ans=NULL;
    findInOrderSuccessor(root,1,ans);

    if(ans!=NULL){
        cout<<ans->key<<endl;
    }
    else{
        cout<<"None found"<<endl;
    }


}
