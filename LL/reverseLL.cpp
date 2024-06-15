#include <iostream>
using namespace std;



class node{
    public:
        int data;
        node* next;
        
        node(int d){ //constructor function
            data=d;  
            next=NULL;
        }
};

void insertAtHead(node* &head,int data){
    if(head==NULL){ //if LL is empty
        head=new node(data);
        return;
    }

        node* n = new node(data);
        n->next=head; //pointing the new node where head was pointing
        head=n; //making this node as the head

    return;
};


node* recReverseLL(node* head){
    //base case
    if(head->next==NULL or head==NULL){  //head null if null head is passed
        return head;
    }
    
    //otherwise
    node* sHead=recReverseLL(head->next); //ex 3->4 and when head is 3 then head next is 4 then shead is 4 and 
    head->next->next=head; //reverse the arrows 4->next=3 and 3->next=NULL
    head->next=NULL;
    return sHead;
}


void iterReverseLL(node* & head){
    node*current=head;
    node*prev=NULL;
    node *temp;
    while(current!=NULL){
        //store next
        temp=current->next;
        //update the current
        current->next=prev; 
        
        prev=current;
        current=temp;
    }
    head=prev;
    return;
}


node* kReverse(node* head,int k){
    if(head==NULL){
        return NULL;
    }
    // reverse the first k nodes
    node* prev=NULL;
    node* current=head;
    node* temp;
    int cnt=1;
    
    while(current!=NULL and cnt<=k){
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
        cnt++;
    }
    
    if(temp!=NULL){  //ie not the last node
        head->next=kReverse(temp, k);
    }
    return prev;
}




void printLL(node* head){  //passing the head as a copy as passed by value so wont change the actual head
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}



int main(){
    node* head=NULL;
    insertAtHead(head, 10);
    insertAtHead(head,20);
    insertAtHead(head,5);
    insertAtHead(head,0);
    insertAtHead(head,30);
    insertAtHead(head,40);
    printLL(head);
    
    head=recReverseLL(head);
    
    printLL(head);
    
    iterReverseLL(head);
    
    printLL(head);
    
    head=kReverse(head, 3);
    
    printLL(head);
}