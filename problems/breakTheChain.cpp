#include<iostream>
#include <unordered_set>
using namespace std;

class node{
public:  
  int data;
  node * next;
  
  node(int data){
      this->data = data;
  }
};


 node * breakChain(node * head){
     //Complete this method
    node* curr=head;
    unordered_set<node*>m;
    while(m.find(curr->next)==m.end()){
        m.insert(curr);
        curr=curr->next;
    }
    curr->next=NULL;
    return head;

 }
 
 
 bool checkCycle(node* head){
    node* s=head;
    node* f=head;
   
    while(f!=NULL and f->next!=NULL){
        
        s=s->next;
        f=f->next->next;
        if(s==f){
            return true;
        }
        
    }
    return false;
 }
 
 int main(){
    node* head=new node(1);
    head->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    head->next->next->next->next=head->next;
    
    bool c1=checkCycle(head);
    if(c1){
        cout<<"contains cycle"<<endl;
    }
    else{
        cout<<"does not contain cycle"<<endl;
    }
    
    node* nhead=breakChain(head);
    bool c=checkCycle(nhead);
    
    
    if(c){
        cout<<"contains cycle"<<endl;
    }
    else{
        cout<<"does not contain cycle"<<endl;
    }
     
 }


