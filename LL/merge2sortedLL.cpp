#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node * next;
        
        node(int d){
            data=d;
            next=NULL;
        }
};

void insertAtTail(node* &head,int data){
    if(head==NULL){
        head=new node(data);
        return ;
    }
        
        node* tail=head;  //new variable tail which will mark the end of the linkedlist
        while(tail->next!=NULL){ //stopping before crossing the last node 
            tail=tail->next;
        }
        
        node* n=new node(data);
        tail->next=n;
        
        
 
        return ;
}

void printLL(node* head){
    while(head != NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
    return ;
}

node* merge(node*a ,node*b){
    if(a==NULL){ //if a reached the null then return the head of the remaining array
        return b; 
    }
    
    else if(b==NULL){
        return a;
    }
    
    node* c;
    
    if(a->data<b->data){
        c=a;
        c->next=merge(a->next,b);
        
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    
    
    return c;
}




int main(){
    node* a=NULL;
    insertAtTail(a,1);
    insertAtTail(a,5);
    insertAtTail(a,7);
    insertAtTail(a,10);
    node* b=NULL;
    insertAtTail(b,2);
    insertAtTail(b,3);
    insertAtTail(b,6);
    printLL(a);
    printLL(b);
    
    node* c=merge(a,b);
    printLL(c);

}