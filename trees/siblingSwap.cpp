#include <cmath>
#include<iostream>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};




bool equal(Node * root1, Node * root2){
    //Complete the Function
    
    
    if(root1->key!=root2->key){
        return false;
    }
    
    cout<<"the value of root1: "<<root1->key<<endl;
    cout<<"the value of root2: "<<root2->key<<endl;
    
   
    if(!root1->left and !root2->left and !root1->right and !root2->right ){  //if all reached the leaf node
            return true;
        }
            
        if(root1->left and root2->left and root1->right and root2->right){
                if( root1->left->key==root2->left->key && root1->right->key==root2->right->key ){
                   bool a1=equal(root1->left,root2->left);
                   bool a2=equal(root1->right,root2->right);
                   
                   if(a1 && a2){
                       
                       return true;
                       
                   }
                   else{
                       return false;
                   }
                   
                   
                }
                
                
                else if(root1->left->key==root2->right->key && root1->right->key==root2->left->key){
                    cout<<"swap needed"<<endl;
                    bool a1=equal(root1->left,root2->right);
                    bool a2=equal(root1->right,root2->left);
                    if(a1 && a2){
                        
                        return true;
                        
                    }
                    else{
                        
                        return false;
                        
                    }
                }
                
                
                else{
                    return false;
                }
            }
        
            //what if one node of each left
        else if(root1->left and root2->left){
            if( root1->left->key==root2->left->key ){
                   bool a1=equal(root1->left,root2->left);
                   if(a1){
                       return true;
                   }
                   return false;
            }
        }
        
        else if(root1->right and root2->right){
            if(root1->right->key==root2->right->key){
                bool a1=equal(root1->right,root2->right);
                if(a1){
                    return true;
                }
                return false;
            }
        }
        
        else if(root1->left and root2->right){
            if(root1->left->key==root2->right->key){
                bool a1=equal(root1->left,root2->right);
                if(a1){
                    return true;
                }
                return false;
            }
        }
        else if(root1->right and root2->left){
            if(root1->right->key==root2->left->key){
                bool a1=equal(root1->right,root2->left); //traverse in right and left subtree
                if(a1){
                    return true;
                }
                return false;
            }
        }
            
            
        return false;
   
        
    
}
        
    
    
    


int main(){
    Node* root1=new Node(6);
    root1->left=new Node(2);
    root1->right=new Node(4);
    // root1->left->left=new Node(1);
    // root1->left->right=new Node(7);
    // root1->right->left=new Node(4);
    // root1->right->right=new Node(2);
    // root1->right->left->left=new Node(7);
    // root1->right->left->right=new Node(1);
    // root1->right->right->right=new Node(3);

    Node* root2=new Node(6);
    root2->right=new Node(2);
    root2->left=new Node(4);
    root2->right->right=new Node(1);
    // root2->right->left=new Node(7);
    // root2->left->left=new Node(4);
    // root2->left->right=new Node(2);
    // root2->left->left->right=new Node(7);
    // root2->left->left->left=new Node(1);
    // root2->left->left->left=new Node(3);
    
    if(equal(root1,root2)){
        cout<<"yes you can convert "<<endl;
    }
    else{
        cout<<"no you cant convert"<<endl;
    }
}