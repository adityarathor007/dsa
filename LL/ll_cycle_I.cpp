#include<iostream>
#include <sys/wait.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

void insertAtTail(node * &head,int data){
    if(head==NULL){
        head=new node(data);
        return ;
    }
    node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    node * n= new node(data);
    tail->next=n;
    return;
    
}

void printLL(node * head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}



bool containsCycle(node *head){
    //Complete this function 
    node* fast=head;
    node* slow=head;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
        
        
    }
    return false;
    
    
}

void joinWith2Nodes(node* head,int i){
    node* a=head;
    node* tail=head;
    int k=0;
    while(k<i){
        k+=1;
        a=a->next;
    }
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=a;
}



int main(){
    node* head=NULL;
    insertAtTail(head,5);
    insertAtTail(head,2);
    insertAtTail(head,7);
    insertAtTail(head,10);
    insertAtTail(head,3);
    joinWith2Nodes(head, 1); 
    
    
    if(containsCycle(head)){
        cout<<"Contains cycle"<<endl;
    }
    else{
        cout<<"Does not contain cycle"<<endl;
    }
    
    printLL(head);
    
    return 0;
}