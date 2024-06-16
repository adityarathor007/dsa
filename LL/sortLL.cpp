#include<iostream>
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
    return;
}

node* midPoint(node* head){
    node* f=head;
    node* s=head;
    while(f->next!=NULL and f->next->next!=NULL){
        f=f->next->next;
        s=s->next;
        
    }
    return s;
}

node* merge(node * a,node *b){
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    
    node* c;
    if(a->data < b->data){
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
    
    
}






//ToDo: mergeSort
node* mergeSort(node* head){
    //base case
    if(head==NULL or head->next==NULL ){
        return head;
    }
    
    //rec case
    node* mid=midPoint(head);
    
    node*a = head;
    node*b = mid->next;
    mid->next=NULL;
    
    //recursiveSorting
    a=mergeSort(a);
    b=mergeSort(b);
    
    return merge(a,b);
}



int main(){
    node* head=NULL;
    insertAtTail(head,5);
    insertAtTail(head,2);
    insertAtTail(head,7);
    insertAtTail(head,10);
    insertAtTail(head,3);
    printLL(head);
    node* head_sort=mergeSort(head);
    printLL(head_sort);
}