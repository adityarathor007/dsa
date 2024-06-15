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

void insertInMiddle(node* &head,int data,int pos){
    if(pos==0){ //we have to update the header
        head=new node(data);
        return;
    }
    node* n = new node(data);
    node* current=head;
    int i=1;
    while(i!=pos){
        current=current->next;
        i++;
    }
    n->next=current->next;
    current->next=n;
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
    insertInMiddle(head, 122, 6);
    
    
    
    //printing the LL
    printLL(head);
    
    
}