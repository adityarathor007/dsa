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

int getMid(node *head){
    //Complete this function to return data middle node
    node* f=head;
    node* s=head;
    while( f->next!=NULL and f->next->next!=NULL){
        cout<<"the value of f pointed node: "<<f->data<<endl;
        cout<<"the value of s pointed node: "<<s->data<<endl;
        f=f->next->next;
        s=s->next;
        cout<<"the updated value of f pointed node: "<<f->data<<endl;
        cout<<"the updated value of s pointed node: "<<s->data<<endl;
    }
    return s->data;
    
    
    
    
}


int kthLastElement(node *head, int k){
    //Complete this function to return kth last element
    int n=1;
    node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
        n+=1;
    }
    int target=n-k+1;
    int i=1;
    while(i<target){
        head=head->next;
        i++;
    }
    return head->data;
    
    
    
    
}


void insertAtTail(node* &head,int data){
    if(head==NULL){
        head=new node(data);
        return;
    }
    node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    node * n=new node(data);
    tail->next=n;
    return;
}

void printLL(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}



int main(){
    node* head=NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    printLL(head);
    // cout<<getMid(head)<<endl;
    cout<<kthLastElement(head, 3)<<endl;

}