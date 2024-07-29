#include <iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};

Node* helper(vector<int>&nums,int s,int e){
        cout<<"fn start"<<endl;
        // cout<<"s value"<<s<<" and "<<"e value"<<e<<endl;
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        Node* n=new Node(nums[mid]);
       
        
        if(s<=mid-1){
            n->left=helper(nums,s,mid-1);
        }
    
        if(e>=mid+1){
            n->right=helper(nums,mid+1,e);
        }
        
        return n;
    }
  
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        return helper(nums,0,nums.size()-1);
    }


    
    int main() {
    vector<int>arr{1,2,3,4,5,6,7};
    Node* root=sortedArrayToBST(arr);
    cout<<root->left->left->data<<endl;
        return 0;
    }